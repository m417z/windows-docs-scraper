# TraceQueryInformation function

## Description

The **TraceQueryInformation** function provides information about an event
tracing session.

## Parameters

### `SessionHandle` [in]

Handle of the event tracing session for which you are collecting information.
The [StartTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-starttracea) function
returns this handle when a new trace is started. To obtain the handle of an
existing trace, use
[ControlTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-controltracew) to query
the trace properties based on the trace's name and then get the handle from the
**Wnode.HistoricalContext** field of the returned `EVENT_TRACE_PROPERTIES` data.

### `InformationClass` [in]

The information class to query. The information that the class captures is
included in the extended data section of the event. For a list of information
classes that you can query, see the
[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/desktop/ETW/trace-info-class) enumeration.

### `TraceInformation` [out]

A pointer to a buffer to receive the returned information class specific data.
The information class determines the contents of this parameter. For example,
for the **TraceStackTracingInfo** information class, this parameter is an array
of [CLASSIC_EVENT_ID](https://learn.microsoft.com/windows/desktop/ETW/classic-event-id) structures. The
structures specify the event GUIDs for which stack tracing is enabled. The array
is limited to 256 elements.

### `InformationLength` [in]

The size, in bytes, of the data returned in the _TraceInformation_ buffer. If
the function fails, this value indicates the required size of the
_TraceInformation_ buffer that is needed.

### `ReturnLength` [out, optional]

A pointer a value that receives the size, in bytes, of the specific data
returned in the _TraceInformation_ buffer.

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

The **TraceQueryInformation** function queries event tracing session settings
from a trace session. Call this function after calling
[StartTrace](https://learn.microsoft.com/windows/desktop/ETW/starttrace).

## See also

[TRACE_QUERY_INFO_CLASS](https://learn.microsoft.com/windows/desktop/ETW/trace-info-class)

[TraceSetInformation](https://learn.microsoft.com/windows/desktop/ETW/tracesetinformation)