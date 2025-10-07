# WNODE\_HEADER structure

The **WNODE\_HEADER** structure is a member of the [**EVENT\_TRACE\_PROPERTIES**](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_properties) structure.

## Members

**BufferSize**

Total size of memory allocated, in bytes, for the event tracing session properties. The size of memory must include the room for the [**EVENT\_TRACE\_PROPERTIES**](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_properties) structure plus the session name string and log file name string that follow the structure in memory.

**ProviderId**

Reserved for internal use.

**HistoricalContext**

On output, the handle to the event tracing session.

**Version**

Reserved for internal use.

**Linkage**

Reserved for internal use.

**KernelHandle**

Reserved for internal use.

**TimeStamp**

Time at which the information in this structure was updated, in 100-nanosecond intervals since midnight, January 1, 1601.

**Guid**

The GUID that you define for the session.

For an NT Kernel Logger session, set this member to **SystemTraceControlGuid**.

If this member is set to **SystemTraceControlGuid** or **GlobalLoggerGuid**, the logger will be a system logger.

For a private logger session, set this member to the provider's GUID that you are going to enable for the session.

If you start a session that is not a kernel logger or private logger session, you do not have to specify a session GUID. If you do not specify a GUID, ETW creates one for you. You need to specify a session GUID only if you want to change the default permissions associated with a specific session. For details, see the EventAccessControl function.

You cannot start more than one session with the same session GUID.

**Prior to Windows Vista:** You can start more than one session with the same session GUID.

**ClientContext**

Clock resolution to use when logging the time stamp for each event. The default is Query performance counter (QPC).

**Prior to Windows Vista:** The default is system time.

**Prior to Windows 10, version 1703:** No more than 2 distinct clock types can be used simultaneously by any system loggers.

**Starting with Windows 10, version 1703:** The clock type restriction has been removed. All three clock types can now be used simultaneously by system loggers.

You can specify one of the following values.

| Value | Meaning |
|-------|---------|
| 1 | Query performance counter (QPC). The QPC counter provides a high-resolution time stamp that is not affected by adjustments to the system clock. The time stamp stored in the event is equivalent to the value returned from the QueryPerformanceCounter API. For more information on the characteristics of this time stamp, see [Acquiring high-resolution time stamps](https://learn.microsoft.com/windows/win32/sysinfo/acquiring-high-resolution-time-stamps).<br> You should use this resolution if you have high event rates or if the consumer merges events from different buffers. In these cases, the precision and stability of the QPC time stamp allows for better accuracy in ordering the events from different buffers. However, the QPC time stamp will not reflect updates to the system clock, e.g. if the system clock is adjusted forward due to synchronization with an NTP server while the trace is in progress, the QPC time stamps in the trace will continue to reflect time as if no update had occurred.<br> To determine the resolution, use the **PerfFreq** member of [**TRACE_LOGFILE_HEADER**](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) when consuming the event.<br> To convert an event’s time stamp into 100-ns units, use the following conversion formula: <br> scaledTimestamp = eventRecord.EventHeader.TimeStamp.QuadPart * 10000000.0 / logfileHeader.PerfFreq.QuadPart<br> Note that on older computers, the time stamp may not be accurate because the counter sometimes skips forward due to hardware errors.<br> |
| 2 | System time. The system time provides a time stamp that tracks changes to the system’s clock, e.g. if the system clock is adjusted forward due to synchronization with an NTP server while the trace is in progress, the System Time time stamps in the trace will also jump forward to match the new setting of the system clock. <br>
* On systems prior to Windows 10, the time stamp stored in the event is equivalent to the value returned from the GetSystemTimeAsFileTime API.
* On Windows 10 or later, the time stamp stored in the event is equivalent to the value returned from the GetSystemTimePreciseAsFileTime API.

Prior to Windows 10, the resolution of this time stamp was the resolution of a system clock tick, as indicated by the TimerResolution member of TRACE_LOGFILE_HEADER. Starting with Windows 10, the resolution of this time stamp is the performance counter resolution, as indicated by the PerfFreq member of TRACE_LOGFILE_HEADER.\
 To convert an event’s time stamp into 100-ns units, use the following conversion formula: \
 scaledTimestamp = eventRecord.EventHeader.TimeStamp.QuadPart\
 Note that when events are captured on a system running an OS prior to Windows 10, if the volume of events is high, the resolution for system time may not be fine enough to determine the sequence of events. In this case, a set of events will have the same time stamp, but the order in which ETW delivers the events may not be correct. Starting with Windows 10, the time stamp is captured with additional precision, though some instability may still occur in cases where the system clock was adjusted while the trace was being captured.\
 |
| 3 | CPU cycle counter. The CPU counter provides the highest resolution time stamp and is the least resource-intensive to retrieve. However, the CPU counter is unreliable and should not be used in production. For example, on some computers, the timers will change frequency due to thermal and power changes, in addition to stopping in some states.<br> To determine the resolution, use the **CpuSpeedInMHz** member of [**TRACE_LOGFILE_HEADER**](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_logfile_header) when consuming the event.<br> If your hardware does not support this clock type, ETW uses system time.<br>**Windows Server 2003, Windows XP with SP1 and Windows XP:** This value is not supported, it was introduced in Windows Server 2003 with SP1 and Windows XP with SP2.<br> |

**Windows 2000:** The **ClientContext** member is not supported.

**Flags**

Must contain **WNODE\_FLAG\_TRACED\_GUID** to indicate that the structure contains event tracing information.

## Remarks

Be sure to initialize the memory for this structure to zero before setting any members.

To convert an ETW timestamp into a FILETIME, use the following procedure:

1. For each session or log file being processed (i.e. for each EVENT\_TRACE\_LOGFILE), check the logFile.ProcessTraceMode field to determine whether the PROCESS\_TRACE\_MODE\_RAW\_TIMESTAMP flag is set. By default, this flag is not set. If this flag is not set, the ETW runtime will automatically convert the timestamp of each EVENT\_RECORD into a FILETIME before sending the EVENT\_RECORD to your EventRecordCallback function, so no additional processing is needed. The following steps should only be used if the trace is being processed with the PROCESS\_TRACE\_MODE\_RAW\_TIMESTAMP flag set.
2. For each session or log file being processed (i.e. for each EVENT\_TRACE\_LOGFILE), check the logFile.LogfileHeader.ReservedFlags field to determine the time stamp scale for the log file. Based on the value of ReservedFlags, follow one of these steps to determine the value to use for timeStampScale in the remaining steps:

a. If ReservedFlags == 1 (QPC): DOUBLE timeStampScale = 10000000.0 / logFile.LogfileHeader.PerfFreq.QuadPart;
b. If ReservedFlags == 2 (System time): DOUBLE timeStampScale = 1.0;
Note that the remaining steps are unnecessary for events using system time, since the events already provide their time stamps in FILETIME units. The remaining steps will work but are unnecessary and will introduce a small rounding error.
c. If ReservedFlags == 3 (CPU cycle counter): DOUBLE timeStampScale = 10.0 / logFile.LogfileHeader.CpuSpeedInMHz;

 3. On the FIRST call to your EventRecordCallback function for a particular log file, use data from the logFile (EVENT\_TRACE\_LOGFILE) and from the eventRecord (EVENT\_RECORD) to compute the timeStampBase that will be used for the remaining events in the log file: INT64 timeStampBase = logFile.LogfileHeader.StartTime.QuadPart - (INT64)(timeStampScale \* eventRecord.EventHeader.TimeStamp.QuadPart);
4. For each eventRecord (EVENT\_RECORD), convert the event’s timestamp into FILETIME as follows, using the timeStampScale and timeStampBase values calculated in steps 2 and 3: INT64 timeStampInFileTime = timeStampBase + (INT64)(timeStampScale \* eventRecord.EventHeader.TimeStamp.QuadPart);

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps \| UWP apps\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps \| UWP apps\]<br> |
| Header<br> | Wmistr.h |

## See also

[*ControlCallback*](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-wmidprequest)

[**EVENT\_TRACE\_PROPERTIES**](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-event_trace_properties)

[**GetTraceLoggerHandle**](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-gettraceloggerhandle)

[**LARGE\_INTEGER**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)

