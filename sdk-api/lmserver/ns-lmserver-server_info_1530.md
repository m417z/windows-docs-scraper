# SERVER_INFO_1530 structure

## Description

The
**SERVER_INFO_1530** structure specifies the minimum number of available receive work items the server requires to begin processing a server message block.

## Members

### `sv1530_minfreeworkitems`

Specifies the minimum number of available receive work items that the server requires to begin processing a server message block. A larger value for this member ensures that work items are available more frequently for nonblocking requests, but it also increases the likelihood that blocking requests will be rejected.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)