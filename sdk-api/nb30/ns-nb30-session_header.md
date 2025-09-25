# SESSION_HEADER structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **SESSION_HEADER** structure contains information about a network session. This structure is pointed to by the **ncb_buffer** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure. **SESSION_HEADER** is followed by as many [SESSION_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_buffer) structures as are required to describe the current network sessions.

## Members

### `sess_name`

Specifies the name number of the session. This value corresponds to the **ncb_num** member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure.

### `num_sess`

Specifies the number of sessions that have the name specified by the **sess_name** member.

### `rcv_dg_outstanding`

Specifies the number of outstanding **NCBDGRECV** and **NCBDGRECVBC** commands.

### `rcv_any_outstanding`

Specifies the number of outstanding **NCBRECVANY** commands.

## See also

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[SESSION_BUFFER](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-session_buffer)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)