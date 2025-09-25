# EVENT_FILTER_EVENT_ID structure

## Description

The **EVENT_FILTER_EVENT_ID** structure defines event IDs used in an
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structure for an event ID or stack walk filter.

## Members

### `FilterIn`

A value that indicates whether filtering should be enabled or disabled for the
event IDs passed in the **Events** member.

When this member is **TRUE**, filtering is enabled for the specified event IDs.
When this member is **FALSE**, filtering is disabled for the event IDs.

### `Reserved`

A reserved value.

### `Count`

The number of event IDs in the **Events** member.

### `Events`

An array of event IDs.

## Remarks

The **EVENT_FILTER_EVENT_ID** structure is used in the
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structure when the **Type** member of the **EVENT_FILTER_DESCRIPTOR** is set to
**EVENT_FILTER_TYPE_EVENT_ID** or **EVENT_FILTER_TYPE_STACKWALK**. This
corresponds to an event ID filter (one of the possible scope filters) or a stack
walk filter. The **EVENT_FILTER_EVENT_ID** structure contains an array of event
IDs and a Boolean value that indicates if filtering is enabled or disabled for
the specified event IDs.

## See also

[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)