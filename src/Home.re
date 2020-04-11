module Styles = {
  open Css;

  let light = style([backgroundColor(white), height(px(64))]);

  let (-@) = Calc.(-);
  let root =
    style([
      alignItems(center),
      backgroundColor(rgb(64, 61, 88)),
      display(flexBox),
      justifyContent(center),
      minHeight(vh(100.0) -@ px(64)),
      padding2(~v=px(0), ~h=px(16)),
    ]);

  let container = style([width(px(326))]);
};

[@react.component]
let make = (~profile) => {
  <>
    <div className=Styles.light />
    <div className=Styles.root>
      <div className=Styles.container> <Resume profile /> </div>
    </div>
  </>;
};
