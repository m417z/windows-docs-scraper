# TdhDeletePayloadFilter function

## Description

The **TdhDeletePayloadFilter** function frees the memory allocated for a single payload filter by the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function.

## Parameters

### `PayloadFilter` [in, out]

A pointer to a single payload filter allocated by the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function.

## Return value

Returns **ERROR_SUCCESS** if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |

## Remarks

On Windows 8.1,Windows Server 2012 R2, and later, event payload filters can be used by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function to filter on the specific content of the event in a logger session.

The **TdhDeletePayloadFilter** function is used to free memory allocated for a single payload filter that is returned by the [TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter) function.

## See also
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)

[TdhCleanupPayloadEventFilterDescriptor](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcleanuppayloadeventfilterdescriptor)

[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter)