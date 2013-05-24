/*
 * XML Strings definitions
 */
const char XML_IN[]   = { '\'',     '\"' ,    '&',     '<',    '>'    };
const char *XML_OUT[] = { "$apos;", "&quot;", "&amp;", "$lt;", "&gt;" };


lang_def xml = {
  57,
  XML_IN, 
  XML_OUT
};