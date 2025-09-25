# MOF_FIELD structure

## Description

You may use the **MOF_FIELD** structures to append event data to the
[EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_header)
or
[EVENT_INSTANCE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_instance_header)
structures.

## Members

### `DataPtr`

Pointer to a event data item.

### `Length`

Length of the item pointed to by **DataPtr**, in bytes.

### `DataType`

Reserved.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

If you use **MOF_FIELD** structures, you must set the **WNODE_FLAG_USE_MOF_PTR**
flag in the **Flags** member of the
[EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_header)
or
[EVENT_INSTANCE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_instance_header)
structures.

The event tracing session automatically dereferences **MOF_FIELD** data pointers
before passing the data to event trace consumers using
[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace) structures.

## See also

[EVENT_INSTANCE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_instance_header)

[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace)

[EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_header)