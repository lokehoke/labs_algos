"use strict";
function findCoverage(U, C) {
    if (C.length == 0) {
        return null;
    }
    U = [...U];
    let globalPower = 0;
    let m = U.length;
    let coverage = [];
    while (m != 0) {
        let max = 0;
        let power = Infinity;
        let t = C[0];
        for (let el of C) {
            let score = 0;
            for (let val of U) {
                if (el.val.includes(val)) {
                    score++;
                }
            }
            if (score > max || (score == max && el.power < power)) {
                max = score;
                t = el;
                power = el.power;
            }
        }
        globalPower += power;
        coverage.push(t.id);
        U = U.filter((val) => {
            return !t.val.includes(val);
        });
        m = U.length;
    }
    return {
        id: 0,
        power: globalPower,
        val: coverage,
    };
}
const M = 15;
const U = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15];
const C = [
    {
        power: 1,
        val: [1, 2, 3, 4, 6, 8],
        id: 1,
    },
    {
        power: 5,
        val: [5, 10, 11, 12, 13, 14],
        id: 2,
    },
    {
        power: 3,
        val: [4, 7, 9, 12, 13, 15],
        id: 3,
    },
    {
        power: 2,
        val: [1, 2, 8, 10, 11, 12],
        id: 4,
    },
    {
        power: 6,
        val: [5, 7, 8, 10, 14, 15],
        id: 5,
    },
    {
        power: 8,
        val: [1, 3, 8, 10, 11, 15],
        id: 6,
    },
    {
        power: 2,
        val: [4, 5, 7, 9, 14, 15],
        id: 7,
    },
];
console.log(findCoverage(U, C));
