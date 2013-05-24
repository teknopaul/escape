Escapes JSON strings for embeding in script output, also supports html and xml entity escaping.

The primary aim of this program is to help writing CGI scripts that output JSON in bash.

e.g.

    #!/bin/bash

    echo 'Content-Type: application/json'
    echo 'Cache-Control: no-cache'
    echo 'Conenction: close'
    echo

    echo '{
        "netstat-data":  "' 

        netstat -an | escape

    echo '"}'

Clearly you can acheive the same goal with sed, awk and many other tools, but this little prog does the job with no fuss.

To output in xml or html suppply the -f option

    last | escape -f xml


