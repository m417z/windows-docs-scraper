# PXE_DHCPV6_MESSAGE structure

## Description

A DHCPV6 message.

For more information about the DHCPv6 messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Members

### `MessageType`

The DHCPv6 message type.

### `TransactionIDByte1`

Byte 1 of the transaction-id in the DHCPv6 message.

### `TransactionIDByte2`

Byte 2 of the transaction-id the DHCPv6 message.

### `TransactionIDByte3`

Byte 3 of the transaction-id DHCPv6 message.

### `Options`

A [PXE_DHCPV6_OPTION](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_dhcpv6_option) structure that specifies the DHCPV6 option.