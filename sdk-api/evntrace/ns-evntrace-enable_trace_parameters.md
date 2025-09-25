# ENABLE_TRACE_PARAMETERS structure

## Description

The **ENABLE_TRACE_PARAMETERS** structure contains information used to enable a
provider via
[EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2).

## Members

### `Version`

Set to **ENABLE_TRACE_PARAMETERS_VERSION_2** (2).

### `EnableProperty`

Optional settings that ETW can include when writing the event. Some settings
write extra data to the
[extended data item](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)
section of each event. Other settings control which events will be included in
the trace. To use these optional settings, specify one or more of the following
flags. Otherwise, set to zero.

- **EVENT_ENABLE_PROPERTY_IGNORE_KEYWORD_0**

 Filters out events where the event's keyword is `0`.

 Supported on Windows 10, version 1507 and later. This is also supported on
Windows 8.1 and Windows 7 with SP1 via a patch.

- **EVENT_ENABLE_PROPERTY_PROVIDER_GROUP**

 Indicates that this call to
[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) should enable a
[Provider Group](https://learn.microsoft.com/windows/desktop/ETW/provider-traits) rather than an
individual Event Provider.

 Supported on Windows 10, version 1507 and later. This is also supported on
Windows 8.1 and Windows 7 with SP1 via a patch.

- **EVENT_ENABLE_PROPERTY_PROCESS_START_KEY**

 Include the Process Start Key in the extended data.

 The Process Start Key is a sequence number that identifies the process. While
the Process ID may be reused within a session, the Process Start Key is
guaranteed to be unique in the current boot session.

 Supported on Windows 10, version 1507 and later. This is also supported on
Windows 8.1 and Windows 7 with SP1 via a patch.

- **EVENT_ENABLE_PROPERTY_EVENT_KEY**

 Include the Event Key in the extended data.

 The Event Key is a unique identifier for the event instance that will be
constant across multiple trace sessions listening to this event. It can be
used to correlate simultaneous trace sessions.

 Supported on Windows 10, version 1507 and later.

- **EVENT_ENABLE_PROPERTY_EXCLUDE_INPRIVATE**

 Filters out all events that are either marked as an InPrivate event or come
from a process that is marked as InPrivate.

 InPrivate implies that the event or process contains some data that would be
considered private or personal. It is up to the process or event to designate
itself as InPrivate for this to work.

 Supported on Windows 10, version 1507 and later.

- **EVENT_ENABLE_PROPERTY_SID**

 Include the security identifier (SID) of the user in the event's extended
data.

 Supported on Windows Vista and later.

- **EVENT_ENABLE_PROPERTY_TS_ID**

 Include the terminal session identifier in the event's extended data.

 Supported on Windows Vista and later.

- **EVENT_ENABLE_PROPERTY_STACK_TRACE**

 Add a call stack trace to the extended data of events written using
[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite).

 > [!Note]
> ETW will drop the event if the total event size exceeds 64K. If the
> provider is logging events close in size to 64K maximum, it is possible that
> enabling stack capture will cause the event to be lost.

 If the stack is longer than the maximum number of frames (192), the frames
will be cut from the bottom of the stack.

 For consumers, the events will include the
[EVENT_EXTENDED_ITEM_STACK_TRACE32](https://learn.microsoft.com/windows/win32/api/evntcons/ns-evntcons-event_extended_item_stack_trace64)
or
[EVENT_EXTENDED_ITEM_STACK_TRACE64](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_extended_item_stack_trace64)
extended item. Note that on 64-bit computers, the trace will contain both
64-bit stacks even if the trace was started by a 32-bit trace controller.

 Supported on Windows 7 and later.

### `ControlFlags`

Reserved. Set to 0.

### `SourceId`

A GUID that uniquely identifies the caller that is enabling or disabling the
provider. If the provider does not implement
[EnableCallback](https://learn.microsoft.com/windows/desktop/api/evntprov/nc-evntprov-penablecallback), the
GUID is not used.

### `EnableFilterDesc`

A pointer to an array of
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structures that points to the filter data. The number of elements in the array
is specified in the **FilterDescCount** member. There can only be one descriptor
for each filter type as specified by the **Type** member of the
**EVENT_FILTER_DESCRIPTOR** structure.

### `FilterDescCount`

The number of elements (filters) in the
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
array pointed to by **EnableFilterDesc** member.

The **FilterDescCount** member should match the number of
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structures in the array pointed to by the **EnableFilterDesc** member.

## Remarks

The **ENABLE_TRACE_PARAMETERS** structure is a version-2 structure and replaces
the
[ENABLE_TRACE_PARAMETERS_V1](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters-v1)
structure.

**Windows 8.1, Windows Server 2012 R2, and later:** Event payload, scope, and
stack walk filters can be used by the
[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2) function and the
**ENABLE_TRACE_PARAMETERS** and
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structures to filter on specific conditions in a logger session. For more
information on event payload filters, see the **EnableTraceEx2**,
[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter),
and
[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)
functions and the **EVENT_FILTER_DESCRIPTOR** and
[PAYLOAD_FILTER_PREDICATE](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-payload_filter_predicate)
structures.

Typically, on 64-bit computers, you cannot capture the kernel stack in certain
contexts when page faults are not allowed. To enable walking the kernel stack on
x64, set the `DisablePagingExecutive` Memory Management registry value to 1. The
`DisablePagingExecutive` registry value is located under the following registry
key:
`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management`.
This should only be done for temporary diagnosis purposes because it increases
memory usage of the system.

## See also

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EVENT_FILTER_EVENT_ID](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_event_id)

[PAYLOAD_FILTER_PREDICATE](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-payload_filter_predicate)

[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2)

[TdhAggregatePayloadFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhaggregatepayloadfilters)

[TdhCreatePayloadFilter](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhcreatepayloadfilter)

[TdhEnumerateProviderFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfilters)