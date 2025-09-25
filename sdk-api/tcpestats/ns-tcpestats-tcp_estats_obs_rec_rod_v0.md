# TCP_ESTATS_OBS_REC_ROD_v0 structure

## Description

The **TCP_ESTATS_OBS_REC_ROD_v0** structure contains read-only dynamic information for extended TCP statistics observed on the remote receiver for a TCP connection.

## Members

### `CurRwinRcvd`

Type: **ULONG**

The most recent window advertisement, in bytes, received from the remote receiver.

### `MaxRwinRcvd`

Type: **ULONG**

The maximum window advertisement, in bytes, received from the remote receiver.

### `MinRwinRcvd`

Type: **ULONG**

The minimum window advertisement, in bytes, received from the remote receiver.

### `WinScaleRcvd`

Type: **ULONG**

The value of the received window scale option if one was
received from the remote receiver; otherwise, a value of -1.

Note that if both the **WinScaleSent** member of the [TCP_ESTATS_REC_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_rec_rod_v0) structure and
the **WinScaleRcvd** member are not -1, then Snd.Wind.Scale
will be the same as this value and used to scale receiver
window announcements from the remote host to the local
host.

## Remarks

The **TCP_ESTATS_OBS_REC_ROD_v0** structure is used as part of the TCP extended statistics feature available on Windows Vista and later.

The **TCP_ESTATS_OBS_REC_ROD_v0** is defined as version 0 of the structure for read-only dynamic information for extended TCP statistics on the local receiver for a TCP connection. This information is available after the connection has been established.

The **TCP_ESTATS_OBS_REC_ROD_v0** structure is retrieved by calls to the [GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats) or [GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats) functions when **TcpConnectionEstatsObsRec** is passed in the *EstatsType* parameter. Extended TCP statistics need to be enabled to retrieve this structure.

The members of this structure are defined in the IETF RFC on the TCP Extended Statistics MIB. For more information, see [http://www.ietf.org/rfc/rfc4898.txt](http://tools.ietf.org/html/rfc4898).

The following is the mapping of the members in the **TCP_ESTATS_OBS_REC_ROD_v0** structure to the entries defined in RFC 4898 for extended TCP statistics:

| Term | Description |
| --- | --- |
| **CurRwinRcvd** | tcpEStatsPerfCurRwinRcvd |
| **MaxRwinRcvd** | tcpEStatsPerfMaxRwinRcvd |
| **MinRwinRcvd** | No mapping to this member. |
| **WinScaleRcvd** | tcpEStatsStackWinScaleRcvd |

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)