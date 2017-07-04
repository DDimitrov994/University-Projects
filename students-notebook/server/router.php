<?php

// Route URL paths
if($request->get('students')) {
	$response->students = $db->querybind_all('SELECT * FROM students_tbl ORDER BY ID');
}
else if($request->get('students/[0-9]+')) {
	$student_id = (int) $request->segment(1);
	$response->student = $db->querybind_one('SELECT * FROM students_tbl WHERE ID = ?', [ $student_id ]);
	if(!$response->student) {
		$response->code(404);
		$response->error('404: Student Not Found.');
	}
}
else if($request->post('students/[0-9]+') || $request->post('students')) {
	$student_id = (int) $request->segment(1, 0);
	$student = $request->data;
	if($student) {	
		if(strlen($student->FAKNO) < 6) $response->error('Faculty Number is invalid.');
		if(strlen($student->NAME) < 1) $response->error('First Name is empty.');
		if(strlen($student->FAM) < 1) $response->error('Last Name is empty.');
		if(strlen($student->ADDRESS) < 3) $response->error('Address is shorter then 3 characters.');
	}
	else {
		$response->error('No JSON data sent.');
	}
	
	if($response->hasErrors()) {
		$response->code(400);
		$response->error('400: Invalid input.');
	}
	else {
		if($student_id > 0) { // update existing
			$result = $db->querybind(
				'UPDATE students_tbl SET FAKNO=?, NAME=?, FAM=?, ADDRESS=? WHERE ID=?', 
				[$student->FAKNO, $student->NAME, $student->FAM, $student->ADDRESS, $student_id]
			);
		} else { // insert new
			$result = $db->querybind(
				'INSERT INTO students_tbl SET FAKNO=?, NAME=?, FAM=?, ADDRESS=?', 
				[$student->FAKNO, $student->NAME, $student->FAM, $student->ADDRESS]
			);
			$student_id = $db->insert_id;
		}
		
		$response->student = $db->querybind_one('SELECT * FROM students_tbl WHERE ID = ?', [$student_id]);
		$response->info('Student saved.');	
	}
}
else if($request->delete('students/[0-9]+')) {
	$student_id = (int) $request->segment(1);
	$db->querybind('DELETE FROM notes_tbl WHERE STID = ?', [$student_id] );
	$db->querybind('DELETE FROM students_tbl WHERE ID = ?', [$student_id] );
	$response->info("Student id=$student_id and its notes deleted.");
}
else if($request->get('students/[0-9]+/notes')) {
	$student_id = (int) $request->segment(1);
	$response->student = $db->querybind_one('SELECT * FROM students_tbl WHERE ID = ?', [$student_id] );
	$response->notes = [];
	if($response->student) {
		$response->notes = $db->querybind_all('SELECT n.*,s.* FROM notes_tbl n, subjects_tbl s WHERE STID = ? AND n.SBID=s.ID', [$student_id] );
	}
	else {
		$response->code(404);
		$response->error("404: Student id=$student_id not found.");
	}
}
else if($request->get('students/[0-9]+/sort')) {
	$subject_id = (int) $request->segment(1);
	$response->students_bySB = $db->querybind_all('SELECT stu.* FROM notes_tbl n, students_tbl stu WHERE stu.ID=n.STID AND n.SBID=?', [$subject_id] );
	}
else if($request->get('notes/[0-9]+')) {
	$note_id = (int) $request->segment(1);
	$response->note = $db->querybind_one('SELECT * FROM notes_tbl WHERE ID = ?', [ $note_id ]);
	if(!$response->note) {
		$response->code(404);
		$response->error('404: Note Not Found.');
	}
}
else {
	$response->error('404: URL Not Found: /'.$request->path);
	$response->code(404);
}

// Outputs $response object as JSON to the client.
echo $response->render();