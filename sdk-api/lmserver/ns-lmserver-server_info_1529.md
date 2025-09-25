# SERVER_INFO_1529 structure

## Description

The
**SERVER_INFO_1529** structure specifies the minimum number of free receive work items the server requires before it begins allocating more items.

## Members

### `sv1529_minrcvqueue`

Specifies the minimum number of free receive work items the server requires before it begins allocating more. A larger value for this member helps ensure that there will always be work items available, but a value that is too large is inefficient.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)