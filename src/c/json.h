/*
 * JSON Strings definitions
 */
const char JSON_IN[]   = { '\'',   '\"'  , '\n' , '\t'};
const char *JSON_OUT[] = { "\\\'", "\\\"", "\\n", "\\t"};

lang_def json = {
  2,
  JSON_IN, 
  JSON_OUT
};