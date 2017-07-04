// send the page title as a chrome message
var xpath;
var list = [];
chrome.runtime.onMessage.addListener(
        function (request, sender, sendResponse) {
            xpath = request.xpath;
            var xpathRes = document.evaluate(xpath, document, null, XPathResult.ANY_TYPE, null);
            if (xpathRes.resultType == 1)
                chrome.runtime.sendMessage({data: xpathRes.numberValue});
            else {
                var actualRes = xpathRes.iterateNext();
                while (actualRes) {
                    list.push(actualRes);
                    chrome.runtime.sendMessage({data: actualRes.innerHTML});
                    actualRes = xpathRes.iterateNext();
                }
                if (!xpath.includes("text()"))
                    for (var i = 0; i < list.length; i++) {
                        list[i].classList.add("xh-highlight");
                    }
            }
        });