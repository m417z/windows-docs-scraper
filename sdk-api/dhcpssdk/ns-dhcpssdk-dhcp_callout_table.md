# DHCP_CALLOUT_TABLE structure

## Description

The
**DHCP_CALLOUT_TABLE** structure is used by Microsoft DHCP Server and third-party DLLs to send notification requests for DHCP Server events.

## Members

### `DhcpControlHook`

Pointer to a
[DhcpControlHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_control) function, implemented in a third-party DLL, to be called when Microsoft DHCP Server is started, stopped, paused, or continued. Set to **NULL** if notification is not required.

### `DhcpNewPktHook`

Pointer to a
[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt) function, implemented in a third-party DLL, to be called when Microsoft DHCP Server receives a packet that it attempts to process. Set to **NULL** if notification is not required.

### `DhcpPktDropHook`

Pointer to a
[DhcpPktDropHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_drop_send) function, implemented in a third-party DLL, to be called when Microsoft DHCP Server drops a packet, and when a packet is completely processed by Microsoft DHCP Server. Set to **NULL** if notification is not required.

### `DhcpPktSendHook`

Pointer to a
[DhcpPktSendHook](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363294(v=vs.85)) function, implemented in a third-party DLL, to be called directly before Microsoft DHCP Server submits a response to a client inquiry. Set to **NULL** if notification is not required.

### `DhcpAddressDelHook`

Pointer to a
[DhcpAddressDelHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_prob) function, implemented in a third-party DLL, to be called when a specified event in Microsoft DHCP Server results in a packet being dropped. Set to **NULL** if notification is not required.

### `DhcpAddressOfferHook`

Pointer to a
[DhcpAddressOfferHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_give_address) function, implemented in a third-party DLL, to be called directly before Microsoft DHCP Server submits a DHCP ACK message in response to a DHCP REQUEST message. Set to **NULL** if notification is not required.

### `DhcpHandleOptionsHook`

Pointer to a
[DhcpHandleOptionsHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_handle_options) function, implemented in a third-party DLL, that sends only parsed DHCP information to the third-party DLL, enabling the third-party DLL to avoid processing the entire DHCP packet. Set to **NULL** if notification is not required.

### `DhcpDeleteClientHook`

Pointer to a
[DhcpDeleteClientHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_delete_client) function, implemented in a third-party DLL, to be called directly before Microsoft DHCP Server deletes a client lease from its active leases database. Set to **NULL** if notification is not required.

### `DhcpExtensionHook`

Reserved for future use.

### `DhcpReservedHook`

Reserved for future use.

## Remarks

It is not necessary to implement all hooks available from Microsoft DHCP Server. If notification for a particular event is not required, set the member to **NULL**. Remember, however, that the initially loaded third-party DLL is responsible for loading subsequent third-party DLLs, and that subsequent DLLs may require notification of events that otherwise would be **NULL**, resulting in a non-**NULL** setting for members used by chained third-party DLLs that would otherwise be unused.

## See also

[Chaining Multiple Third-Party DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/chaining-multiple-third-party-dlls)

[DhcpAddressDelHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_prob)

[DhcpAddressOfferHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_give_address)

[DhcpControlHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_control)

[DhcpDeleteClientHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_delete_client)

[DhcpHandleOptionsHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_handle_options)

[DhcpNewPktHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_newpkt)

[DhcpPktDropHook](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_drop_send)

[DhcpPktSendHook](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa363294(v=vs.85))

[DhcpServerCalloutEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpssdk/nc-dhcpssdk-lpdhcp_entry_point_func)