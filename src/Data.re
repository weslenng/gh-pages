type social = {
  discord: string,
  github: string,
  linkedin: string,
};

type profile = {
  name: string,
  role: string,
  email: string,
  birth: string,
  location: string,
  personality: string,
  social,
};

type tag =
  | Advanced
  | Beginner
  | Interested
  | Intermediary
  | NotInterested
  | Rusty
  | Toybox
  | WorkExperience;

type attr = {
  name: string,
  tags: list(tag),
};

type skill = {
  name: string,
  attribs: list(attr),
};

type raw = {
  profile,
  skills: list(skill),
};

let raw = {
  profile: {
    name: "@weslenng",
    role: "Full Stack Developer",
    email: "weslenng@outlook.com",
    birth: "2000-12-31",
    location: {js|São Paulo, Brazil|js},
    personality: {js|INTP-T • ♑|js},
    social: {
      discord: "https://discordapp.com/users/239549277611753473",
      github: "https://github.com/weslenng",
      linkedin: "https://www.linkedin.com/in/weslenng",
    },
  },
  skills: [
    {
      name: "Languages",
      attribs: [
        {name: "Javascript", tags: [Advanced, WorkExperience]},
        {name: "Typescript", tags: [Intermediary, Toybox, WorkExperience]},
        {name: "Golang", tags: [Intermediary, Interested]},
        {name: "ReasonML, OCaml", tags: [Beginner, Interested]},
        {name: "Rust", tags: [Interested]},
        {name: "C, C++", tags: [Beginner, NotInterested]},
      ],
    },
    {
      name: "Back End",
      attribs: [
        {name: "Node.JS", tags: [Advanced, WorkExperience]},
        {name: "REST APIs", tags: [Advanced, WorkExperience]},
        {name: "GraphQL", tags: [Beginner, Interested]},
        {name: "Microservices", tags: [Beginner, Interested]},
        {name: "SQL DBs", tags: [Intermediary, WorkExperience]},
        {name: "NoSQL DBs", tags: [Beginner, Interested]},
      ],
    },
    {
      name: "Front End",
      attribs: [
        {name: "HTML5, CSS3", tags: [Advanced, WorkExperience]},
        {name: "UI, UX", tags: [Intermediary, NotInterested]},
        {name: "React", tags: [Advanced, Toybox]},
        {name: "GraphQL", tags: [Beginner, Interested]},
      ],
    },
    {
      name: "Others",
      attribs: [
        {name: "AWS", tags: [Beginner, Interested, WorkExperience]},
        {name: "Google Cloud", tags: [Intermediary, Interested]},
        {name: "Docker, Kubernetes", tags: [Beginner, Interested]},
        {name: "Linux", tags: [Advanced, WorkExperience]},
        {name: "Git", tags: [Beginner, WorkExperience]},
        {name: "Tests", tags: [Intermediary, Interested]},
        {name: "Security", tags: [Intermediary, Toybox]},
        {name: "Scrum, Agile", tags: [Beginner, WorkExperience]},
      ],
    },
  ],
};

let string_of_tag =
  fun
  | Advanced => "advanced"
  | Beginner => "beginner"
  | Interested => "interested"
  | Intermediary => "intermediary"
  | NotInterested => "not-interested"
  | Rusty => "rusty"
  | Toybox => "toybox"
  | WorkExperience => "work-experience";

let color_of_tag =
  fun
  | Advanced => Css.rgb(255, 129, 142)
  | Beginner => Css.rgb(249, 255, 163)
  | Interested => Css.rgb(145, 215, 255)
  | Intermediary => Css.rgb(255, 159, 91)
  | NotInterested => Css.rgb(222, 222, 222)
  | Rusty => Css.rgb(222, 222, 222)
  | Toybox => Css.rgb(245, 159, 255)
  | WorkExperience => Css.rgb(188, 255, 193);
