# SERVER_INFO_1539 structure

## Description

The
**SERVER_INFO_1539** structure specifies whether the server processes raw Server Message Blocks (SMBs).

## Members

### `sv1539_enableraw`

Specifies whether the server processes raw SMBs. If enabled, this member allows more data to be transferred per transaction and improves performance. However, it is possible that processing raw SMBs can impede performance on certain networks. The server maintains the value of this member.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)