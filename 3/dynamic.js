"use strict";
function dynamicSearch(g, a, b, visited = []) {
    let min = Infinity;
    let path = [];
    for (let i = 0; i < g.length; ++i) {
        if (g[a][i] != -1 && !visited.includes(i)) {
            let search = dynamicSearch(g, i, b, [...visited, i]);
            if (search.score + g[a][i] < min) {
                min = g[a][i] + search.score;
                path = [a, ...search.path];
            }
        }
    }
    if (g[a][b] != -1 && g[a][b] <= min) {
        return {
            score: g[a][b],
            path: [a, b],
        };
    }
    else {
        return {
            score: min,
            path,
        };
    }
}
const g = [];
for (let i = 0; i < 7; ++i) {
    g[i] = [];
    for (let j = 0; j < 7; ++j) {
        g[i][j] = -1;
    }
}
g[0][1] = 1;
g[0][3] = 8;
g[0][4] = 25;
g[0][6] = 20;
g[3][4] = 9;
g[4][6] = 6;
g[1][2] = 2;
g[1][6] = 15;
g[2][5] = 3;
g[5][6] = 4;
console.log(dynamicSearch(g, 0, 6));
