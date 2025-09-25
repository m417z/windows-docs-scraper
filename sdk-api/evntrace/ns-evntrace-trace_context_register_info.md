## Description

Identifies the set of registers to be logged when enabling Context Register Tracing. Used when the
[TraceContextRegisterInfo](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class) value is specified as the *InformationClass* parameter of the [TraceSetInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracesetinformation) function.

## Members

### `RegisterTypes`

This field specifies which CPU registers should be logged when triggered by a
related system event. Multiple flag values can be combined using bit-wise OR.
For supported values, see [ETW_CONTEXT_REGISTER_TYPES](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-etw_context_register_types).

### `Reserved`

Reserved.

## Remarks

Currently, both [EtwContextRegisterTypeControl](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-etw_context_register_types) and [EtwContextRegisterTypeInteger](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-etw_context_register_types) must be set for correct operation of this API.

## See also