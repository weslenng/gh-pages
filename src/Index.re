[@bs.module "normalize.css"] external normalize: string = "normalize";
normalize;

[@bs.module "typeface-exo-2"] external typeface: string = "typeface";
typeface;

Css.(
  global(
    "body",
    [
      fontFamilies([
        `custom("\"Exo 2\""),
        `custom("Arial"),
        `custom("Helvetica"),
        `custom("sans-serif"),
      ]),
    ],
  )
);

ReactDOMRe.renderToElementWithId(<App />, "root");
