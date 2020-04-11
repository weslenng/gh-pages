module Styles = {
  open Css;

  let caption =
    style([
      fontSize(rem(1.4)),
      fontWeight(medium),
      lineHeight(`abs(1.25)),
      letterSpacing(px(1)),
      margin(px(0)),
    ]);
};

[@react.component]
let make = (~children) => {
  <h2 className=Styles.caption> children </h2>;
};
