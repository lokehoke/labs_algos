"use strict";

function getAn(n: number): number {
  if (n <= 0) {
    return 3;
  } else {
    return (getAn(n - 1) * 3) / n;
  }
}

const n = 20;
const arr: Array<number> = [];
for (let i: number = 0; i < n; ++i) {
  arr.push(getAn(i));
}

console.log(arr.map((el, i) => `${i} : ${el}`));
