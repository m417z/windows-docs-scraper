# SERVER_INFO_1544 structure

## Description

The
**SERVER_INFO_1544** structure specifies the initial number of tree connections to be allocated in the connection table.

## Members

### `sv1544_initconntable`

Specifies the initial number of tree connections to be allocated in the connection table. The server automatically increases the table as necessary, so setting the member to a higher value is an optimization.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)