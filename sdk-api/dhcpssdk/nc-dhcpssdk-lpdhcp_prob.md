# LPDHCP_PROB callback function

## Description

The
**DhcpAddressDelHook** function is called by Microsoft DHCP Server when one of the following four defined events occurs:

* DHCP_PROB_CONFLICT
* DHCP_PROB_DECLINE
* DHCP_PROB_RELEASE
* DHCP_PROB_NACKED

See Remarks for more information on these events. The
**DhcpAddressDelHook** function is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events. The
**DhcpAddressDelHook** function should not block.

## Parameters

### `Packet` [in]

Buffer for the packet being processed.

### `PacketSize` [in]

Size of the *Packet* parameter, in bytes.

### `ControlCode` [in]

Specifies the event. See Remarks for control code definitions.

### `IpAddress` [in]

Internet Protocol (IP) address of the socket on which the packet was received. The IP address is in host order.

### `AltAddress` [in]

Internet Protocol (IP) address used to provide additional information about the event. The meaning of *AltAddress* varies based on the value of *ControlCode*. See Remarks.

### `Reserved` [in]

Reserve for future use.

### `PktContext` [in]

Context identifying the packet, as provided in the *PktContext* parameter of a previous
[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt) function call.

## Return value

Return values are defined by the application providing the callback.

## Remarks

The following table defines the four defined events that trigger Microsoft DHCP Server to call the
**DhcpAddressDelHook** function in a third-party DLL.

| Control code | Description |
| --- | --- |
| DHCP_PROB_CONFLICT | The address attempted to be offered, as provided in *AltAddress*, is already in use on the network. |
| DHCP_PROB_DECLINE | The packet was a DECLINE message for the address specified in *AltAddress*. |
| DHCP_PROB_RELEASE | The packet was a RELEASE message for the address specified in *AltAddress*. |
| DHCP_PROB_NACKED | The packet was a REQUEST message for the address specified in *AltAddress*, and the request was declined by Microsoft DHCP Server. |

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt)