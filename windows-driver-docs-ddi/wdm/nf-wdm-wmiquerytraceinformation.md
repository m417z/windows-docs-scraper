# WmiQueryTraceInformation function

## Description

The **WmiQueryTraceInformation** routine returns information about a [WMI event trace](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-event-tracing).

## Parameters

### `TraceInformationClass` [in]

Specifies a [TRACE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_trace_information_class) enumerator that indicates the type of information to return about an event trace.

### `TraceInformation` [out]

A pointer to a caller-allocated output buffer where the routine returns the event trace information specified by *TraceInformationClass*.

### `TraceInformationLength` [in]

Specifies the size, in bytes, of the *TraceInformation* buffer.

### `RequiredLength` [out, optional]

A pointer to the value returned by the routine that specifies the required size, in bytes, of the *TraceInformation* buffer. The caller should set *RequiredLength* to **NULL** if it does not use the required length information.

### `Buffer` [in, optional]

A pointer to the query-specific input information that a caller supplies. If caller-supplied information is not required, the caller should set *Buffer* to **NULL**.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Success |
| **STATUS_INFO_LENGTH_MISMATCH** | The size of the *TraceInformation* buffer is not equal to the required size for the specified event trace information. |
| **STATUS_INVALID_HANDLE** | The trace handle specified by the **HistoricalContext** member of the (PWNODE_HEADER)*Buffer* is not valid. |
| **STATUS_INVALID_INFO_CLASS** | The specified type of event trace information is not valid. |
| **STATUS_INVALID_PARAMETER** | The name of the event trace, supplied with a query to return a trace handle given its name, is not valid. |
| **STATUS_INVALID_PARAMETER_MIX** | The caller did not supply the information required for the specified event trace information. |
| **STATUS_MORE_ENTRIES** | The *TraceInformation* buffer is not large enough to hold an array of all the valid event trace handles. |
| **STATUS_NOT_FOUND** | A global logger was not found. |

## Remarks

For each type of event trace information specified by *TraceInformationClass*, the following table provides:

* Input requirements
* Information that **WmiQueryTraceInformation** returns in the *TraceInformation* buffer

| Value of *TraceClassInformation* | Input requirements | Information returned |
| --- | --- | --- |
| **TraceIdClass** | *TraceInformationLength* is equal to the value of **sizeof**(ULONG).<br><br>The size, in bytes of the *TraceInformation* buffer is greater than or equal to the value of **sizeof**(ULONG).<br><br>The **HistoricalContext** member of (PWNODE_HEADER)*Buffer* specifies an event trace handle. | *(PULONG)*TraceInformation* is set to the logger ID of the event trace handle. |
| **TraceHandleClass** | *TraceInformationLength* is equal to the value of **sizeof**(TRACEHANDLE).<br><br>The size, in bytes of the *TraceInformation* buffer must be greater than or equal to the value of **sizeof**(TRACEHANDLE).<br><br>*(PULONG)*Buffer* is set to a logger ID. | *(PTRACEHANDLE)*TraceInformation* is set to an event trace handle for the specified logger. If the specified logger ID is zero, an event trace handle for the kernel logger is returned. |
| **TraceEnableFlagsClass** | *TraceInformationLength* is greater than or equal to the value of **sizeof**(ULONG). <br><br>The size, in bytes of the *TraceInformation* buffer must be greater than or equal to the value of **sizeof**(ULONG).<br><br>The **HistoricalContext** member of (PWNODE_HEADER)*Buffer* specifies an event trace handle. | *(PULONG)*TraceInformation* is set to the enable flags that are set for the specified event trace handle. |
| **TraceEnableLevelClass** | *TraceInformationLength* is set greater than or equal to the value of **sizeof**(ULONG). <br><br>The size, in bytes of the *TraceInformation* buffer must be greater than or equal to the value of **sizeof**(ULONG).<br><br>The **HistoricalContext** member of (PWNODE_HEADER)*Buffer* specifies an event trace handle. | *(PULONG)*TraceInformation* is set to the level for the specified event trace handle. |
| **GlobalLoggerHandleClass** | *TraceInformationLength* is equal to the value of **sizeof**(TRACEHANDLE).<br><br>The size, in bytes of the *TraceInformation* buffer must be greater than or equal to the value of **sizeof**(TRACEHANDLE). | *(PTRACEHANDLE)*TraceInformation* is set to an event trace handle for the global logger. |
| **EventLoggerHandleClass** | For internal use only. | For internal use only. |
| **AllLoggerHandlesClass** | *TraceInformationLength* is set to the size, bytes, of an array of *m* TRACEHANDLE values.<br><br>The size, in bytes of the *TraceInformation* buffer must be greater than or equal to the value of (*m****sizeof**(TRACEHANDLE)). | The *TraceInformation* buffer contains an array of *n* trace handles, where *n* is the minimum of *m*, the number of caller-supplied event trace handles, and the number of valid event trace handles. The routine returns a status of STATUS_MORE_ENTRIES if the *TraceInformation* buffer is too small to hold all trace handles. |
| **TraceHandleByNameClass** | *TraceInformationLength* is set to the value of **sizeof**(TRACEHANDLE).<br><br>The size, in bytes, of the *TraceInformation* buffer must be greater than or equal to the value of **sizeof**(TRACEHANDLE).<br><br>(PUNICODE_STRING)*Buffer* specifies a friendly trace name in Unicode format. | *(PTRACEHANDLE)*TraceInformation* is set to the event trace handle associated with the specified friendly name. |

If the caller supplies a non-**NULL** *RequiredLength* pointer, **WmiQueryTraceInformation** also returns the required length for the specified event trace information.

**WmiQueryTraceInformation** runs at the IRQL of the caller.

## See also

[IoWmiWriteEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiwriteevent)

[TRACE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_trace_information_class)

[WmiFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmifireevent)

[WmiTraceMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessage)

[WmiTraceMessageVa](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessageva)