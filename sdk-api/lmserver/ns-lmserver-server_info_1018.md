# SERVER_INFO_1018 structure

## Description

The
**SERVER_INFO_1018** structure contains information about how much the announce rate can vary for the specified server.

## Members

### `sv1018_anndelta`

Specifies the delta value for the announce rate, in milliseconds. This value specifies how much the announce rate can vary from the period of time specified in the sv*X*_announce member.

The delta value allows randomly varied announce rates. For example, if the sv*X*_announce member has the value 10 and the sv*X*_anndelta member has the value 1, the announce rate can vary from 9.999 seconds to 10.001 seconds. For more information, see
[SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102) and
[SERVER_INFO_1017](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_1017).

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[SERVER_INFO_1017](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_1017)

[SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)