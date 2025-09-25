# RSVP_SESSION structure

## Description

The
**RSVP_SESSION** structure stores information about an RSVP SESSION message.

## Members

### `sess_header`

RSVP Object Header, in the form of an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `sess_u`

#### sess_ipv4

Session information, in the form of a [Session_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-session_ipv4) structure.

### `sess_ipv4`

## See also

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)

[Session_IPv4](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-session_ipv4)