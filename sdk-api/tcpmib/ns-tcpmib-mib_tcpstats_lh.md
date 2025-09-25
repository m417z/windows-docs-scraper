# MIB_TCPSTATS_LH structure

## Description

The
**MIB_TCPSTATS** structure contains statistics for the TCP protocol running on the local computer.

## Members

### `dwRtoAlgorithm`

Type: **DWORD**

The retransmission time-out (RTO) algorithm in use. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **MIB_TCP_RTO_OTHER**<br><br>1 | Other |
| **MIB_TCP_RTO_CONSTANT**<br><br>2 | Constant Time-out |
| **MIB_TCP_RTO_RSRE**<br><br>3 | MIL-STD-1778 Appendix B |
| **MIB_TCP_RTO_VANJ**<br><br>4 | Van Jacobson's Algorithm |

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

### `dwInSegs`

Type: **DWORD**

The number of segments received.

### `dwOutSegs`

Type: **DWORD**

The number of segments transmitted. This number does not include retransmitted segments.

### `dwRetransSegs`

Type: **DWORD**

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

## Remarks

The [GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics) function returns a pointer to a **MIB_TCPSTATS** structure.

The **MIB_TCPSTATS** structure changed slightly on Windows Vista and later. On Windows Vista and later, the **dwRtoAlgorithm** member is replaced by a union that contains the following members.

| Member | Description |
| --- | --- |
| DWORD dwRtoAlgorithm | The retransmission time-out (RTO) algorithm in use. |
| TCP_RTO_ALGORITHM RtoAlgorithm | The retransmission time-out (RTO) algorithm in use. This member can be one of the values from the **TCP_RTO_ALGORITHM** enumeration type defined in the *Tcpmib.h* header file. The possible values are the same as those defined for the **dwRtoAlgorithm** member. |

In the Windows SDK, the version of the structure for use on Windows Vista and later is defined as **MIB_TCPSTATS_LH**. In the Windows SDK, the version of this structure to be used on earlier systems including Windows 2000 and later is defined as **MIB_TCPSTATS_W2K**. When compiling an application if the target platform is Windows Vista and later (`NTDDI_VERSION >= NTDDI_LONGHORN`, `_WIN32_WINNT >= 0x0600`, or `WINVER >= 0x0600`), the **MIB_TCPSTATS_LH** structure is typedefed to the **MIB_TCPSTATS** structure. When compiling an application if the target platform is not Windows Vista and later, the **MIB_TCPSTATS_W2K** structure is typedefed to the **MIB_TCPSTATS** structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Tcpmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetTcpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcpstatistics)

[GetUdpStatistics](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getudpstatistics)

[MIB_UDPSTATS](https://learn.microsoft.com/windows/desktop/api/udpmib/ns-udpmib-mib_udpstats)