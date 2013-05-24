/*
 * JSON Strings definitions
 */
const char JSON_IN[]   = { '\'',   '\"'   };
const char *JSON_OUT[] = { "\\\'", "\\\"" };


lang_def json = {
  2,
  JSON_IN, 
  JSON_OUT
};