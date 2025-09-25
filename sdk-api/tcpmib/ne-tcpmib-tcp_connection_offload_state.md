# TCP_CONNECTION_OFFLOAD_STATE enumeration

## Description

The **TCP_CONNECTION_OFFLOAD_STATE** enumeration defines the possible TCP offload states for a TCP connection.

## Constants

### `TcpConnectionOffloadStateInHost`

The TCP connection is currently owned by the network stack on the local computer, and is not offloaded

### `TcpConnectionOffloadStateOffloading`

The TCP connection is in the process of being offloaded, but the offload has not been completed.

### `TcpConnectionOffloadStateOffloaded`

The TCP connection is offloaded to the network interface controller.

### `TcpConnectionOffloadStateUploading`

The TCP connection is in the process of being uploaded back to the network stack on the local computer, but the reinstate-to-host process has not completed.

### `TcpConnectionOffloadStateMax`

The maximum possible value for the [TCP_CONNECTION_OFFLOAD_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/tcpmib/ne-tcpmib-tcp_connection_offload_state) enumeration type. This is not a legal value for the possible TCP connection offload state.

## Remarks

The **TCP_CONNECTION_OFFLOAD_STATE** enumeration is defined on Windows Server 2003 and later.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **TCP_CONNECTION_OFFLOAD_STATE** enumeration is defined in the *Tcpmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Tcpmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Tcpmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetTcp6Table](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table)

[GetTcp6Table2](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-gettcp6table2)

[MIB_TCP6ROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6row2)

[MIB_TCP6TABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcp6table2)

[MIB_TCPROW2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow2)

[MIB_TCPTABLE2](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcptable2)