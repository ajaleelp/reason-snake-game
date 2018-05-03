type t = {
  body: list(Cell.t),
  direction: Direction.t,
};

let newHead = (head, direction) => {
  let newX = Cell.x(head) + Direction.deltaX(direction);
  let newY = Cell.y(head) + Direction.deltaY(direction);
  Cell.create((newX, newY));
};

let foodFound = (head, food) => {
  let foodPosition = Food.position(food);
  Cell.x(head) == Cell.x(foodPosition)
  && Cell.y(head) == Cell.y(foodPosition);
};

let fixTail = (hasEaten, tail) => hasEaten ? tail : List.tl(tail);

let newTail = (snake, hasEaten) => {
  let [head, ...tail] = snake.body;
  tail |> List.rev |> fixTail(hasEaten) |> List.rev |> List.append([head]);
};

let move = (snake, direction, food) => {
  let [head, ...tail] = snake.body;
  let head' = newHead(head, direction);
  let hasEaten = foodFound(head', food);
  {body: [head', ...newTail(snake, hasEaten)], direction};
};

let create = (xs, direction) => {
  body: List.map(Cell.create, xs),
  direction,
};

let body = snake => snake.body;

let direction = snake => snake.direction;

let head = snake => snake |> body |> List.hd;

let grew = (oldSnake, newSnake) =>
  newSnake |> body |> List.length > (oldSnake |> body |> List.length);