# TRACE_VERSION_INFO structure

## Description

Determines the version information of the trace processing API.
This data is returned from
[TraceQueryInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracequeryinformation)
when called with the
[TraceVersionInfo](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)
information class.

## Members

### `EtwTraceProcessingVersion`

The version of the trace processing API on the current system.

### `Reserved`

Not used.

## See also

[TraceQueryInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracequeryinformation)