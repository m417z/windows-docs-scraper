# LPDHCP_NEWPKT callback function

## Description

The
**DhcpNewPktHook** function is called by Microsoft DHCP Server shortly after it receives a DHCP packet slated for processing. Since the
**DhcpNewPktHook** function call is in the critical path for Microsoft DHCP Server processing, this function should execute and return as quickly as possible or performance will be impacted.

The
**DhcpNewPktHook** function is implemented by a third-party DLL that registers for notification of significant Microsoft DHCP Server events.

## Parameters

### `Packet` [in, out]

Pointer to a 4Kb character buffer that contains the packet.

**Note** Writing to this buffer directly is not recommended.

### `PacketSize` [in, out]

Pointer to the size of the *Packet* parameter.

### `IpAddress` [in]

Pointer to the IP address of the socket on which the packet was received. The IP address is in host order.

### `Reserved` [in]

Reserved for future use.

### `PktContext` [in, out]

Pointer provided by the third-party DLL, and used by Microsoft DHCP Server in future references to this specific packet. Third-party DLLs interested in such tracking are responsible for providing and tracking this packet context.

### `ProcessIt` [out]

Flag identifying whether Microsoft DHCP Server should continue processing the packet. Set to **TRUE** to indicate processing should proceed. Set to **FALSE** to have Microsoft DHCP Server drop the packet.

## Return value

Return values are defined by the application providing the callback.

## Remarks

If useful, third-party DLLs can modify the *Packet* buffer, or return a new packet buffer through appropriate modification of the *Packet* and *PacketSize* parameters.

If a third-party DLL needs to keep track of a given packet and its progress through Microsoft DHCP Server, it can provide a packet context in *PktContext*, and use internal structures that track the packet's progress through its DHCP processing. A context provided in *PktContext* will be passed as a parameter to many other DHCP Server API functions, enabling identification.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DhcpServerCalloutEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_entry_point_func)

[How the
DHCP Server API Operates](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/how-the-dhcp-server-api-operates)