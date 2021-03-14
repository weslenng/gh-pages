type social = {
  discord: string,
  github: string,
  twitter: string,
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
    name: "Weslen Guerreiro",
    role: "Software Engineer",
    email: "weslenng@outlook.com",
    birth: "2000-12-31",
    location: {js|São Paulo, Brazil|js},
    personality: {js|INTP-T • ♑|js},
    social: {
      discord: "https://discordapp.com/users/239549277611753473",
      github: "https://github.com/weslenng",
      twitter: "https://twitter.com/theweslenng",
      linkedin: "https://www.linkedin.com/in/weslenng",
    },
  },
  skills: [
    {
      name: "Languages",
      attribs: [
        {name: "Javascript", tags: [Advanced, WorkExperience]},
        {name: "Typescript", tags: [Advanced, WorkExperience]},
        {name: "Golang", tags: [Advanced, WorkExperience]},
        {name: "Rust", tags: [Intermediary, Toybox, Interested]},
        {name: "Elixir, Erlang", tags: [Beginner, Interested]},
        {name: "Reason, OCaml", tags: [Intermediary, Interested]},
        {name: "C, C++", tags: [Intermediary]},
      ],
    },
    {
      name: "Back End",
      attribs: [
        {name: "Node.JS", tags: [Advanced, WorkExperience]},
        {name: "REST APIs", tags: [Advanced, WorkExperience]},
        {name: "GraphQL", tags: [Intermediary, Interested]},
        {name: "Microservices", tags: [Beginner, Interested]},
        {name: "SQL DBs", tags: [Intermediary, WorkExperience]},
        {name: "NoSQL DBs", tags: [Intermediary, Interested]},
      ],
    },
    {
      name: "Front End",
      attribs: [
        {name: "HTML5, CSS3", tags: [Advanced, WorkExperience]},
        {name: "UI, UX", tags: [Intermediary, NotInterested]},
        {name: "React", tags: [Intermediary, Toybox]},
        {name: "GraphQL", tags: [Intermediary, Interested]},
      ],
    },
    {
      name: "Others",
      attribs: [
        {name: "AWS", tags: [Advanced, WorkExperience]},
        {name: "Google Cloud", tags: [Intermediary, Interested]},
        {name: "Docker, Kubernetes", tags: [Intermediary, Interested]},
        {name: "Linux", tags: [Advanced, WorkExperience]},
        {name: "Git", tags: [Intermediary, WorkExperience]},
        {name: "Tests", tags: [Intermediary, Interested]},
        {name: "Security", tags: [Advanced, Toybox]},
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
  | Toybox => "toybox"
  | WorkExperience => "work-experience";

let color_of_tag =
  fun
  | Advanced => Css.rgb(255, 129, 142)
  | Beginner => Css.rgb(249, 255, 163)
  | Interested => Css.rgb(145, 215, 255)
  | Intermediary => Css.rgb(255, 159, 91)
  | NotInterested => Css.rgb(222, 222, 222)
  | Toybox => Css.rgb(245, 159, 255)
  | WorkExperience => Css.rgb(188, 255, 193);
