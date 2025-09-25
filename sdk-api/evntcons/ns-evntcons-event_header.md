# EVENT_HEADER structure (evntcons.h)

## Description

Defines information about the event.

## Members

### `Size`

Size of the event record, in bytes.

### `HeaderType`

Reserved.

### `Flags`

Flags that provide information about the event such as the type of session it was logged to and if the event contains extended data. This member can contain one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **EVENT_HEADER_FLAG_EXTENDED_INFO** | The **ExtendedData** member of [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record) contains data. |
| **EVENT_HEADER_FLAG_PRIVATE_SESSION** | The event was logged to a private session. Use **ProcessorTime** for elapsed execution time. |
| **EVENT_HEADER_FLAG_STRING_ONLY** | The event data is a null-terminated Unicode string. You do not need a manifest to parse the **UserData** member of [EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record). |
| **EVENT_HEADER_FLAG_TRACE_MESSAGE** | The provider used [TraceMessage](https://learn.microsoft.com/windows/desktop/ETW/tracemessage) or [TraceMessageVa](https://learn.microsoft.com/windows/desktop/ETW/tracemessageva) to log the event. Most providers do not use these functions to write events, so this flag typically indicates that the event was written by [Windows Software Trace Preprocessor](https://learn.microsoft.com/windows/desktop/ETW/windows-software-trace-preprocessor) (WPP). |
| **EVENT_HEADER_FLAG_NO_CPUTIME** | Use **ProcessorTime** for elapsed execution time. |
| **EVENT_HEADER_FLAG_32_BIT_HEADER** | Indicates that the provider was running on a 32-bit computer or in a WOW64 session. |
| **EVENT_HEADER_FLAG_64_BIT_HEADER** | Indicates that the provider was running on a 64-bit computer. |
| **EVENT_HEADER_FLAG_CLASSIC_HEADER** | Indicates that provider used [TraceEvent](https://learn.microsoft.com/windows/desktop/ETW/traceevent) to log the event. |

### `EventProperty`

Indicates the source to use for parsing the event data.

| Value | Meaning |
| --- | --- |
| **EVENT_HEADER_PROPERTY_XML** | Indicates that you need a manifest to parse the event data. |
| **EVENT_HEADER_PROPERTY_FORWARDED_XML** | Indicates that the event data contains within itself a fully-rendered XML description of the data, so you do not need a manifest to parse the event data. |
| **EVENT_HEADER_PROPERTY_LEGACY_EVENTLOG** | Indicates that you need a WMI MOF class to parse the event data. |

### `ThreadId`

Identifies the thread that generated the event.

### `ProcessId`

Identifies the process that generated the event.

### `TimeStamp`

Contains the time that the event occurred. The resolution is system time unless the **ProcessTraceMode** member of [EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/desktop/ETW/event-trace-logfile) contains the PROCESS_TRACE_MODE_RAW_TIMESTAMP flag, in which case the resolution depends on the value of the **Wnode.ClientContext** member of [EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) at the time the controller created the session.

### `ProviderId`

GUID that uniquely identifies the provider that logged the event.

### `EventDescriptor`

Defines the information about the event such as the event identifier and severity level. For details, see [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.KernelTime`

Elapsed execution time for kernel-mode instructions, in CPU time units. If you are using a private session, use the value in the **ProcessorTime** member instead. For more information, see Remarks.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.UserTime`

Elapsed execution time for user-mode instructions, in CPU time units. If you are using a private session, use the value in the **ProcessorTime** member instead. For more information, see Remarks.

### `DUMMYUNIONNAME.ProcessorTime`

For private sessions, the elapsed execution time for user-mode instructions, in CPU ticks.

### `ActivityId`

Identifier that relates two events. For details, see [EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer).

## Remarks

You can use the **KernelTime** and **UserTime** members to determine the CPU cost in units for a set of instructions (the values indicate the CPU usage charged to that thread at the time of logging). For example, if Event A and Event B are consecutively logged by the same thread and they have CPU usage numbers 150 and 175, then the activity that was performed by that thread between events A and B cost 25 CPU time units (175 – 150).

The **TimerResolution** of the [TRACE_LOGFILE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/trace-logfile-header) structure contains the resolution of the CPU usage timer in 100-nanosecond units. You can use the timer resolution with the kernel time and user time values to determine the amount of CPU time that the set of instructions used. For example, if the timer resolution is 156,250, then 25 CPU time units is 0.39 seconds (156,250 * 25 * 100 / 1,000,000,000). This is the amount of CPU time (not elapsed wall clock time) used by the set of instructions between events A and B.

## See also

[EVENT_RECORD](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_record)