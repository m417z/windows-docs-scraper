# RSVP_FILTERSPEC structure

## Description

The **RSVP_FILTERSPEC** structure provides RSVP FILTERSPEC information.

## Members

### `Type`

Specifies the type of FILTERSPEC using the **FilterSpec** enumeration.

### `FilterSpecV4`

IPv4 FILTERSPEC information, provided in the form of a [RSVP_FILTERSPEC_V4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4) structure.

### `FilterSpecV6`

IPv6 FILTERSPEC information, provided in the form of a [RSVP_FILTERSPEC_V6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6) structure.

### `FilterSpecV6Flow`

IPv6 FILTERSPEC flow information, provided in the form of a [RSVP_FILTERSPEC_V6_FLOW](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_flow) structure.

### `FilterSpecV4Gpi`

IPv4 FILTERSPEC general port ID information, provided in the form of a [RSVP_FILTERSPEC_V4_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4_gpi) structure.

### `FilterSpecV6Gpi`

IPv6 FILTERSPEC general port ID information, provided in the form of a [RSVP_FILTERSPEC_V6_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_gpi) structure.

## See also

[RSVP_FILTERSPEC_V4](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4)

[RSVP_FILTERSPEC_V4_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v4_gpi)

[RSVP_FILTERSPEC_V6](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6)

[RSVP_FILTERSPEC_V6_FLOW](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_flow)

[RSVP_FILTERSPEC_V6_GPI](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec_v6_gpi)