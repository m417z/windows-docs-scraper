# LPDHCP_HANDLE_OPTIONS callback function

## Description

The
*DhcpHandleOptionsHook* function enables third-party DLLs to obtain commonly used options from a DHCP packet, avoiding the need to process the entire DHCP packet. The
*DhcpHandleOptionsHook* function should not block.

## Parameters

### `Packet` [in]

Buffer for the packet being processed.

### `PacketSize` [in]

Size of the *Packet* parameter, in bytes.

### `Reserved` [in]

Reserve for future use.

### `PktContext` [in]

Context identifying the packet, as provided in the *PktContext* parameter of a previous
[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt) function call.

### `ServerOptions` [in, out]

Structure of type [DHCP_SERVER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_server_options) containing the information parsed from the packet by Microsoft DHCP Server, and provided as the collection of commonly used server options.

## Return value

Return values are defined by the application providing the callback.

## Remarks

The
*DhcpHandleOptionsHook* function is useful when developers of third-party DLLs want to avoid having to process an entire DHCP packet, and rather, could achieve the desired results by a set of commonly used server options. When third-party DLLs register for this event notification, the Microsoft DHCP Server parses the incoming packet, extracts commonly used server options, and passes them to the third-party DLL in the *ServerOptions* parameter.

If the [DHCP_SERVER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_server_options) structure pointed to in *ServerOptions* is needed beyond the completion of the
*DhcpHandleOptionsHook* function call, third-party DLLs must make a copy of the structure.

The
*DhcpHandleOptionsHook* function can be called multiple times for a single packet.

## See also

[DHCP_CALLOUT_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_callout_table)

[DHCP_SERVER_OPTIONS](https://learn.microsoft.com/windows/desktop/api/dhcpssdk/ns-dhcpssdk-dhcp_server_options)

[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt)