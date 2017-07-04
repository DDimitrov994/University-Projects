var xpath;
var recData = "";
var rowName;
var constr="";
var countcell=0;

// Inject the payload.js script into the current tab after the popout has loaded
window.addEventListener('load', function (evt) {
    chrome.extension.getBackgroundPage().chrome.tabs.executeScript(null, {
        file: 'payload.js'
    });
    console.log("payload sent to webpage");
});
$(document).on('click', '#submit', function () {
    xpath = document.getElementById('xpath').value;
    console.log("clicked button");
    chrome.tabs.query({active: true, currentWindow: true}, function (tabs) {
        if (tabs.length == 0) {
            console.log("could not send mesage to current tab");
        } else {
            chrome.tabs.sendMessage(tabs[0].id, {xpath: xpath}, function (response) {
            });
        }
    });
});

$(document).on('click', '#addrow', function () {
    if ($('#row').val()) {
        countcell=0;
        rowName = $('#row').val();
        $('#mtable>tbody:last').append($("<tr id='" + rowName + "'>"));
        document.getElementById(rowName).innerHTML = rowName;
    } else {
        alert('Enter Name of row!');
    }
});
function addrow(crawledData) {
    var html = "<td class='" + countcell+"'>" + crawledData + "</td>";
    countcell++;
    $("#" + rowName + ":last-child").append(html);
    console.log(crawledData);
}

// Listen to messages from the payload.js script and write to popout.html
chrome.runtime.onMessage.addListener(function (response) {
    recData = response.data;
    recData = recData.toString();
    if (recData.includes("<")) {
        var idx = recData.indexOf("<");
        recData = recData.substring(0, idx);
    }
    console.log("received data from payload and attemting to print");
    addrow(recData);
});