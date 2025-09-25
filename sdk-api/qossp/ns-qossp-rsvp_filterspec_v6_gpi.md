# RSVP_FILTERSPEC_V6_GPI structure

## Description

The **RSVP_FILTERSPEC_V6_GPI** structure provides general port identifier information for a given FILTERSPEC on an IPv6 address.

## Members

### `Address`

IPv4 address for which the FILTERSPEC general port identifier applies, expressed as an [IN_ADDR_IPV6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv6) structure.

### `GeneralPortId`

General Port Identifier for the FILTERSPEC.

## Remarks

When working with IPv4 addresses, use [RSVP_FILTERSPEC_V4_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4_gpi).

## See also

[IN_ADDR_IPV6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv6)

[RSVP_FILTERSPEC_V4_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4_gpi)