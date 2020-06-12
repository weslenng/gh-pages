open Css;

[@bs.module "normalize.css"] external normalize: string = "normalize";
normalize;

[@bs.module "typeface-exo-2"] external typeface: string = "typeface";
typeface;

global(
  "body",
  [
    fontFamilies([
      `custom("\"Exo 2\""),
      `custom("-apple-system"),
      `custom("BlinkMacSystemFont"),
      `custom("\"Segoe UI\""),
      `custom("Roboto"),
      `custom("Helvetica"),
      `custom("Arial"),
      `custom("sans-serif"),
      `custom("\"Apple Color Emoji\""),
      `custom("\"Segoe UI Emoji\""),
      `custom("\"Segoe UI Symbol\""),
    ]),
  ],
);

global("html", [unsafe("scroll-behavior", "smooth")]);

ReactDOMRe.renderToElementWithId(<App />, "root");
