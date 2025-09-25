# SERVER_INFO_1536 structure

## Description

The
**SERVER_INFO_1536** structure specifies whether the server allows clients to use opportunistic locks (oplocks) on files.

## Members

### `sv1536_enableoplocks`

Specifies whether the server allows clients to use oplocks on files. Opportunistic locks are a significant performance enhancement, but have the potential to cause lost cached data on some networks, particularly wide-area networks.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)