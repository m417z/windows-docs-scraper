# PXE_DHCPV6_RELAY_MESSAGE structure

## Description

Provides the DHCPV6 relay message.

MessageType, HopCount, LinkAddress, and Options fields that are described by RFC 3315 section 7.

For more information about DHCPV6 message type, hop count, link address, and options, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Members

### `MessageType`

The message type

### `HopCount`

The hop count

### `LinkAddress`

The link address

### `PeerAddress`

The peer address

### `Options`

A [PXE_DHCPV6_OPTION](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_dhcpv6_option) structure and see RFC 3315 section 7.