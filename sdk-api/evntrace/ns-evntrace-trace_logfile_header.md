# TRACE_LOGFILE_HEADER structure

## Description

The **TRACE_LOGFILE_HEADER** structure contains information about an event
tracing session and its events. It is the raw data format of the trace
information data in the header of an ETW log file. It is also a part of the
information returned by
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) and provided to
the
[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka)
during trace processing.

## Members

### `BufferSize`

Size of the event tracing session's buffers, in bytes.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Version`

Version number of the operating system where the trace was collected. This is a
roll-up of the members of **VersionDetail**. Starting with the low-order bytes,
the first two bytes contain **MajorVersion**, the next two bytes contain
**MinorVersion**, the next two bytes contain **SubVersion**, and the last two
bytes contain **SubMinorVersion**.

### `DUMMYUNIONNAME.VersionDetail`

### `DUMMYUNIONNAME.VersionDetail.MajorVersion`

Major version number of the operating system where the trace was collected.

### `DUMMYUNIONNAME.VersionDetail.MinorVersion`

Minor version number of the operating system where the trace was collected.

### `DUMMYUNIONNAME.VersionDetail.SubVersion`

Reserved.

### `DUMMYUNIONNAME.VersionDetail.SubMinorVersion`

Reserved.

### `ProviderVersion`

Build number of the operating system where the trace was collected.

### `NumberOfProcessors`

Number of processors on the system where the trace was collected.

### `EndTime`

Time at which the event tracing session stopped, in 100-nanosecond intervals
since midnight, January 1, 1601. This value may be 0 if you are consuming events
in real time or from a log file that was not finalized (i.e. was not properly
closed).

### `TimerResolution`

Resolution of the hardware timer, in units of 100 nanoseconds. For usage, see
the Remarks for [EVENT_TRACE_HEADER](https://learn.microsoft.com/windows/desktop/ETW/event-trace-header).

### `MaximumFileSize`

Maximum size of the log file, in megabytes.

### `LogFileMode`

Logging mode for the event tracing session. For a list of values, see
[Logging Mode Constants](https://learn.microsoft.com/windows/desktop/ETW/logging-mode-constants).

### `BuffersWritten`

Total number of buffers written by the event tracing session.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.LogInstanceGuid`

Reserved.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME.StartBuffers`

Reserved.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME.PointerSize`

Default size of a pointer data type, in bytes.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME.EventsLost`

Number of events lost during the event tracing session. Events are primarily
lost due to insufficient memory allocated to a trace logging session or a very
high rate of incoming events.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME.CpuSpeedInMHz`

CPU speed, in megahertz, of the system where the trace was collected.

**Windows 2000:** This member is not supported.

### `LoggerName`

Do not use this field.

The name of the event tracing session is the first null-terminated string
following this structure in memory.

### `LogFileName`

Do not use this field.

The name of the event tracing log file is the second null-terminated string
following this structure in memory. The first string is the name of the session.

### `TimeZone`

A
[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)
structure that contains the time zone for the **BootTime**, **EndTime** and
**StartTime** members.

### `BootTime`

Time at which the system was started, in 100-nanosecond intervals since
midnight, January 1, 1601. **BootTime** is supported only for traces written to
the Global Logger session.

### `PerfFreq`

Frequency of the high-resolution performance counter, if one exists.

### `StartTime`

Time at which the event tracing session started, in 100-nanosecond intervals
since midnight, January 1, 1601.

### `ReservedFlags`

Specifies the clock type. For details, see the **ClientContext** member of
[WNODE_HEADER](https://learn.microsoft.com/windows/win32/etw/wnode-header).

### `BuffersLost`

Total number of buffers lost during the event tracing session.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any
members.

The first event from any log file contains the data defined in this structure.
You can use this structure to access the event data or you can use the
[EventTrace_Header](https://learn.microsoft.com/windows/desktop/ETW/eventtrace-header) MOF class to decode
the event data. Using this structure to read the event data may return
unexpected results if the consumer is on a different computer from the one that
generated the log file or the log file was written in a WOW (32-bit) session on
a 64-bit computer. This is because the **LoggerName** and **LogFileName**
members are pointers and can vary in size depending on the **PointerSize**
member.

## See also

[EVENT_TRACE_LOGFILE](https://learn.microsoft.com/windows/desktop/ETW/event-trace-logfile)

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)

[TIME_ZONE_INFORMATION](https://learn.microsoft.com/windows/desktop/api/timezoneapi/ns-timezoneapi-time_zone_information)