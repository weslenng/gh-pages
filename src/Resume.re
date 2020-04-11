module Styles = {
  open Css;

  let section =
    style([color(white), display(flexBox), flexDirection(column)]);

  let details = style([fontSize(rem(0.8)), marginTop(px(8))]);

  let paragraph = style([margin2(~v=px(8), ~h=px(0))]);

  let link = style([color(white), marginRight(px(24))]);

  let icon = style([marginTop(px(32))]);
};

let rs = React.string;

module Emoji = {
  [@react.component]
  let make = (~ariaLabel, ~codePoint) => {
    <span ariaLabel role="img">
      {codePoint->Js.String.fromCodePoint->rs}
    </span>;
  };
};

type t =
  | Component(ReasonReact.reactElement)
  | String(string);

module Item = {
  [@react.component]
  let make = (~prefix, ~sufix) => {
    <p className=Styles.paragraph>
      prefix->rs
      <span>
        {switch (sufix) {
         | Component(sufix) => sufix
         | String(sufix) => sufix->rs
         }}
      </span>
    </p>;
  };
};

module Email = {
  [@react.component]
  let make = (~href) => {
    <a
      className=Styles.link
      href={"mailto:" ++ href ++ "?Subject=Whats%20up!"}
      target="_top">
      href->rs
    </a>;
  };
};

module Link = {
  [@react.component]
  let make = (~href, ~children) => {
    <a className=Styles.link href rel="noopener noreferrer" target="_blank">
      children
    </a>;
  };
};

[@react.component]
let make = (~profile: Data.profile) => {
  let age =
    ReasonDateFns.DateFns.differenceInYears(
      Js.Date.fromString(profile.birth),
      Js.Date.make(),
    )
    ->Js.Float.toString;

  <section className=Styles.section>
    <Title bg={Css.rgb(193, 69, 102)}> profile.name->rs </Title>
    <Caption>
      {(profile.role ++ " ")->rs}
      <Emoji ariaLabel="Hot Beverage Emoji" codePoint=9749 />
      <Emoji ariaLabel="Hammer and Wrench Emoji" codePoint=128736 />
    </Caption>
    <div className=Styles.details>
      <Item
        prefix={"Age: " ++ age ++ " "}
        sufix={
          Component(<Emoji ariaLabel="Sparkles Emoji" codePoint=10024 />)
        }
      />
      <Item
        prefix="Email: "
        sufix={Component(<Email href={profile.email} />)}
      />
      <Item prefix="Location: " sufix={profile.location->String} />
      <Item prefix="Personality: " sufix={profile.personality->String} />
    </div>
    <div className=Styles.icon>
      <Link href={profile.social.discord}> <Discord /> </Link>
      <Link href={profile.social.github}> <GitHub /> </Link>
      <Link href={profile.social.linkedin}> <Linkedin /> </Link>
    </div>
  </section>;
};
