# FLOWDESCRIPTOR structure

## Description

The **FLOWDESCRIPTOR** structure specifies one or more filters for a given FLOWSPEC.

## Members

### `FlowSpec`

Flow specification (FLOWSPEC), provided as a [FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec) structure.

### `NumFilters`

Number of filters provided in **FilterList**.

### `FilterList`

Pointer to a [RSVP_FILTERSPEC](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec) structure containing FILTERSPEC information.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)

[RSVP_FILTERSPEC](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-rsvp_filterspec)