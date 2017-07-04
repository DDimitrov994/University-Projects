// All these function render piece of HTML to plug into the DOM tree.
// The HTML can be plugged using $('#id').html(new_html);

function render_students(students) {
	var html = "<tr>"+
			"<th>ID</th>"+
			"<th>FAKNO</th>"+
			"<th>NAME</th>"+
			"<th>ADDRESS</th>"+
			"<th></th>"+
		"</tr>";

	for(var i=0; i<students.length; i++) {
		var s = students[i];
		html += "<tr>" +
			"<td>" + s.ID + "</td>" +
			"<td>" + s.FAKNO + "</td>" +
			"<td><a href='#' data-student-id='" + s.ID + "' class='user_icon student-notes'>" +
				html_escape(s.NAME + " " + s.FAM) +
			"</a></td>"+
			"<td>" + html_escape(s.ADDRESS) + "</td>" +
			"<td>" +
				"<a href='#' data-student-id='" + s.ID + "' class='edit_icon student-edit'>Edit</a> " +
				"<a href='#' data-student-id='" + s.ID + "' class='delete_icon student-delete'>Delete</a>" +
			"</td>" +
		"</tr>";
	}

	html = "<table class='grid'>"+html+"</table>";
	return html;
}
function render_students_bySB(students_bySB){
		var html = "<tr>"+
			"<th>ID</th>"+
			"<th>FAKNO</th>"+
			"<th>NAME</th>"+
			"<th>ADDRESS</th>"+
			"<th></th>"+
		"</tr>";
			for(var i=0; i<students_bySB.length; i++) {
		var s = students_bySB[i];
		html += "<tr>" +
			"<td>" + s.ID + "</td>" +
			"<td>" + s.FAKNO + "</td>" +
			"<td>" +
			s.NAME + " " + s.FAM +
			"</td>"+
			"<td>" + html_escape(s.ADDRESS) + "</td>" +
		"</tr>";
	}

	html = "<table class='grid'>"+html+"</table>";
	return html;
}

function render_student_form(student) {
	if(!student) return 'Empty student.';
	
	var html = '';
	var title = (student.ID) ? 'Edit Person' : 'Add Person';
	
	html += "<h1>" + title + "</h1>";
	html += "<form action='#' method='post'>";
	html += "<p><label>ID</label><input name='id' value='" + html_escape(student.ID) + "' readonly='readonly' /></p>";
	html += "<p><label>Faculty Number</label><input name='FAKNO' value='" + html_escape(student.FAKNO) + "'/></p>";
	html += "<p><label>First Name</label><input name='NAME' value='" + html_escape(student.NAME) + "'/></p>";
	html += "<p><label>Last Name</label><input name='FAM' value='" + html_escape(student.FAM) + "'/></p>";
	html += "<p><label>Address</label><input name='ADDRESS' value='" + html_escape(student.ADDRESS) + "'/></p>";
	html += "<p><button>Save</button></p>";
	html += "</form>";
	
	return html;
}

// notes
function render_notes(student, notes) {	
	var html = '';
	
	html += "<p class='user_icon'>"+
			"<b>" + html_escape(student.FAKNO+" "+student.NAME + " " + student.FAM) + "</b>, "+ 
			html_escape(student.ADDRESS) + 
		"</p>";
	
	html += "<table class='grid'>";
	html += "<tr>"+
		"<th>ID</td>"+
		"<th>STID</th>"+
		"<th>NOTE</th>"+
		"<th>SUBJECT</th>"+
		"<th></th>"+
	"</tr>";
	for(var i=0; i<notes.length; i++) {
		var note = notes[i];
		html += "<tr>"+
			"<td>" + note.ID + "</td>" +
			"<td>" + html_escape(note.STID) + "</td>" +
//			"<td>" + html_escape(note.NAME) + "</td>" +
			"<td>" + html_escape(note.NOTE) + "</td>" +
			"<td><a href='#' data-subject-id='" + note.SBID + "' class='user_icon student_bySB-notes'>" +
				html_escape(note.NAME) +
		"</tr>";
	}
	html += "</table>";
	return html;
}

function render_messages(messages) {
	var html = '';
	if(messages) {	
		for(var i = 0; i < messages.length; i++) {
			var m = messages[i];
			var css = (m.type === 'error') ? 'error_icon' : 'info_icon';
			html += "<p class='" + css + "'>" + m.text + "</p>";
		}
	}
	return html;
}

function html_escape(val) {
	return (val+'')
      .replace(/&/g, '&amp;')
      .replace(/</g, '&lt;')
      .replace(/>/g, '&gt;')
      .replace(/\"/g, '&quot;')
      .replace(/\'/g, '&apos;');
}

