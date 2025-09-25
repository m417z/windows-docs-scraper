# SERVER_INFO_1541 structure

## Description

The
**SERVER_INFO_1541** structure specifies the minimum number of free connection blocks the server sets aside to handle bursts of requests by clients to connect to the server.

## Members

### `sv1541_minfreeconnections`

Specifies the minimum number of free connection blocks maintained per endpoint. The server sets these aside to handle bursts of requests by clients to connect to the server.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)