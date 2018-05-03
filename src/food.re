type t = Cell.t;

let create = Cell.create;

let position = t => t;

let createRandom = () => create((Random.int(20), Random.int(20)));