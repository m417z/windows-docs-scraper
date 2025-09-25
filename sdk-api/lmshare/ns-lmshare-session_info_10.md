# SESSION_INFO_10 structure

## Description

Contains information about the session, including name of the computer; name of the user; and active and idle times for the session.

## Members

### `sesi10_cname`

Pointer to a Unicode string specifying the name of the computer that established the session. This string cannot contain a backslash (\\).

### `sesi10_username`

Pointer to a Unicode string specifying the name of the user who established the session.

### `sesi10_time`

Specifies the number of seconds the session has been active.

### `sesi10_idle_time`

Specifies the number of seconds the session has been idle.

## See also

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[NetSessionGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiongetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Session Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)