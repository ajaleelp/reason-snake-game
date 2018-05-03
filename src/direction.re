type t =
  | Up
  | Right
  | Down
  | Left;

type changeInDirection = option(t);

let right = Right;

let parsedKey = key =>
  switch (key) {
  | "ArrowUp" => Some(Up)
  | "ArrowRight" => Some(Right)
  | "ArrowDown" => Some(Down)
  | "ArrowLeft" => Some(Left)
  | _ => None
  };

let update = (direction, key) =>
  switch (direction, parsedKey(key)) {
  | (direction, None) => direction
  | (Up | Down, Some(Left | Right) as leftOrRight) =>
    leftOrRight |> Ext.Option.unsafelyUnwrapOption
  | ((Up | Down) as upOrDown, Some(Up | Down)) => upOrDown
  | (Left | Right, Some(Up | Down) as upOrDown) =>
    upOrDown |> Ext.Option.unsafelyUnwrapOption
  | ((Left | Right) as leftOrRight, Some(Left | Right)) => leftOrRight
  };

let deltaX = direction =>
  switch (direction) {
  | Right => 1
  | Left => (-1)
  | Up
  | Down => 0
  };

let deltaY = direction =>
  switch (direction) {
  | Up => (-1)
  | Down => 1
  | Left
  | Right => 0
  };