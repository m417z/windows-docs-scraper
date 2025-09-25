# TCP_BOOLEAN_OPTIONAL enumeration

## Description

The **TCP_BOOLEAN_OPTIONAL** enumeration defines the states that a caller can specify when updating a member in the read/write information for a TCP connection.

## Constants

### `TcpBoolOptDisabled:0`

The option should be disabled.

### `TcpBoolOptEnabled`

The option should be enabled.

### `TcpBoolOptUnchanged:-1`

The option should be unchanged.

## Remarks

The **TCP_BOOLEAN_OPTIONAL** enumeration is defined on Windows Vista and later.

The collection of extended statistics on a TCP connection are enabled and disabled using calls to the [SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats) and [SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats) functions where the type of extended statistics specified is one of values from the [TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type) enumeration type. A value from the **TCP_BOOLEAN_OPTIONAL** enumeration is used to specify how a member in the [TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0) structure should be updated to enable or disable extended statistics on a TCP connection for bandwidth estimation.

## See also

[SetPerTcp6ConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcp6connectionestats)

[SetPerTcpConnectionEStats](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setpertcpconnectionestats)

[TCP_ESTATS_BANDWIDTH_RW_v0](https://learn.microsoft.com/windows/desktop/api/tcpestats/ns-tcpestats-tcp_estats_bandwidth_rw_v0)

[TCP_ESTATS_TYPE](https://learn.microsoft.com/windows/desktop/api/tcpestats/ne-tcpestats-tcp_estats_type)