# RSVP_FILTERSPEC_V4_GPI structure

## Description

The **RSVP_FILTERSPEC_V4_GPI** structure provides general port identifier information for a given FILTERSPEC.

## Members

### `Address`

IPv4 address for which the FILTERSPEC general port identifier applies, expressed as an [IN_ADDR_IPV4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv4) union.

### `GeneralPortId`

General Port Identifier for the FILTERSPEC.

## Remarks

When working with IPv6 addresses, use [RSVP_FILTERSPEC_V6_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_gpi).

## See also

[IN_ADDR_IPV4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-in_addr_ipv4)

[RSVP_FILTERSPEC_V6_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_gpi)