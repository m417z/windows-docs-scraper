## Description

The **EVENT_INSTANCE_HEADER** structure contains standard event tracing
information common to all events written by
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance).
The structure also contains registration handles for the event trace class and
related parent event, which you use to trace instances of a transaction or
hierarchical relationships between related events.

## Members

### `Size`

Total number of bytes of the event. **Size** must include the size of the
**EVENT_INSTANCE_HEADER** structure, plus the size of any event-specific data
appended to this structure. The size must be less than the size of the event
tracing session's buffer minus 72 (0x48).

### `DUMMYUNIONNAME`

A union of various structures and members.

### `DUMMYUNIONNAME.FieldTypeFlags`

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.HeaderType`

Reserved.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.MarkerFlags`

Reserved.

### `DUMMYUNIONNAME2`

A union of Class in two forms.

### `DUMMYUNIONNAME2.Version`

This is a roll-up of the members of **Class**. The low-order byte contains the
Type, the next byte contains the Level, and the last two bytes contain the
version.

### `DUMMYUNIONNAME2.Class`

The Class structure.

### `DUMMYUNIONNAME2.Class.Type`

Type of event. A provider can define their own event types or use the predefined
event types listed in the following table.

- **EVENT_TRACE_TYPE_CHECKPOINT**

 Checkpoint event. Use for an event that is not at the start or end of an
activity.

- **EVENT_TRACE_TYPE_DC_END**

 Data collection end event.

- **EVENT_TRACE_TYPE_DC_START**

 Data collection start event.

- **EVENT_TRACE_TYPE_DEQUEUE**

 Dequeue event. Use when an activity is queued before it begins. Use
EVENT_TRACE_TYPE_START to mark the time when a work item is queued. Use the
dequeue event type to mark the time when work on the item actually begins. Use
EVENT_TRACE_TYPE_END to mark the time when work on the item completes.

- **EVENT_TRACE_TYPE_END**

 End event. Use to trace the final state of a multi-step event.

- **EVENT_TRACE_TYPE_EXTENSION**

 Extension event. Use for an event that is a continuation of a previous event.
For example, use the extension event type when an event trace records more
data than can fit in a session buffer.

- **EVENT_TRACE_TYPE_INFO**

 Informational event. This is the default event type.

- **EVENT_TRACE_TYPE_REPLY**

 Reply event. Use when an application that requests resources can receive
multiple responses. For example, if a client application requests a URL, and
the web server replies by sending several files, each file received can be
marked as a reply event.

- **EVENT_TRACE_TYPE_START**

 Start event. Use to trace the initial state of a multi-step event.

If your event trace class GUID supports multiple event types, consumers will use
the event type to determine the event and how to interpret its contents.

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

On output, contains the time the event occurred, in 100-nanosecond intervals
since midnight, January 1, 1601.

### `RegHandle`

Handle to a registered event trace class. Set this property before calling the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function.

The
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function creates this handle (see the _TraceGuidReg_ parameter).

### `InstanceId`

On output, contains the event trace instance identifier associated with
**RegHandle**.

### `ParentInstanceId`

On output, contains the event trace instance identifier associated with
**ParentRegHandle**.

### `DUMMYUNIONNAME3`

A union of structs and members.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME`

A structure containing the following members.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME.KernelTime`

Elapsed execution time for kernel-mode instructions, in CPU ticks. If you are
using a private session, use the value in the **ProcessorTime** member instead.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME.UserTime`

Elapsed execution time for user-mode instructions, in CPU ticks. If you are
using a private session, use the value in the **ProcessorTime** member instead.

### `DUMMYUNIONNAME3.ProcessorTime`

For private sessions, the elapsed execution time for user-mode instructions, in
CPU ticks.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME2`

A union of structs and members.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME2.EventId`

The event identifier.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME2.Flags`

Must contain **WNODE_FLAG_TRACED_GUID**, and may also contain any combination of
the following.

- **WNODE_FLAG_USE_GUID_PTR**

 Specify if the **GuidPtr** member contains the class GUID.

- **WNODE_FLAG_USE_MOF_PTR**

 Specify if an array of
[MOF_FIELD](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-mof_field) structures
contains the event data appended to this structure. The number of elements in
the array is limited to **MAX_MOF_FIELDS**.

### `ParentRegHandle`

Handle to a registered event trace class of a parent event. Set this property
before calling the
[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)
function if you want to trace a hierarchical relationship (parent element/child
element) between related events.

The
[RegisterTraceGuids](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-registertraceguidsa)
function creates this handle (see the _TraceGuidReg_ parameter).

#### - ClientContext

Reserved.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

## See also

[TraceEventInstance](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-traceeventinstance)