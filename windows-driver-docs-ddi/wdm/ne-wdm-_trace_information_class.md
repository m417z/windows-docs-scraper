# _TRACE_INFORMATION_CLASS enumeration

## Description

The **TRACE_INFORMATION_CLASS** enumeration type is used to indicate types of information associated with a [WMI event tracing](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-event-tracing) session.

## Constants

### `TraceIdClass`

Retrieves the logger ID (ULONG) of an event tracing session given a caller-supplied Wnode.

### `TraceHandleClass`

Retrieves a trace handle (TRACEHANDLE) for an event tracing session given a caller-supplied logger ID (ULONG).

### `TraceEnableFlagsClass`

Retrieves the enable flags (ULONG) set on a caller-supplied event trace handle (TRACEHANDLE).

### `TraceEnableLevelClass`

Retrieves the enable level (ULONG) set on a caller-supplied event trace handle (TRACEHANDLE).

### `GlobalLoggerHandleClass`

Retrieves an event trace handle (TRACEHANDLE) for the global logger.

### `EventLoggerHandleClass`

Reserved for use by the operating system.

### `AllLoggerHandlesClass`

Retrieves an array of event trace handles (TRACEHANDLE array) for all valid loggers.

### `TraceHandleByNameClass`

Retrieves an event trace handle (TRACEHANDLE) identified by a caller-supplied friendly name ([UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure in buffer).

### `LoggerEventsLostClass`

Retrieves the number (ULONG) of events lost for a logger session given a caller-supplied logger ID (ULONG).

### `TraceSessionSettingsClass`

Retrieves the settings (**ETW_TRACE_SESSION_SETTINGS** structure) for a logger session given a caller-supplied trace handle (TRACEHANDLE).

### `LoggerEventsLoggedClass`

Retrieves the number (ULONG) of events logged in a logger session given a caller-supplied logger ID (ULONG).

### `DiskIoNotifyRoutinesClass`

Reserved for use by the operating system.

### `TraceInformationClassReserved1`

Reserved for use by the operating system.

### `FltIoNotifyRoutinesClass`

Reserved for use by the operating system.

### `TraceInformationClassReserved2`

Reserved for use by the operating system.

### `WdfNotifyRoutinesClass`

Reserved for use by the operating system.

### `MaxTraceInformationClass`

The maximum value in this enumeration type.

## Remarks

**TRACE_INFORMATION_CLASS** is provided primarily for use with the [WmiQueryTraceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmiquerytraceinformation) routine, which returns information about a WMI event tracing session.

## See also

[WmiFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmifireevent)

[WmiQueryTraceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmiquerytraceinformation)

[WmiTraceMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessage)

[WmiTraceMessageVa](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessageva)