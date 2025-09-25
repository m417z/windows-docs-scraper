# SESSION_INFO_502 structure

## Description

Contains information about the session, including name of the computer; name of the user; open files, pipes, and devices on the computer; and the name of the transport the client is using.

## Members

### `sesi502_cname`

Pointer to a Unicode string specifying the name of the computer that established the session. This string cannot contain a backslash (\\).

### `sesi502_username`

Pointer to a Unicode string specifying the name of the user who established the session.

### `sesi502_num_opens`

Specifies the number of files, devices, and pipes opened during the session.

### `sesi502_time`

Specifies the number of seconds the session has been active.

### `sesi502_idle_time`

Specifies the number of seconds the session has been idle.

### `sesi502_user_flags`

Specifies a value that describes how the user established the session. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SESS_GUEST** | The user specified by the **sesi502_username** member established the session using a guest account. |
| **SESS_NOENCRYPTION** | The user specified by the **sesi502_username** member established the session without using password encryption. |

### `sesi502_cltype_name`

Pointer to a Unicode string that specifies the type of client that established the session. Following are the defined types for LAN Manager servers.

| Value | Meaning |
| --- | --- |
| **DOS LM 1.0** | LAN Manager for MS-DOS 1.0 clients. |
| **DOS LM 2.0** | LAN Manager for MS-DOS 2.0 clients. |
| **OS/2 LM 1.0** | LAN Manager for MS-OS/2 1.0 clients. |
| **OS/2 LM 2.0** | LAN Manager for MS-OS/2 2.0 clients. |

Sessions from LAN Manager servers running UNIX also will appear as LAN Manager 2.0.

### `sesi502_transport`

Specifies the name of the transport that the client is using to communicate with the server.

## See also

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Session Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)