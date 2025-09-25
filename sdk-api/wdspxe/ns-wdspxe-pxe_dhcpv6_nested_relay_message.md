# PXE_DHCPV6_NESTED_RELAY_MESSAGE structure

## Description

Describes packets nested in OPTION_RELAY_MSG message.

For more information about OPTION_RELAY_MSG and RELAY-FORW messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Members

### `pRelayMessage`

A pointer to the nested RELAY-FORW message.

### `cbRelayMessage`

A pointer to the size of the nested RELAY-FORW message.

### `pInterfaceIdOption`

If the nested RELAY-FORW message contains **OPTION_INTERFACE_ID**, this is a pointer to the option payload. Otherwise, this field will be **NULL**.

### `cbInterfaceIdOption`

If the nested RELAY-FORW message contains **OPTION_INTERFACE_ID**, this is the size of the option payload.
Otherwise, this field will be 0.