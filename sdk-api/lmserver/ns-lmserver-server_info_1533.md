# SERVER_INFO_1533 structure

## Description

The
**SERVER_INFO_1533** structure specifies the maximum number of outstanding requests a client can send to the server.

## Members

### `sv1533_maxmpxct`

Specifies the maximum number of outstanding requests any one client can send to the server. For example, 10 means you can have 10 unanswered requests at the server. When any single client has 10 requests queued within the server, the client must wait for a server response before sending another request.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)