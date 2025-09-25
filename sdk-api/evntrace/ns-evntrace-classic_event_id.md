# CLASSIC_EVENT_ID structure

## Description

Identifies the kernel event for which you want to enable call stack tracing. Used with the [TraceStackTracingInfo](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class) class of
[TraceSetInformation](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-tracesetinformation).

## Members

### `EventGuid`

The GUID that identifies the kernel event class.

### `Type`

The event type that identifies the event within the kernel event class to enable.

### `Reserved`

Reserved.

## Remarks

Useful values for the EventGuid and Type fields can be determined from consulting the WMI classes in the `root\wmi` namespace. You can also find these values in `wmicore.mof` (where they are originally defined), or see [NT Kernel Logger Constants](https://learn.microsoft.com/windows/win32/etw/nt-kernel-logger-constants).

### Examples

To enable the [read](https://learn.microsoft.com/windows/desktop/ETW/diskio-typegroup1) event type for [disk IO](https://learn.microsoft.com/windows/desktop/ETW/diskio) events, set **GUID** to `3d6fa8d4-fe05-11d0-9dda-00c04fd7ba7c` and **Type** to 10.

To enable the [context switch](https://learn.microsoft.com/windows/win32/etw/cswitch) event type for [thread](https://learn.microsoft.com/windows/win32/etw/thread-v2) events, set **GUID** to `3d6fa8d1-fe05-11d0-9dda-00c04fd7ba7c` and **Type** to 36.

## See also

[TraceSetInformation](https://learn.microsoft.com/windows/desktop/ETW/tracesetinformation)

[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)

[NT Kernel Logger Constants](https://learn.microsoft.com/windows/win32/etw/nt-kernel-logger-constants)