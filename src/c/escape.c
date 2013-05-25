
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

#define ARG_ERROR   1;
#define OTHER_ERROR 2;
/*
 * Escape characters on stdin to stdout.
 * 
 * @author teknopaul
 */
//typedef struct lang_def lang_def;

typedef struct  {
  int len;
  const char *in_chars;
  const char **out_strings;
} lang_def;

#include "json.h"
#include "c.h"
#include "html.h"
#include "xml.h"

static int escape(FILE *in, FILE *out, lang_def def);


int main (int argc, char *argv[]) {
  char *fvalue = "c";
  int ch;
     
  opterr = 0;
     
  while ((ch = getopt (argc, argv, "f:")) != -1) {
    switch (ch)
    {
      case 'f':
        fvalue = optarg;
        break;
      case '?':
        if (optopt == 'f') {
          fprintf(stderr, "Specify the escape format\n");
        }
        else {
          fprintf(stderr, "Unknown option character `\\x%x'\n", optopt);         
        }
        return ARG_ERROR;
      default:
        return ARG_ERROR;
    }
  }
  
  
  if ( strcmp("json", fvalue) == 0 ) {
    return escape(stdin, stdout, json);
  }
  
  if ( strcmp("c", fvalue) == 0 ) {
    return escape(stdin, stdout, c);
  }
  
  if ( strcmp("html", fvalue) == 0 ) {
    return escape(stdin, stdout, html);
  }
  
  if ( strcmp("xml", fvalue) == 0 ) {
    return escape(stdin, stdout, xml);
  }
  
  fprintf(stderr, "Unknown format '%s'\n", fvalue);
  return OTHER_ERROR;
  
}

static int index_of(int len, const char in_chars[], int ch) {
  int i;
  for(i = 0 ; i < len ; i++) {
    if (ch == in_chars[i]) return i;
  }
  return -1;
}


static int escape(FILE *in, FILE *out,  lang_def def) {
  int index;
  int ch;
  while( (ch = fgetc(in)) != EOF ) {
    index = index_of(def.len, def.in_chars, ch);
    if (index > -1) {
      fputs(def.out_strings[index], out);
    }
    else {
      fputc(ch, out);
    }
  }
  return 0;
}