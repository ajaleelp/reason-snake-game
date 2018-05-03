type t = {
  canvasContext: int,
  snake: Snake.t,
  food: Food.t,
};

let create = (snake, food) => {canvasContext: 0, snake, food};

let snake = t => t.snake;

let food = t => t.food;