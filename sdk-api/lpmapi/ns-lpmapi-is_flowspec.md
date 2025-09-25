# IS_FLOWSPEC structure

## Description

The
**IS_FLOWSPEC** structure stores an Integrated Services FLOWSPEC object.

## Members

### `flow_header`

General information and length information for the Integrated Services flowspec object (this structure), expressed as an [RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr) structure.

### `flow_body`

FLOWSPEC object data, expressed as an [IntServFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservflowspec) structure.

## See also

[IntServFlowSpec](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-intservflowspec)

[RsvpObjHdr](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-rsvpobjhdr)