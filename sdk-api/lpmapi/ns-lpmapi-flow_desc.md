# FLOW_DESC structure

## Description

The
**FLOW_DESC** structure contains flow descriptor information for RSVP.

## Members

### `u1`

Union of Tspec and flowspec information.

### `u1.stspec`

Sender Tspec, expressed as a [SENDER_TSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-sender_tspec) structure.

### `u1.isflow`

Integrated Services flowspec information, expressed as an [IS_FLOWSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-is_flowspec) structure.

### `u2`

Union of sender and filterspec information.

### `u2.stemp`

Sender template for the flow, expressed as a [FILTER_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec) structure.

### `u2.fspec`

Filter spec for the flow, expressed as a [FILTER_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec) structure.

## See also

[FILTER_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-filter_spec)

[IS_FLOWSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-is_flowspec)

[SENDER_TSPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-sender_tspec)