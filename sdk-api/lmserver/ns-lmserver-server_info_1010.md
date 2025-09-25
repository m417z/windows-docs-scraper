# SERVER_INFO_1010 structure

## Description

The
**SERVER_INFO_1010** structure contains the auto-disconnect time associated with the specified server.

## Members

### `sv1010_disc`

Specifies the auto-disconnect time, in minutes.

If a session is idle longer than the period of time specified by this member, the server disconnects the session. If the value of this member is SV_NODISC, auto-disconnect is not enabled.

## See also

[NetServerGetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservergetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Server Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)