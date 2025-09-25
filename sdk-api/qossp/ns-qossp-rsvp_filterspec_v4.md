# RSVP_FILTERSPEC_V4 structure

## Description

The **RSVP_FILTERSPEC_V4** structure stores information for a FILTERSPEC on an IPv4 address.

## Members

### `Address`

IPv4 address for which the FILTERSPEC applies, expressed as an [IN_ADDR_IPV4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv4) union.

### `Unused`

Reserved. Set to zero.

### `Port`

TCP port of the socket on which the FILTERSPEC applies.

## Remarks

When working with IPv6 addresses, use [RSVP_FILTERSPEC_V6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6).

## See also

[IN_ADDR_IPV4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv4)

[RSVP_FILTERSPEC_V6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6)