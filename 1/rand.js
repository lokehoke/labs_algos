function getRand(x = 3167) {
    return () => {
        x = `${x}`;
        let y = `${+x * +x}`;
        let dif = x.length * 2 - y.length;
        for (let i = 0; i < dif; ++i) {
            y = `0${y}`;
        }

        return +(x = y.substr(x.length / 2, x.length));
    }
}

let rand = getRand();

for (let i = 0; i < 10; ++i) {
    console.log(rand());
}
