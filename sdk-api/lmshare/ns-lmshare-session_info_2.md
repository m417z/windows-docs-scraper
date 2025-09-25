# SESSION_INFO_2 structure

## Description

Contains information about the session, including name of the computer; name of the user; open files, pipes, and devices on the computer; and the type of client that established the session.

## Members

### `sesi2_cname`

Pointer to a Unicode string specifying the name of the computer that established the session. This string cannot contain a backslash (\\).

### `sesi2_username`

Pointer to a Unicode string specifying the name of the user who established the session.

### `sesi2_num_opens`

Specifies a DWORD value that contains the number of files, devices, and pipes opened during the session.

### `sesi2_time`

Specifies a DWORD value that contains the number of seconds the session has been active.

### `sesi2_idle_time`

Specifies a DWORD value that contains the number of seconds the session has been idle.

### `sesi2_user_flags`

Specifies a DWORD value that describes how the user established the session. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SESS_GUEST** | The user specified by the **sesi2_username** member established the session using a guest account. |
| **SESS_NOENCRYPTION** | The user specified by the **sesi2_username** member established the session without using password encryption. |

### `sesi2_cltype_name`

Pointer to a Unicode string that specifies the type of client that established the session. Following are the defined types for LAN Manager servers.

| Value | Meaning |
| --- | --- |
| **DOS LM 1.0** | LAN Manager for MS-DOS 1.0 clients |
| **DOS LM 2.0** | LAN Manager for MS-DOS 2.0 clients |
| **OS/2 LM 1.0** | LAN Manager for MS-OS/2 1.0 clients |
| **OS/2 LM 2.0** | LAN Manager for MS-OS/2 2.0 clients |

Sessions from LAN Manager servers running UNIX also will appear as LAN Manager 2.0.

## See also

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[NetSessionGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiongetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Session Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)