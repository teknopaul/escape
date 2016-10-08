name = escape
tmp_dir := /tmp/$(name)_debbuild
arch != uname -m
version != grep 'Version:' ../../DEBIAN/control | awk '{print $$2}'

escapemake: escape.c xml.h c.h json.h html.h
	gcc -Wall -o escape escape.c


.PHONY: clean install uninstall deb deploy-local deploy-remote test

clean:
	rm escape
	rm -f ../../target/*.deb

install:
	cp escape /usr/bin
	cp *.1 /usr/share/man/man1

uninstall:
	rm -f /usr/bin/escape
	rm -f /usr/share/man/man1/escape.1

deb:

	#@echo "Building $(name)-$(version).$(arch).deb"

	mkdir -p "$(tmp_dir)"
	sudo rm -rf "$(tmp_dir)"
	mkdir -p "$(tmp_dir)/usr/bin"
	mkdir -p "$(tmp_dir)/usr/share/man/man1"
	
	cp --archive ../../DEBIAN "$(tmp_dir)"
	cp --archive escape "$(tmp_dir)/usr/bin"
	cp --archive escape.1 "$(tmp_dir)/usr/share/man/man1"
	sudo chown -R root.root "$(tmp_dir)"

	dpkg-deb --build $(tmp_dir) $(name)-$(version).$(arch).deb
	test -f $(name)-$(version).$(arch).deb && echo "Built $(name)-$(version).$(arch).deb"
	mkdir -p ../../target
	mv $(name)-$(version).$(arch).deb ../../target
	
deploy-local:
	rsync --archive -v ../../target/ deb@pibox:/var/debrepo/
	ssh deb@pibox /home/deb/bin/rescan.sh

deploy-remote:
	rsync --archive -v ../../target/ deb@vbox:/var/debrepo/

test:
	echo '<xml/>'     | ./escape -f xml  | grep '$lt;xml/&gt;'
	echo '"whatever"' | ./escape -f c    | grep '\\"whatever\\"'
	echo '<html/>'    | ./escape -f html | grep '$lt;html/&gt;'
	echo '"json"'     | ./escape -f json | grep '\\"json\\"'
	
	
	
	
	
	
	
	