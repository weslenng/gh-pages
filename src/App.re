[@react.component]
let make = () => {
  <>
    <Home profile={Data.raw.profile} />
    <SkillPage skills={Data.raw.skills} />
  </>;
};
