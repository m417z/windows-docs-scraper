# SERVER_INFO_1005 structure

## Description

The
**SERVER_INFO_1005** structure contains a comment that describes the specified server.

## Members

### `sv1005_comment`

Pointer to a string that contains a comment describing the server. The comment can be null.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** are defined.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)