# FILTER_SPEC structure

## Description

The
**FILTER_SPEC** structure stores information about an RSVP FILTERSPEC.

## Members

### `filt_header`

RSVP Object Header for the FILTERSPEC, in the form of an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `filt_u`

#### filt_ipv4

FILTERSPEC, in the form of a [Filter_Spec_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec_ipv4) header.

#### filt_ipv4gpi

FILTERSPEC GPI information, in the form of a [Filter_Spec_IPv4GPI](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec_ipv4gpi) header.

### `filt_ipv4`

### `filt_ipv4gpi`

## See also

[Filter_Spec_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec_ipv4)

[Filter_Spec_IPv4GPI](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec_ipv4gpi)

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)