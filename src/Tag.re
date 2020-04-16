module Styles = {
  open Css;

  let tag = tag =>
    style([
      backgroundColor(tag->Data.color_of_tag),
      borderRadius(px(4)),
      color(rgb(55, 53, 47)),
      display(inlineBlock),
      fontSize(rem(0.8)),
      lineHeight(pct(120.0)),
      marginRight(px(4)),
      media("(max-width: 960px)", [marginBottom(px(4))]),
      padding(px(2)),
    ]);
};

let rs = React.string;

[@react.component]
let make = (~tag) => {
  <div className={tag->Styles.tag}>
    {tag->Data.string_of_tag->rs}
  </div>;
};
