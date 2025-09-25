# SESSION_BUFFER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **SESSION_BUFFER** structure contains information about a local network session. One or more **SESSION_BUFFER** structures follows a [SESSION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_header) structure when an application specifies the **NCBSSTAT** command in the **ncb_command** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

## Members

### `lsn`

Specifies the local session number.

### `state`

Specifies the state of the session. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LISTEN_OUTSTANDING** | The session is waiting for a call from a remote computer. |
| **CALL_PENDING** | The session is attempting to connect to a remote computer. |
| **SESSION_ESTABLISHED** | The session connected and is able to transfer data. |
| **HANGUP_PENDING** | The session is being deleted due to a command by the local user. |
| **HANGUP_COMPLETE** | The session was deleted due to a command by the local user. |
| **SESSION_ABORTED** | The session was abandoned due to a network or user problem. |

### `local_name`

Specifies the 16-byte NetBIOS name on the local computer used for this session.

### `remote_name`

Specifies the 16-byte NetBIOS name on the remote computer used for this session.

### `rcvs_outstanding`

Specifies the number of pending **NCBRECV** commands.

### `sends_outstanding`

Specifies the number of pending **NCBSEND** and **NCBCHAINSEND** commands.

## See also

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[SESSION_HEADER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_header)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)