"use strict";

class Board {
  m_place: Array<Array<number>> = [];
  m_w: number;

  constructor(w: number) {
    this.m_w = w;
    for (let i = 0; i < w + 2; ++i) {
      this.m_place[i] = [];
    }

    for (let i = 0; i < w + 2; ++i) {
      // wall in border
      this.m_place[i][0] = -1;
      this.m_place[0][i] = -1;
      this.m_place[i][w + 1] = -1;
      this.m_place[w + 1][i] = -1;
    }

    for (let i = 1; i < w + 1; ++i) {
      for (let j = 1; j < w + 1; ++j) {
        let r = Math.floor(Math.random() * 8); // about 12.5% is wall
        if (r === 7) {
          this.m_place[i][j] = -1;
        } else {
          this.m_place[i][j] = Infinity;
        }
      }
    }

    this.m_place[1][1] = 0;
    this.m_place[w - 1][w - 1] = -2;
  }

  wave(): void {
    let d = 0;
    let finish = true;
    do {
      finish = true;
      for (let i = 1; i < this.m_w + 1; ++i) {
        for (let j = 1; j < this.m_w + 1; ++j) {
          if (this.m_place[i][j] === d) {
            if (this.m_place[i + 1][j] === Infinity) {
              this.m_place[i + 1][j] = d + 1;
              finish = false;
            }
            if (this.m_place[i - 1][j] === Infinity) {
              this.m_place[i - 1][j] = d + 1;
              finish = false;
            }
            if (this.m_place[i][j + 1] === Infinity) {
              this.m_place[i][j + 1] = d + 1;
              finish = false;
            }
            if (this.m_place[i][j - 1] === Infinity) {
              this.m_place[i][j - 1] = d + 1;
              finish = false;
            }

            if (this.m_place[i + 1][j] === -2) {
              finish = true;
            }
            if (this.m_place[i - 1][j] === -2) {
              finish = true;
            }
            if (this.m_place[i][j + 1] === -2) {
              finish = true;
            }
            if (this.m_place[i][j - 1] === -2) {
              finish = true;
            }
          }
        }
      }
      ++d;
    } while (!finish);
  }

  show(): void {
    console.log(this.m_place);
  }
}

const p = [new Board(10), new Board(20), new Board(30)];

for (let i of p) {
  i.wave();
  i.show();
}
