*rdbcd.ctl example file
* RDBE-D must be configured with multi-cast 239.0.2.40:20024
*
* line 1: host(IP address or name) port(5000) time-out(centiseconds)
* using an IP address avoids name server and potential network problems
* example: remote host uses a long time-out
*   192.52.61.56 5000  500
* example: local host uses a short time-out
*   128.183.107.27 5000 100
*  192.168.1.126 5000 500
