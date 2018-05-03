type t;

let create: (list((int, int)), Direction.t) => t;

let move: (t, Direction.t, Food.t) => t;

let body: t => list(Cell.t);

let direction: t => Direction.t;

let head: t => Cell.t;

let grew: (t, t) => bool;