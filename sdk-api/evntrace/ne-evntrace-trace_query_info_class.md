# TRACE_QUERY_INFO_CLASS enumeration

## Description

Used with [EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguidsex),
[TraceQueryInformation](https://learn.microsoft.com/windows/desktop/ETW/tracequeryinformation), or
[TraceSetInformation](https://learn.microsoft.com/windows/desktop/ETW/tracesetinformation) to specify a
type of trace information.

Note that **TRACE_INFO_CLASS** and **TRACE_QUERY_INFO_CLASS** are typedefs for
the same enumeration.

More comprehensive documentation about which APIs the values in the enumeration
should be used with, as well as the corresponding buffer input and output
formats are available in-line in the `TRACE_QUERY_INFO_CLASS` enumeration
definition in `evntrace.h`.

## Constants

### `TraceGuidQueryList:0`

Query for an array of GUIDs of the providers that are registered on the
computer.

### `TraceGuidQueryInfo:1`

Query for information that each session used to enable the provider.

### `TraceGuidQueryProcess:2`

Query for an array of GUIDs of the providers that registered themselves in the
same process as the calling process.

### `TraceStackTracingInfo:3`

Query the setting for call stack tracing for kernel events.

Returns an array of [CLASSIC_EVENT_ID](https://learn.microsoft.com/windows/desktop/ETW/classic-event-id)
structures. The structures specify the event GUIDs for which stack tracing is
enabled. The array is limited to 256 elements.

The value is supported on Windows 7, Windows Server 2008 R2, and later.

### `TraceSystemTraceEnableFlagsInfo:4`

Query the setting for the **EnableFlags** for the system trace provider. For
more information, see the
[EVENT_TRACE_PROPERTIES](https://learn.microsoft.com/windows/desktop/ETW/event-trace-properties) structure.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TraceSampledProfileIntervalInfo:5`

Queries the setting for the sampling profile interval for the supplied source.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TraceProfileSourceConfigInfo:6`

Configures the list of profiling sources that will be collected when the
performance monitoring counter profile event fires. The collected counters will
be emitted as part of the `PERF_PMC_PROFILE` event.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TraceProfileSourceListInfo:7`

Queries the list of profiling sources available on the system.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TracePmcEventListInfo:8`

Configures the session with a list of system events for which performance
monitoring counters configured by `TracePmcCounterListInfo` will be collected.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TracePmcCounterListInfo:9`

Configures the session with a list of profiling sources that will be collected
when events configured by `TracePmcEventListInfo` are logged to the session.

The value is supported on Windows 8, Windows Server 2012, and later.

### `TraceSetDisallowList:10`

Set the list of providers that will not be enabled to this session as part of a
provider group enablement. For more information, see
[Provider Traits](https://learn.microsoft.com/windows/desktop/ETW/provider-traits).

The value is supported on Windows 10, Windows Server 2016, and later.

### `TraceVersionInfo:11`

Query the trace file version information.

The value is supported on Windows 10, Windows Server 2016, and later.

### `TraceGroupQueryList:12`

Query an array of GUIDs of the provider groups that are active on the computer.

### `TraceGroupQueryInfo:13`

The value is supported on Windows 10, Windows Server 2016, and later.

Query information that each session used to enable the provider group.

### `TraceDisallowListQuery:14`

The value is supported on Windows 10, Windows Server 2016, and later.

Query an array of GUIDs that are disallowed for group enables on this session.

The value is supported on Windows 10, Windows Server 2016, and later.

### `TraceInfoReserved15`

Reserved for future use. Do not use.

### `TracePeriodicCaptureStateListInfo:16`

Updates the session with a list of providers that will periodically receive the
`EVENT_CONTROL_CODE_CAPTURE_STATE` control code, akin to a call from
[EnableTraceEx2](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex2).

For more information, see
[TRACE_PERIODIC_CAPTURE_STATE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_periodic_capture_state_info).

The value is supported on Windows 10, version 1709, Windows Server, version
1709, and later.

### `TracePeriodicCaptureStateInfo:17`

Queries the limits of periodic capture state settings on the system, including
the minimum time frequency and maximum number of providers that can be
simultaneously configured.

For more information, see
[TRACE_PERIODIC_CAPTURE_STATE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_periodic_capture_state_info).

The value is supported on Windows 10, version 1709, Windows Server, version
1709, and later.

### `TraceProviderBinaryTracking:18`

Instructs ETW to begin tracking binaries for all providers that are enabled to
the session. The tracking applies to providers that are enabled to the session
at the time of the call as well as to all future providers that are enabled to
the session.

ETW generates tracking events that contain a mapping between provider GUID(s)
and the path to the module containing the callback for the tracked provider. In
the case of a realtime session, the events are provided live in the realtime
buffers. In the case of a file-based session (i.e. if the trace is saved to an
.etl file), the events are aggregated and written to the file header; they will
be among the first events the ETW runtime provides when the .etl file is played
back.

The binary tracking events will have provider id `EventTraceGuid` and opcode
`0x43`.

The value is supported on Windows 10, version 1709, Windows Server, version
1709, and later.

### `TraceMaxLoggersQuery:19`

Queries the currently configured maximum number of ETW logging sessions allowed
by the operating system. Returns a ULONG. Used with
[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguidsex).

The value is supported on Windows 10, version 1709, Windows Server, version
1709, and later.

### `TraceLbrConfigurationInfo:20`

Enables Last Branch Record tracing for the given session, and configures
corresponding LBR filters.

The value is supported on Windows 10, version 19H1, Windows Server, version
1903, and later.

### `TraceLbrEventListInfo:21`

Configures the list of events that will trigger ETW to trace Last Branch Record
information as configured by `TraceLbrConfigurationInfo`.

The value is supported on Windows 10, version 19H1, Windows Server, version
1903, and later.

### `TraceMaxPmcCounterQuery:22`

Queries the maximum number of profiling sources that may be simultaneously
configured for use with ETW.

The value is supported on Windows 10, version 19H1, Windows Server, version
1903, and later.

### `TraceStreamCount:23`

Queries the configured stream count for a session. This is usually, but not
always, equal to the number of processors on the system, or 1 if no
per-processor buffering is configured for the session.

The value is supported on Windows 10, version 21H2, Windows Server 2022, and
later.

### `TraceStackCachingInfo:24`

Instructs ETW to begin caching stack traces for RegisterTraceGuids-based
("Classic") events in this session.

The value is supported on Windows 10, version 21H2, Windows Server 2022, and
later.

### `TracePmcCounterOwners:25`

Queries ETW for a list of processor performance monitoring counters currently in
use. This list may contain counters in use by facilities other than ETW.

The value is supported on Windows 10, version 21H2, Windows Server 2022, and
later.

### `TraceUnifiedStackCachingInfo:26`

Instructs ETW to begin caching stack traces for both RegisterTraceGuids-based
("Classic") and EventRegister-based events.

The value is supported on Windows 10, version 21H2, Windows Server 2022, and
later.

### `TracePmcSessionInformation:27`

Query all sessions for their PMC configuration set via `TracePmcEventListInfo` and `TracePmcCounterListInfo`.

The value is supported on Windows 10, version 22H2 and later.

### `TraceContextRegisterInfo:28`

Configures the session with a list of system events for which context register
events will be collected. Context register events contain CPU register
contents at the moment the specified related event is fired.

The value is supported on Windows Server 23H2 and later.

### `MaxTraceSetInfoClass:29`

Marks the last value in the enumeration. Do not use.

## Remarks

The **TRACE_INFO_CLASS** and **TRACE_QUERY_INFO_CLASS** enumerations both define
the same values. Use both enumerations with the
[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguidsex) function or
the [TraceSetInformation](https://learn.microsoft.com/windows/desktop/ETW/tracesetinformation) function.

## See also

[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/desktop/ETW/enumeratetraceguidsex)

[TraceSetInformation](https://learn.microsoft.com/windows/desktop/ETW/tracesetinformation)