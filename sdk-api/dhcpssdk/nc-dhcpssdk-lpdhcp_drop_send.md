# LPDHCP_DROP_SEND callback function

## Description

## Parameters

### `Packet` [in, out]

Pointer to a buffer, 4Kb in size, that contains the packet.

**Note** Writing to this buffer directly is not recommended.

### `PacketSize` [in, out]

Pointer to the size of the *Packet* parameter, in bytes.

### `ControlCode` [in]

Control code that specifies the reason for dropping. See Remarks.

### `IpAddress` [in]

Internet Protocol (IP) address of the socket on which the packet was received. The IP address is in host order.

### `Reserved` [in]

Reserved for future use.

### `PktContext` [in]

Context identifying the packet, as provided in the *PktContext* parameter of a previous
[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt) function call.

## Return value

Return values are defined by the application providing the callback.

## Remarks

The
**DhcpPktDropHook** function is called by Microsoft DHCP Server when a DHCP packet is dropped, or a packet is completely processed. The
**DhcpPktDropHook** is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events.

The
**DhcpPktDropHook** function should not block.

Third-party DLLs that register for notification of this event should be prepared to have their
**DhcpPktDropHook** function called multiple times for each packet. If a packet is dropped by Microsoft DHCP Server, this function is called twice for that packet: once to notify that the packet was dropped, and again to identify that the packet was completely processed.

The following table defines the possible control codes returned in the *ControlCode* parameter.

| Control code | Description |
| --- | --- |
| DHCP_DROP_DUPLICATE | The packet is a duplicate of another received by the DHCP server. |
| DHCP_DROP_NOMEM | There is not enough memory available to process the packet. |
| DHCP_DROP_INTERNAL_ERROR | An unexpected internal error has occurred. |
| DHCP_DROP_TIMEOUT | The packet is too old to process. |
| DHCP_DROP_UNAUTH | The server is not authorized to process this packet. |
| DHCP_DROP_PAUSED | The server is paused. |
| DHCP_DROP_NO_SUBNETS | There are no subnets configured, therefore there is no point in processing the packet. |
| DHCP_DROP_INVALID | The packet is invalid, or it was received on an invalid socket. |
| DHCP_DROP_WRONG_SERVER | The packet was sent to the wrong DHCP Server. |
| DHCP_DROP_NOADDRESS | There is no address to offer. |
| DHCP_DROP_PROCESSED | The packet has been processed. |
| DHCP_DROP_GEN_FAILURE | An unknown error has occurred. |

The
**DhcpPktSendHook** function is called by Microsoft DHCP Server directly before Microsoft DHCP Server sends a response to a client. Registering for notification of
**DhcpPktSendHook** enables third-party developers to alter the response of the Microsoft DHCP Server by manipulation of the packet pointers. The
**DhcpPktSendHook** is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events.

The
**DhcpPktSendHook** function should not block.

The
**DhcpPktSendHook** function should not block.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt)