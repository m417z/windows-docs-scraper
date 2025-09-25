# RSVP_SCOPE structure

## Description

The
**RSVP_SCOPE** structure provides RSVP scope information.

## Members

### `scopl_header`

Scope header, in the form of an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `scope_u`

Union containing scope list information.

#### scopl_ipv4

RSVP scope list, in the form of a [Scope_list_ipv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-scope_list_ipv4) structure.

### `scopl_ipv4`

## See also

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)

[Scope_list_ipv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-scope_list_ipv4)