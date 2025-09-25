# TdhAggregatePayloadFilters function

## Description

The **TdhAggregatePayloadFilters** function aggregates multiple payload filters for a single provider into a single data structure for use with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## Parameters

### `PayloadFilterCount`

The count of payload filters.

### `PayloadFilterPtrs`

An array of event payload single filters, each created by a call to the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function.

### `EventMatchALLFlags` [in, optional]

An array of Boolean values that correspond to each payload filter passed in the *PayloadFilterPtrs* parameter and indicates how events are handled when multiple conditions are specified.. This parameter only affects situations where multiple payload filters are being specified for the same event.

When a Boolean value is **TRUE**, an event will be written to a session if any of the specified conditions specified in the filter are **TRUE**. If this flag is set to **TRUE** on one or more filters for the same event Id or event version, then the event is only written if all the flagged filters for the event are satisfied.

When a Boolean value is **FALSE**, an event will be written to a session only if all of the specified conditions specified in the filter are **TRUE**. If this flag is set to **FALSE** on one or more filters for the same event Id or event version, then the event is written if any of the non-flagged filters are satisfied.

### `EventFilterDescriptor` [out]

A pointer to an [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structure to be used with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function. The **EVENT_FILTER_DESCRIPTOR** structure will contain a pointer to the aggregated payload filters, which have been allocated by this function.

When the caller is finished using this [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structure with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function, the [TdhCleanupPayloadEventFilterDescriptor](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcleanuppayloadeventfilterdescriptor) function should be called to free the allocated memory.

## Return value

Returns **ERROR_SUCCESS** if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Unable to allocate memory to create the aggregated payload filter. |

## Remarks

On Windows 8.1,Windows Server 2012 R2, and later, event payload filters can be used by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function to filter on the specific content of the event in a logger session.

The **TdhAggregatePayloadFilters** function aggregates payload filters for a single provider into a single data structure for use with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function. The **TdhAggregatePayloadFilters** allocates and fills in an opaque data structure for an aggregated payload filter. When the aggregated payload filter is no longer needed, the [TdhCleanupPayloadEventFilterDescriptor](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcleanuppayloadeventfilterdescriptor) function is used to free memory allocated for the aggregated payload filter in the [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structure returned.

#### Examples

For an example that uses
the **TdhAggregatePayloadFilters** function to aggregate payload filters to use in filtering on specific conditions in a logger session, see
the example for the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## See also
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[TdhCleanupPayloadEventFilterDescriptor](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcleanuppayloadeventfilterdescriptor)

[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter)

[TdhDeletePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhdeletepayloadfilter)