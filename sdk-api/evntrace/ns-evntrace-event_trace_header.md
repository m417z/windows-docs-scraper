# EVENT_TRACE_HEADER structure

## Description

The **EVENT_TRACE_HEADER** structure contains standard event tracing information
common to all events written by
[TraceEvent](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceevent).

## Members

### `Size`

Total number of bytes of the event. **Size** includes the size of the header
structure, plus the size of any event-specific data appended to the header.

On input, the size must be less than the size of the event tracing session's
buffer minus 72 (0x48).

On output, do not use this number in calculations.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.FieldTypeFlags`

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.HeaderType`

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MarkerFlags`

Reserved.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.Version`

This is a roll-up of the members of **Class**. The low-order byte contains the
Type, the next byte contains the Level, and the last two bytes contain the
version.

### `DUMMYUNIONNAME2.Class`

### `DUMMYUNIONNAME2.Class.Type`

Type of event. A provider can define their own event types or use the predefined
event types listed in the following table.

- **EVENT_TRACE_TYPE_CHECKPOINT**: Checkpoint event. Use for an event that is
not at the start or end of an activity.

- **EVENT_TRACE_TYPE_DC_END**: Data collection end event.

- **EVENT_TRACE_TYPE_DC_START**: Data collection start event.

- **EVENT_TRACE_TYPE_DEQUEUE**: Dequeue event. Use when an activity is queued
before it begins. Use EVENT_TRACE_TYPE_START to mark the time when a work item
is queued. Use the dequeue event type to mark the time when work on the item
actually begins. Use EVENT_TRACE_TYPE_END to mark the time when work on the
item completes.

- **EVENT_TRACE_TYPE_END**: End event. Use to trace the final state of a
multi-step event.

- **EVENT_TRACE_TYPE_EXTENSION**: Extension event. Use for an event that is a
continuation of a previous event. For example, use the extension event type
when an event trace records more data than can fit in a session buffer.

- **EVENT_TRACE_TYPE_INFO**: Informational event. This is the default event
type.

- **EVENT_TRACE_TYPE_REPLY**: Reply event. Use when an application that requests
resources can receive multiple responses. For example, if a client application
requests a URL, and the web server replies by sending several files, each file
received can be marked as a reply event.

- **EVENT_TRACE_TYPE_START**: Start event. Use to trace the initial state of a
multi-step event.

If you define your own event types, you should use numbers starting from 10.
However, there is nothing to prevent you from using any numbers that you wish to
use. If your event trace class GUID supports multiple event types, consumers
will use the event type to determine the event and how to interpret its
contents.

### `DUMMYUNIONNAME2.Class.Level`

Provider-defined value that defines the severity level used to generate the
event. The value ranges from 0 to 255. The controller specifies the severity
level when it calls the
[EnableTraceEx2](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enabletraceex2)
function. The provider retrieves the severity level by calling the
[GetTraceEnableLevel](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-gettraceenablelevel)
function from its
[ControlCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-wmidprequest)
implementation. The provider uses the value to set this member.

ETW defines the following severity levels. Selecting a level higher than 1 will
also include events for lower levels. For example, if the controller specifies
TRACE_LEVEL_WARNING (3), the provider also generates TRACE_LEVEL_FATAL (1) and
TRACE_LEVEL_ERROR (2) events.

| Value | Meaning |
| ------------------------------- | --------------------------------------------- |
| **TRACE_LEVEL_CRITICAL** (1) | Abnormal exit or termination events |
| **TRACE_LEVEL_ERROR** (2) | Severe error events |
| **TRACE_LEVEL_WARNING** (3) | Warning events such as allocation failures |
| **TRACE_LEVEL_INFORMATION** (4) | Non-error events such as entry or exit events |
| **TRACE_LEVEL_VERBOSE** (5) | Detailed trace events |

### `DUMMYUNIONNAME2.Class.Version`

Indicates the version of the event trace class that you are using to log the
event. Specify zero if there is only one version of your event trace class. The
version tells the consumer which MOF class to use to decipher the event data.

### `ThreadId`

On output, identifies the thread that generated the event.

Note that on Windows 2000, **ThreadId** was a **ULONGLONG** value.

### `ProcessId`

On output, identifies the process that generated the event.

**Windows 2000:** This member is not supported.

### `TimeStamp`

On output, contains the time that the event occurred. The resolution is system
time unless the **ProcessTraceMode** member of
[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_logfilea)
contains the `PROCESS_TRACE_MODE_RAW_TIMESTAMP` flag, in which case the
resolution depends on the value of the **Wnode.ClientContext** member of
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_properties)
at the time the controller created the session.

### `DUMMYUNIONNAME3`

### `DUMMYUNIONNAME3.Guid`

Event trace class GUID. You can use the class GUID to identify a category of
events and the **Class.Type** member to identify an event within the category of
events.

Alternatively, you can use the **GuidPtr** member to specify the class GUID.

**Windows XP and Windows 2000:** The class GUID must have been registered
previously using the
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function.

### `DUMMYUNIONNAME3.GuidPtr`

Pointer to an event trace class GUID. Alternatively, you can use the **Guid**
member to specify the class GUID.

When the event is written, ETW uses the pointer to copy the GUID to the event
(the GUID is included in the event, not the pointer).

If you use this member, the **Flags** member must also contain
WNODE_FLAG_USE_GUID_PTR.

### `DUMMYUNIONNAME4`

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME.KernelTime`

Elapsed execution time for kernel-mode instructions, in CPU time units. If you
are using a private session, use the value in the **ProcessorTime** member
instead. For more information, see Remarks.

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME.UserTime`

Elapsed execution time for user-mode instructions, in CPU time units. If you are
using a private session, use the value in the **ProcessorTime** member instead.
For more information, see Remarks.

### `DUMMYUNIONNAME4.ProcessorTime`

For private sessions, the elapsed execution time for user-mode instructions, in
CPU ticks.

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME2`

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME2.ClientContext`

Reserved.

### `DUMMYUNIONNAME4.DUMMYSTRUCTNAME2.Flags`

You must set this member to WNODE_FLAG_TRACED_GUID, and may optionally specify
any combination of the following.

- **WNODE_FLAG_USE_GUID_PTR**: Specify if the **GuidPtr** member contains the
class GUID.

- **WNODE_FLAG_USE_MOF_PTR**: Specify if an array of
[MOF_FIELD](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-mof_field) structures
contains the event data appended to this structure. The number of elements in
the array is limited to **MAX_MOF_FIELDS**.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

You can use the **KernelTime** and **UserTime** members to determine the CPU
cost in units for a set of instructions (the values indicate the CPU usage
charged to that thread at the time of logging). For example, if Event A and
Event B are consecutively logged by the same thread and they have CPU usage
numbers 150 and 175, then the activity that was performed by that thread between
events A and B cost 25 CPU time units (175 – 150).

The **TimerResolution** of the
[TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) structure
contains the resolution of the CPU usage timer in 100-nanosecond units. You can
use the timer resolution with the kernel time and user time values to determine
the amount of CPU time that the set of instructions used. For example, if the
timer resolution is 156,250, then 25 CPU time units is 0.39 seconds (156,250 \*
25 \* 100 / 1,000,000,000). This is the amount of CPU time (not elapsed wall
clock time) used by the set of instructions between events A and B.

Note, however, that the CPU usage timer resolution is typically very low (around
10 or more milliseconds). Therefore, CPU usage numbers cannot be used to account
for CPU time usage among threads with high accuracy. Rather, they are suitable
for long term, statistical type of analysis.

## See also

[EVENT_TRACE](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace)

[EventCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_callback)

[TraceEvent](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceevent)