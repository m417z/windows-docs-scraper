# SERVER_INFO_1016 structure

## Description

The
**SERVER_INFO_1016** structure contains information about whether the server is visible to other computers in the same network domain.

## Members

### `sv1016_hidden`

Specifies whether the server is visible to other computers in the same network domain. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SV_VISIBLE** | The server is visible. |
| **SV_HIDDEN** | The server is not visible. |

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)