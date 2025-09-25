# SERVER_INFO_1528 structure

## Description

The
**SERVER_INFO_1528** structure specifies the period of time that the scavenger remains idle before waking up to service requests.

## Members

### `sv1528_scavtimeout`

Specifies the period of time, in seconds, that the scavenger remains idle before waking up to service requests. A smaller value for this member improves the response of the server to various events but costs CPU cycles.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)