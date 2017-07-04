function reload_students() {
	$.get('students').done(function(data) {
		$('#students').html(render_students(data.students));
		$('#students-messages').html(render_messages(data.messages));
	}).fail(function(response) {
		var data = response.responseJSON;
		$('#students-messages').html(render_messages(data.messages));
	});
}

function reload_students_bySB(subject_id){
	$.get('students/' + subject_id+'/sort').done(function(data){
		$('#students_bySB').html(render_students_bySB(data.students_bySB));
	}).fail(function(response){
		var data=response.responseJSON;
		$('#notes-messages').html(render_messages(data.messages));
	});
}

function reload_notes(student_id) {
	$.get('students/' + student_id + '/notes').done(function(data) {
		$('#notes').html(render_notes(data.student, data.notes));
		$('#notes-messages').html(render_messages(data.messages));
	}).fail(function(response) {
		var data = response.responseJSON;
		$('#notes-messages').html(render_messages(data.messages));
	});
}

function reload_teltypes() {
	$.get('teltypes').done(function(data) {
		TELTYPES = data.teltypes;
	}).fail(function(response) {
		var data = response.responseJSON;
		$('#persons-messages').html(render_messages(data.messages));
	});
}

$(document).ready(function() {
	
	reload_students();

	$(document).on('click', 'a.students-refresh', function() {
		reload_students();
		return false; // disables default browser behavior when a hyper-link is clicked.
	});

	$(document).on('click', 'a.student-add', function() {
		var new_student = { ID: '',FAKNO: '', NAME: '', FAM: '',	ADDRESS: '' };
		$('#student-edit').html(render_student_form(new_student));
		$('#student-messages').html('');
		return false;
	});

	$(document).on('click', 'a.student-edit', function() {
		var student_id = $(this).attr('data-student-id');
		$.get('students/'+student_id).done(function(data) {
			$('#student-edit').html(render_student_form(data.student));	
			$('#student-messages').html(render_messages(data.messages));
		}).fail(function(response) {
			var data = response.responseJSON;
			$('#student-messages').html(render_messages(data.messages));
		});
		return false;
	});

	$(document).on('submit', '#student-edit > form', function() {
		var edited_student = $(this).serializeObject();
		$.postJSON('students/' + edited_student.id, edited_student).done(function(data) {
			$('#student-edit').html('');
			$('#student-messages').html(render_messages(data.messages));
			reload_students();
		}).fail(function(response) {
			var data = response.responseJSON;
			$('#student-messages').html(render_messages(data.messages));
		});
		return false;
	});

	$(document).on('click', 'a.student-delete', function() {
		var student_id = $(this).attr('data-student-id');
		$.delete('students/' + student_id).done(function(data) {
			reload_students();
			$('#student-messages').html(render_messages(data.messages));
		}).fail(function(response) {
			var data = response.responseJSON;
			$('#student-messages').html(render_messages(data.messages));
		});
		return false;
	});


	// notes
	$(document).on('click', 'a.student-notes, a.notes-refresh', function() {
		var student_id = $(this).attr('data-student-id');
		reload_notes(student_id);
		$('#note-edit').html('');
		$('#note-messages').html('');
		return false;
	});
	
	$(document).on('click', 'a.student_bySB-notes', function() {
		var subject_id = $(this).attr('data-subject-id');
		reload_students_bySB(subject_id);
		$('#note-edit').html('');
		$('#note-messages').html('');
		return false;
	});
});
