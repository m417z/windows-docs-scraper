# TdhCleanupPayloadEventFilterDescriptor function

## Description

The **TdhCleanupPayloadEventFilterDescriptor** function frees the aggregated structure of payload filters created using the [TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters) function.

## Parameters

### `EventFilterDescriptor` [in, out]

A pointer to an [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structure that contains aggregated filters where the allocated memory is to be freed. The **EVENT_FILTER_DESCRIPTOR** structure passed was created by calling the [TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters) function.

If the call is successful, allocated memory is released for the aggregated filters and the fields in the returned [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structure are re-initialized

## Return value

Returns **ERROR_SUCCESS** if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |

## Remarks

On Windows 8.1,Windows Server 2012 R2, and later, event payload filters can be used by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function to filter on specific content of the event in a logger session.

The **TdhCleanupPayloadEventFilterDescriptor** function is used to free memory allocated that is returned by the [TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters) function.

#### Examples

For an example that uses
the **TdhCleanupPayloadEventFilterDescriptor** function to free memory used by aggregate payload filters, see
the example for the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## See also
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)

[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter)

[TdhDeletePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhdeletepayloadfilter)