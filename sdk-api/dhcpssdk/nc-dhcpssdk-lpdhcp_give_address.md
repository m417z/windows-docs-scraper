# LPDHCP_GIVE_ADDRESS callback function

## Description

The
**DhcpAddressOfferHook** function is called by Microsoft DHCP Server directly before Microsoft DHCP Server sends an acknowledgment (ACK) to a DHCP REQUEST message. The
**DhcpAddressOfferHook** is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events.

The
**DhcpAddressOfferHook** function should not block.

## Parameters

### `Packet` [in]

Buffer for the packet being processed.

### `PacketSize` [in]

Size of the *Packet* parameter, in bytes.

### `ControlCode` [in]

Specifies the type of lease being approved. If the acknowledgment is for a new lease, *ControlCode* is DHCP_GIVE_ADDRESS_NEW. If the acknowledgment is for the renewal of an existing lease, *ControlCode* is DHCP_GIVE_ADDRESS_OLD.

### `IpAddress` [in]

Internet Protocol (IP) address of the socket on which the packet was received. The IP address is in host order.

### `AltAddress` [in]

Internet Protocol (IP) address being handed out in the lease.

### `AddrType` [in]

Specifies whether the address is a DHCP or BOOTP address. The default value is DHCP_CLIENT_DHCP.

| Value | Meaning |
| --- | --- |
| **DHCP_CLIENT_DHCP** | The address is a DHCP-served address. |
| **DHCP_CLIENT_BOOTP** | The address is a BOOTP-served address. |

### `LeaseTime` [in]

Lease duration being passed, in seconds.

### `Reserved` [in]

Reserve for future use.

### `PktContext` [in]

Context identifying the packet, as provided in the *PktContext* parameter of a previous
[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt) function call.

## Return value

Return values are defined by the application providing the callback.

## Remarks

Implementations of the
**DhcpAddressOfferHook** should not block.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt)