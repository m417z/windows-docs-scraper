# TRACE_ENABLE_INFO structure

## Description

Defines the session and the information that the session used to enable the
provider. This information is returned by
[EnumerateTraceGuidsEx](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-enumeratetraceguidsex)
as part of a
[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_provider_instance_info)
block.

## Members

### `IsEnabled`

Indicates if the provider is enabled to the session. The value is **TRUE** if
the provider is enabled to the session, otherwise, the value is **FALSE**. This
value should always be **TRUE**.

### `Level`

Level of detail that the session asked the provider to include in the events.
For details, see the _Level_ parameter of the
[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) function.

### `Reserved1`

Reserved.

### `LoggerId`

Identifies the session that enabled the provider.

### `EnableProperty`

Additional information that the session wants ETW to include in the log file.
For details, see the _EnableProperty_ parameter of the
[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) function.

### `Reserved2`

Reserved.

### `MatchAnyKeyword`

Keywords specify which events the session wants the provider to write. For
details, see the _MatchAnyKeyword_ parameter of the
[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) function.

### `MatchAllKeyword`

Keywords specify which events the session wants the provider to write. For
details, see the _MatchAllKeyword_ parameter of the
[EnableTraceEx](https://learn.microsoft.com/windows/desktop/ETW/enabletraceex-func) function.

## Remarks

The
[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_provider_instance_info)
block contains one or more of these structures.

## See also

[TRACE_PROVIDER_INSTANCE_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_provider_instance_info)