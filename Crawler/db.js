var db = openDatabase('DCrawlerDB', '1.0', 'Captured information', 50 * 1024 * 1024);
var msg;
var listsql = [];
var numberOfRows;
var cols = "";
var els = "";
var count = 0;
$(document).on('click', '#commitToDB', function () {
    console.log("entering db func");
    var nodelist = document.querySelectorAll('tr[id]');
    var list = nodelist;
    //creating table
    var sql = "CREATE TABLE IF NOT EXISTS " +
            document.getElementById("nameOfTable").value +
            " (id INTEGER PRIMARY KEY";
    for (var i = 0; i < list.length; i++) {
        console.log(list[i].firstChild.data);
        sql += ", " + list[i].firstChild.data;
    }
    sql += ")";
    listsql.push(sql);
    console.log(sql);
    //creating entries in the table
    var $rowNames = document.querySelectorAll('tr[id]');
    for (var p = 0; p < $("#mtable tr:nth-child(2) td").length; p++) {
        sql = "INSERT INTO " +
                document.getElementById("nameOfTable").value +
                "(";
        var i;
        if ($rowNames.length != 1) {
            for (i = 0; i < $rowNames.length - 1; i++) {
                cols += $rowNames[i].firstChild.data + ", ";
            }
            cols += $rowNames[$rowNames.length - 1].firstChild.data;
        } else
            cols += $rowNames[0].firstChild.data;
        sql += cols + ") VALUES (";
        cols = "";
        var str = "";
        var elem = document.getElementsByClassName(p);
        var arr = [].slice.call(elem);
        var genres = arr.map(function (el) {
            return el.firstChild.data;
        });
        for (var k = 0; k < genres.length - 1; k++)
            str += '"' + genres[k] + '", ';
        str += '"' + genres[genres.length - 1] + '"';
        sql += str + ")";
        listsql.push(sql);
    }
    db.transaction(function (tx) {
        for (var o = 0; o < listsql.length; o++)
            tx.executeSql(listsql[o]);
    });

});

$(document).on('click', '#addstatement', function () {
    var usersql = document.getElementById("dbstatement").value;
    if (!usersql.includes("SELECT")) {
        db.transaction(function (tx) {
            tx.executeSql(usersql);
            document.getElementById("status").innerHTML = "Transaction successfull: " + usersql;
        });
    } else {
        db.transaction(function (tx) {
            tx.executeSql(usersql, [], function (tx, results) {
                var len = results.rows.length, i;
                var res="";
                for (i = 0; i < len; i++) {
                    res+=JSON.stringify(results.rows.item(i))+ "\n";
                }
                document.getElementById("result").innerHTML=res;
            });
        });
    }
});