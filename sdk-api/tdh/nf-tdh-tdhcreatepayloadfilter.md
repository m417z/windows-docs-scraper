# TdhCreatePayloadFilter function

## Description

The **TdhCreatePayloadFilter** function creates a single filter for a single payload to be used with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## Parameters

### `ProviderGuid` [in]

A GUID that identifies the manifest provider of the *EventDescriptor* parameter.

### `EventDescriptor` [in]

A pointer to the event descriptor whose payload will be filtered.

### `EventMatchANY` [in]

A Boolean value that indicates how events are handled when multiple conditions are specified.

When this parameter is **TRUE**, an event will be written to a session if any of
the specified conditions specified in the filter are **TRUE**.

When this parameter is **FALSE**, an event will be written to a session only if all of
the specified conditions specified in the filter are **TRUE**.

### `PayloadPredicateCount` [in]

The number of conditions specified in the filter.
This value must be less than or equal to the **ETW_MAX_PAYLOAD_PREDICATES** constant defined in the *Tdh.h* header file.

### `PayloadPredicates` [in]

A pointer to an array of [PAYLOAD_FILTER_PREDICATE](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-payload_filter_predicate) structures that contain the list conditions that the filter specifies.

### `PayloadFilter` [out]

On success, this parameter returns a pointer to a single payload filter that is properly sized and built for the specified conditions.

When the caller is finished using the returned payload filter with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function, the [TdhDeletePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhdeletepayloadfilter) function should be called to free the allocated memory.

## Return value

Returns **ERROR_SUCCESS** if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The metadata for the provider was not found. |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_INSUFFICIENT_BUFFER** | The resulting payload filter would not fit within the **MAX_EVENT_FILTER_PAYLOAD_SIZE** limit imposed by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function on the [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structures in a payload. |
| **ERROR_NOT_ENOUGH_MEMORY** | Unable to allocate memory to create the payload filter. |
| **ERROR_NOT_FOUND** | The schema information for supplied provider GUID was not found. |

## Remarks

On Windows 8.1,Windows Server 2012 R2, and later, event payload filters can be used by the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function to filter on the specific content of event in a logger session.

The **TdhCreatePayloadFilter** function is used to create a single payload filter for a single payload to be used with the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function. The **TdhCreatePayloadFilter** allocates and fills in an opaque data structure for a single payload filter. When the payload filter is no longer needed, the [TdhDeletePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhdeletepayloadfilter) function is used to free memory allocated for a payload filter.

For a single provider, multiple events can have distinct payload filters. There can also be multiple filters for the same event, with a payload being passed to the session if any or all of the event's filters pass it.

The [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function takes an array of [EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor) structures in the [ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters) structures passed in the *EnableParameters* parameter. There can only be one entry in the array for each event filter type. The [TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters) function can be used to aggregate a list of payload filters for a single provider created using the **TdhCreatePayloadFilter** into a single data structure and return an **EVENT_FILTER_DESCRIPTOR** for use with the **EnableTraceEx2** function.

#### Examples

For an example that uses
the **TdhCreatePayloadFilter** function to create payload filters to use in filtering on specific conditions in a logger session, see
the example for the [EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function.

## See also
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters)

[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[PAYLOAD_FILTER_PREDICATE](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-payload_filter_predicate)

[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)

[TdhCleanupPayloadEventFilterDescriptor](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcleanuppayloadeventfilterdescriptor)

[TdhDeletePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhdeletepayloadfilter)