# SERVER_INFO_1506 structure

## Description

The
**SERVER_INFO_1506** structure contains information about the maximum number of work items the specified server can allocate.

## Members

### `sv1506_maxworkitems`

Specifies the maximum number of receive buffers, or work items, the server can allocate. If this limit is reached, the transport protocol must initiate flow control at a significant cost to performance.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)