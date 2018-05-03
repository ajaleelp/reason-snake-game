type t =
  | ArrowUp
  | ArrowRight
  | Ignore;

let parseKey = evt =>
  switch (Webapi.Dom.KeyboardEvent.key(evt)) {
  | "ArrowUp" => ArrowUp
  | "ArrowRight" => ArrowRight
  | _ => Ignore
  };