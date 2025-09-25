# MIB_TCPSTATS2 structure

## Description

The
**MIB_TCPSTATS2** structure contains statistics for the TCP protocol running on the local computer. This structure is different from [MIB_TCPSTATS](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcpstats_lh) structure in that it uses 64-bit counters, rather than 32-bit counters.

## Members

### `RtoAlgorithm`

### `dwRtoMin`

Type: **DWORD**

The minimum RTO value in milliseconds.

### `dwRtoMax`

Type: **DWORD**

The maximum RTO value in milliseconds.

### `dwMaxConn`

Type: **DWORD**

The maximum number of connections. If this member is -1, the maximum number of connections is variable.

### `dwActiveOpens`

Type: **DWORD**

The number of active opens. In an active open, the client is initiating a connection with the server.

### `dwPassiveOpens`

Type: **DWORD**

The number of passive opens. In a passive open, the server is listening for a connection request from a client.

### `dwAttemptFails`

Type: **DWORD**

The number of failed connection attempts.

### `dwEstabResets`

Type: **DWORD**

The number of established connections that were reset.

### `dwCurrEstab`

Type: **DWORD**

The number of currently established connections.

### `dw64InSegs`

Type: **DWORD**

The number of segments received.

### `dw64OutSegs`

Type: **DWORD64**

The number of segments transmitted. This number does not include retransmitted segments.

### `dwRetransSegs`

Type: **DWORD64**

The number of segments retransmitted.

### `dwInErrs`

Type: **DWORD**

The number of errors received.

### `dwOutRsts`

Type: **DWORD**

The number of segments transmitted with the reset flag set.

### `dwNumConns`

Type: **DWORD**

The number of connections that are currently present in the system. This total number includes connections in all states except listening connections.

#### - TCP_RTO_ALGORITHM

Type: **DWORD**

The retransmission time-out (RTO) algorithm in use.

| Value | Meaning |
| --- | --- |
| **MIB_TCP_RTO_OTHER**<br><br>1 | Other |
| **MIB_TCP_RTO_CONSTANT**<br><br>2 | Constant Time-out |
| **MIB_TCP_RTO_RSRE**<br><br>3 | MIL-STD-1778 Appendix B |
| **MIB_TCP_RTO_VANJ**<br><br>4 | Van Jacobson's Algorithm |

## Remarks

The [GetTcpStatisticsEx2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatisticsex2) function returns a pointer to a **MIB_TCPSTATS2** structure.

 This structure is defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.