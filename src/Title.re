module Styles = {
  open Css;

  let title =
    style([
      fontSize(rem(3.0)),
      fontWeight(bold),
      lineHeight(`abs(1.25)),
      letterSpacing(px(1)),
      margin(px(0)),
      position(relative),
      zIndex(1),
    ]);

  let highlight = bg =>
    style([
      backgroundColor(bg),
      height(px(24)),
      position(relative),
      top(px(-24)),
      left(px(-10)),
      maxWidth(vw(90.0)),
      lineHeight(`abs(1.6)),
    ]);
};

[@react.component]
let make = (~bg, ~children, ~id) => {
  <header>
    <h1 className=Styles.title id> children </h1>
    <div className={bg |> Styles.highlight} />
  </header>;
};
