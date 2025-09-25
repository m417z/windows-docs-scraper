# PXE_DHCPV6_MESSAGE_HEADER structure

## Description

Describes the fields in common between the [PXE_DHCPV6_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_dhcpv6_message) and [PXE_DHCPV6_RELAY_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_dhcpv6_relay_message) structures.

For more information about the DHCPv6 messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Members

### `MessageType`

The DHCPv6 Message Type.

### `Message`

The remainder of the packet which must be interpreted differently based on the **MessageType**.