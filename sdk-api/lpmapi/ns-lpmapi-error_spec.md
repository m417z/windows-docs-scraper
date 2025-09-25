# ERROR_SPEC structure

## Description

The
**ERROR_SPEC** structure contains RSVP error messages.

## Members

### `errs_header`

Error header, in the form of an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `errs_u`

Union containing RSVP error information.

#### errs_ipv4

Error information, expressed as an [Error_Spec_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-error_spec_ipv4) structure.

### `errs_ipv4`

## See also

[Error_Spec_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-error_spec_ipv4)

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)