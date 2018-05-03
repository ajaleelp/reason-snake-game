let initialSnake =
  Snake.create(
    [(10, 10), (11, 10), (12, 10), (13, 10)],
    Direction.right,
  );

let initialFood = Food.create((15, 10));

let initialWorld = World.create(initialSnake, initialFood);

let state = ref(initialWorld);

let drawWorld = world => {
  state := world;
  Draw.clearScene();
  Draw.drawSnake(World.snake(state^));
  Draw.drawFood(World.food(state^));
};

let handleTick = () => {
  let oldWorld = state^;
  let oldSnake = World.snake(oldWorld);
  let newSnake =
    Snake.move(oldSnake, Snake.direction(oldSnake), World.food(oldWorld));
  let newFood =
    Snake.grew(oldSnake, newSnake) ?
      Food.createRandom() : World.food(oldWorld);
  let newWorld = World.create(newSnake, newFood);
  drawWorld(newWorld);
  Js.log(Snake.direction(newSnake));
};

Js.Global.setInterval(handleTick, 300);

/* Handling KeyDown Events */
open Webapi.Dom;

let documentEventTarget =
  document
  |> Document.asHtmlDocument
  |> Ext.Option.andThen(HtmlDocument.body)
  |> Ext.Option.unsafelyUnwrapOption
  |> Element.asEventTarget;

let handleEvent = evt => {
  let oldWorld = state^;
  let oldSnake = World.snake(oldWorld);
  let keyPressed = Webapi.Dom.KeyboardEvent.key(evt);
  let newDirection = Direction.update(Snake.direction(oldSnake), keyPressed);
  let newSnake =
    Snake.move(World.snake(oldWorld), newDirection, World.food(oldWorld));
  let newWorld = World.create(newSnake, World.food(oldWorld));
  state := newWorld;
};

Webapi.Dom.EventTarget.addKeyDownEventListener(
  handleEvent,
  documentEventTarget,
);