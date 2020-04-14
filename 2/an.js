"use strict";
function getAn(n) {
    if (n <= 0) {
        return 3;
    }
    else {
        return (getAn(n - 1) * 3) / n;
    }
}
var n = 20;
var arr = [];
for (var i = 0; i < n; ++i) {
    arr.push(getAn(i));
}
console.log(arr.map(function (el, i) { return i + " : " + el; }));
