# TraceSetInformation function

## Description

The **TraceSetInformation** function configures event tracing session settings.

## Parameters

### `SessionHandle` [in]

Handle of the event tracing session to be configured. The
[StartTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-starttracea) function
returns this handle when a new trace is started. To obtain the handle of an
existing trace, use
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracew) to query
the trace properties based on the trace's name and then get the handle from the
**Wnode.HistoricalContext** field of the returned `EVENT_TRACE_PROPERTIES` data.

### `InformationClass` [in]

The information class to enable or disable. The information that the class
captures is included in the extended data section of the event. For a list of
information classes that you can enable, see the
[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)
enumeration.

### `TraceInformation` [in]

A pointer to information class specific data. The information class determines
the contents of this parameter.

### `InformationLength` [in]

The size, in bytes, of the data in the _TraceInformation_ buffer.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the following error codes.

- **ERROR_BAD_LENGTH**

 The program issued a command but the command length is incorrect. This error
is returned if the _InformationLength_ parameter is less than a minimum size.

- **ERROR_INVALID_PARAMETER**

 The parameter is incorrect.

- **ERROR_NOT_SUPPORTED**

 The request is not supported.

- **Other**

 Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to
obtain the message string for the returned error.

## Remarks

Call this function after calling [StartTrace](https://learn.microsoft.com/windows/desktop/ETW/starttrace).

If the _InformationClass_ parameter is set to **TraceStackTracingInfo**, calling
this function enables stack tracing of the specified kernel events. Subsequent
calls to this function overwrites the previous list of kernel events for which
stack tracing is enabled. To disable stack tracing, call this function with
_InformationClass_ set to **TraceStackTracingInfo** and _InformationLength_ set
to 0.

The extended data section of the event will include the call stack. The
[StackWalk_Event](https://learn.microsoft.com/windows/desktop/ETW/stackwalk-event) MOF class defines the
layout of the extended data.

Typically, on 64-bit computers, you cannot capture the kernel stack in certain
contexts when page faults are not allowed. To enable walking the kernel stack on
x64, set the `DisablePagingExecutive` Memory Management registry value to 1. The
`DisablePagingExecutive` registry value is located under the following registry
key:
`HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Memory Management`.
This should only be done for temporary diagnosis purposes because it increases
memory usage of the system.

## See also

[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/win32/api/evntrace/ne-evntrace-trace_query_info_class)

[TraceQueryInformation](https://learn.microsoft.com/windows/desktop/ETW/tracequeryinformation)