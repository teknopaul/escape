

escapemake: escape.c xml.h c.h json.h html.h
	gcc -Wall -o escape escape.c


.PHONY: clean install uninstall

clean:
	rm escape

install:
	cp escape /usr/bin
	cp *.1 /usr/share/man/man1

uninstall:
	rm -f /usr/bin/escape
	rm -f /usr/share/man/man1/escape.1

