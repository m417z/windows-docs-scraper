# SESSION_INFO_1 structure

## Description

Contains information about the session, including name of the computer; name of the user; and open files, pipes, and devices on the computer.

## Members

### `sesi1_cname`

Pointer to a Unicode string specifying the name of the computer that established the session. This string cannot contain a backslash (\\).

### `sesi1_username`

Pointer to a Unicode string specifying the name of the user who established the session.

### `sesi1_num_opens`

Specifies a DWORD value that contains the number of files, devices, and pipes opened during the session.

### `sesi1_time`

Specifies a DWORD value that contains the number of seconds the session has been active.

### `sesi1_idle_time`

Specifies a DWORD value that contains the number of seconds the session has been idle.

### `sesi1_user_flags`

Specifies a DWORD value that describes how the user established the session. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SESS_GUEST** | The user specified by the **sesi1_username** member established the session using a guest account. |
| **SESS_NOENCRYPTION** | The user specified by the **sesi1_username** member established the session without using password encryption. |

## See also

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[NetSessionGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiongetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Session Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)