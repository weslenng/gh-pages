module Styles = {
  open Css;

  let root =
    style([
      alignItems(center),
      display(flexBox),
      flexDirection(column),
      justifyContent(center),
      minHeight(vh(100.0)),
      padding(px(16)),
    ]);

  let container = style([color(rgb(50, 50, 48)), width(px(326))]);

  let tcontainer =
    style([
      display(grid),
      gridTemplateColumns([fr(1.0), fr(1.0)]),
      gridTemplateRows([`auto, `auto]),
      gridColumnGap(px(32)),
      gridRowGap(px(32)),
      media(
        "(max-width: 960px)",
        [
          gridTemplateColumns([fr(1.0)]),
          gridTemplateRows([`auto, `auto, `auto, `auto]),
          gridColumnGap(px(0)),
          gridRowGap(px(48)),
        ],
      ),
    ]);
};

let rs = React.string;

[@react.component]
let make = (~skills) => {
  <>
    <div className=Styles.root>
      <div className=Styles.container>
        <Title id="skill-set" bg={Css.rgb(255, 212, 94)}>
          "My Skill Set"->rs
        </Title>
      </div>
      <div className=Styles.tcontainer>
        {List.mapi(
           (key, skill) => <SkillTable key={key->string_of_int} skill />,
           skills,
         )
         ->Array.of_list
         ->ReasonReact.array}
      </div>
    </div>
  </>;
};
