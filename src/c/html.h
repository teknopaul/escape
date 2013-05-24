/*
 * HTML Strings definitions
 */
const char HTML_IN[]   = { '\'',     '\"'    , '&',     '<',    '>',    ' ',      '\n'      };
const char *HTML_OUT[] = { "$apos;", "&quot;", "&amp;", "$lt;", "&gt;", "&nbsp;", "<br/>\n" };


lang_def html = {
  7,
  HTML_IN, 
  HTML_OUT
};