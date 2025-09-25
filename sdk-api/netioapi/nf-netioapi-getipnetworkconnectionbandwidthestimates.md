# GetIpNetworkConnectionBandwidthEstimates function

## Description

The
**GetIpNetworkConnectionBandwidthEstimates** function retrieves historical bandwidth estimates for a network connection on the specified interface.

## Parameters

### `InterfaceIndex` [in]

The local index value for the network interface.

This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `AddressFamily` [in]

The address family. Possible values for the address family are listed in the *Ws2def.h* header file. Note that the values for the AF_ address family and PF_ protocol family constants are identical (for example, **AF_INET** and **PF_INET**), so either constant can be used.

 Note that the *Ws2def.h* header file is automatically included in *Winsock2.h*, and should never be used directly.

The values currently supported are **AF_INET** or **AF_INET6**, which are the Internet
address family formats for IPv4 and IPv6.

| Value | Meaning |
| --- | --- |
| **AF_INET**<br><br>2 | The Internet Protocol version 4 (IPv4) address family. |
| **AF_INET6**<br><br>23 | The Internet Protocol version 6 (IPv6) address family. |

### `BandwidthEstimates` [out]

A pointer to a buffer that returns the historical bandwidth estimates maintained for the point of attachment to which the interface is currently connected.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the file specified. This error is returned if the interface index specified by the *InterfaceIndex* parameter was not a value on the local machine. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *BandwidthEstimates* parameter or the *AddressFamily* parameter was not specified as **AF_INET** or **AF_INET6**. |
| **ERROR_NOT_FOUND** | Element not found. This error is returned if the network interface specified by the *InterfaceIndex* parameter does not match the IP address family specified in the *AddressFamily* parameter. |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

The **GetIpNetworkConnectionBandwidthEstimates** function is defined on Windows 8 and later.

On input, the *AddressFamily* parameter must be initialized to either **AF_INET** or **AF_INET6**. In addition on input, the *InterfaceIndex* parameter must be initialized with the specified interface index.

A value must be set for the *InterfaceIndex* parameter (the value of this parameter must not be set to zero).

On output, the [MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-mib_ip_network_connection_bandwidth_estimates) structure pointed to by the *BandwidthEstimates* parameter is filled in if the *AddressFamily* and *InterfaceIndex* parameters were specified.

The **GetIpNetworkConnectionBandwidthEstimates** function returns historical estimates of available bandwidth at the point of attachment (the first hop) for use by an application. The estimates are intended as a guide to tune performance parameters and the application should maintain thresholds and differentiate behavior for low and high bandwidth situations.

It is possible that the true available bandwidth changes over time as more bandwidth is consumed by devices competing on the same network. So applications should be prepared to handle cases where the available bandwidth drops below historical limits reported by the **GetIpNetworkConnectionBandwidthEstimates** function.

It is possible that the TCP/IP stack has not built up any estimates for the given interface, in a particular or both directions. In this case the estimate returned will be zero. The application should be prepared to handle such cases by picking reasonable defaults and fine tuning if required.

The *Netioapi.h* header file is automatically included by the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcp6connectionestats)

[GetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getpertcpconnectionestats)

[MIB_IP_NETWORK_CONNECTION_BANDWIDTH_ESTIMATES](https://learn.microsoft.com/windows/win32/api/netioapi/ns-netioapi-mib_ip_network_connection_bandwidth_estimates)

[NL_BANDWIDTH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/nldef/ns-nldef-nl_bandwidth_information)

[TCP_ESTATS_BANDWIDTH_ROD_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rod_v0)