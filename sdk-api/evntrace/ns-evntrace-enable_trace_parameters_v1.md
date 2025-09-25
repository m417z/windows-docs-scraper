# ENABLE_TRACE_PARAMETERS_V1 structure

## Description

The **ENABLE_TRACE_PARAMETERS_V1** structure contains information used to enable
a provider via
[EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2). This
structure is obsolete. Use
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/desktop/ETW/enable-trace-parameters) instead.

## Members

### `Version`

Set to **ENABLE_TRACE_PARAMETERS_VERSION** (1).

### `EnableProperty`

Optional information that ETW can include when writing the event. The data is
written to the
[extended data item](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)
section of the event. To include the optional information, specify one or more
of the following flags; otherwise, set to zero.

- **EVENT_ENABLE_PROPERTY_SID**

 Include in the extended data the security identifier (SID) of the user.

- **EVENT_ENABLE_PROPERTY_TS_ID**

 Include in the extended data the terminal session identifier.

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
extended item. Note that 32-bit consumers may receive 64-bit stack traces from
64-bit processes.

### `ControlFlags`

Reserved. Set to 0.

### `SourceId`

A GUID that uniquely identifies the caller that is enabling or disabling the
provider. If the provider does not implement
[EnableCallback](https://learn.microsoft.com/windows/desktop/api/evntprov/nc-evntprov-penablecallback), the
GUID is not used.

### `EnableFilterDesc`

An
[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)
structure that points to the filter data. The provider uses filter data to
prevent events that match the filter criteria from being written to the session.
The provider determines the layout of the data and how it applies the filter to
the event's data. A session can pass only one filter to the provider.

A session can call the
[TdhEnumerateProviderFilters](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfilters)
function to determine the schematized filters that it can pass to the provider.

## Remarks

**ENABLE_TRACE_PARAMETERS_V1** is obsolete. The
[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-enable_trace_parameters)
structure is a version 2 structure and replaces the
**ENABLE_TRACE_PARAMETERS_V1** structure.

Typically, on 64-bit computers, you cannot capture the kernel stack in certain
contexts when page faults are not allowed. To enable walking the kernel stack on
x64, set the `DisablePagingExecutive` Memory Management registry value to 1. The
`DisablePagingExecutive` registry value is located under the following registry
key:
`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management`.
This should only be done for temporary diagnosis purposes because it increases
memory usage of the system.

## See also

[ENABLE_TRACE_PARAMETERS](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-enable_trace_parameters)

[EVENT_FILTER_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_filter_descriptor)

[EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2)