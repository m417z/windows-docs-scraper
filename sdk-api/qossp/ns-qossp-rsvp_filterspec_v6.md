# RSVP_FILTERSPEC_V6 structure

## Description

The **RSVP_FILTERSPEC_V6** structure stores information for a FILTERSPEC on an IPv6 address.

## Members

### `Address`

IPv4 address for which the FILTERSPEC applies, expressed as an [IN_ADDR_IPV6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv6) structure.

### `UnUsed`

### `Port`

TCP port of the socket on which the FILTERSPEC applies.

### `Unused`

Reserved. Set to zero.

## Remarks

When working with IPv4 addresses, use [RSVP_FILTERSPEC_V4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4).

## See also

[IN_ADDR_IPV6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv6)

[RSVP_FILTERSPEC_V4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4)