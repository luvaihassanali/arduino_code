var $ = global.jQuery = require('./jquery-3.4.1.min')
var wDown = false;
var aDown = false;
var sDown = false;
var dDown = false;

$(document).ready(function () {
    "use strict";
    $.ajaxSetup({ timeout: 1000 });
    var baseLogFunction = console.log;
    console.log = function () {
        baseLogFunction.apply(console, arguments);
        var args = Array.prototype.slice.call(arguments);
        for (var i = 0; i < args.length; i++) {
            var node = createLogNode(args[i]);
            document.querySelector("#mylog").appendChild(node);
        }

    }
    window.onerror = function (message, url, linenumber) {
        console.log("Error: " + message + " on line " +
            linenumber + " for " + url);
    };

    console.log("Ready");
});

function greenLight() {
    console.log("Green light turned on");
    $.get("http://192.168.0.196:80", { "sr1": 6 });
    { Connection: close };
}

function redLight() {
    console.log("Red light turned on");
    $.get("http://192.168.0.196:80", { "sr1": 7 });
    { Connection: close };
}

function blueLight() {
    console.log("Blue light turned on");
    $.get("http://192.168.0.196:80", { "sr1": 5 });
    { Connection: close };
}

function offLight() {
    console.log("Light turned off");
    $.get("http://192.168.0.196:80", { "sr1": 8 });
    { Connection: close };
}

function goForward() {
    if (!wDown) {
        console.log("forward");
        $.get("http://192.168.0.196:80", { "sr1": 1 });
        { Connection: close };
        wDown = true;
    }
}

function goBackward() {
    if (!sDown) {
        console.log("backward");
        $.get("http://192.168.0.196:80", { "sr1": 2 });
        { Connection: close };
        sDown = true;
    }
}

function goLeft() {
    if (!aDown) {
        console.log("left");
        $.get("http://192.168.0.196:80", { "sr1": 3 });
        { Connection: close };
        aDown = true;
    }
}

function goRight() {
    if (!dDown) {
        console.log("right");
        $.get("http://192.168.0.196:80", { "sr1": 4 });
        { Connection: close };
        dDown = true;
    }
}

function stop() {
    console.log("stop");
    $.get("http://192.168.0.196:80", { "sr1": 0 });
    { Connection: close };
    wDown = false;
    aDown = false;
    sDown = false;
    dDown = false;
}

function createLogNode(message) {
    var node = document.createElement("div");
    var textNode = document.createTextNode('> ' + message);
    node.appendChild(textNode);
    var objDiv = document.getElementById("mylog");
    objDiv.scrollTop = objDiv.scrollHeight;
    return node;
}

$(document).keyup(function (e) {
    if (e.key == 'w') {
        if (wDown == true) { stop(); }
        $("#buttonW").css("backgroundColor", "");
    }
    if (e.key == 'a') {
        if (aDown == true) { stop(); }
        $("#buttonA").css("backgroundColor", "");
    }
    if (e.key == 's') {
        if (sDown == true) { stop(); }
        $("#buttonS").css("backgroundColor", "");
    }
    if (e.key == 'd') {
        if (dDown == true) { stop(); }
        $("#buttonD").css("backgroundColor", "");
    }
});

$(document).keydown(function (e) {
    if (e.key == 'w' && !aDown && !sDown && !dDown) {
        goForward();
        $("#buttonW").css("backgroundColor", "#ff3fff");
    }
    if (e.key == 'a' && !wDown && !sDown && !dDown) {
        goLeft();
        $("#buttonA").css("backgroundColor", "#ff3fff");
    }
    if (e.key == 's' && !wDown && !aDown && !dDown) {
        goBackward();
        $("#buttonS").css("backgroundColor", "#ff3fff");
    }
    if (e.key == 'd' && !wDown && !sDown && !aDown) {
        goRight();
        $("#buttonD").css("backgroundColor", "#ff3fff");
    }
});