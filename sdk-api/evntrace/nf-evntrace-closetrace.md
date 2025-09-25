# CloseTrace function

## Description

The **CloseTrace** function closes a trace processing session that was created
with [OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea).

## Parameters

### `TraceHandle` [in]

Handle to the trace processing session to close. The
[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea) function returns
this handle.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is one of the
[system error codes](https://learn.microsoft.com/windows/win32/debug/system-error-codes). The following
are some common errors and their causes.

- **ERROR_INVALID_HANDLE**

 One of the following is true:

  - _TraceHandle_ is **0**.
  - _TraceHandle_ is **INVALID_PROCESSTRACE_HANDLE**.
  - _TraceHandle_ is not a valid handle.

- **ERROR_BUSY**

 Prior to Windows Vista, you cannot close the trace until the
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) function
completes.

- **ERROR_CTX_CLOSE_PENDING**

 The call was successful. The
[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) function
will stop after it has processed all real-time events in its buffers (it will
not receive any new events).

## Remarks

Consumers call this function to close a trace handle returned by **OpenTrace**.

> [!Important]
> Do not use this function to close the trace handle returned by
> **StartTrace**.

If you are processing events from a log file, you call this function only after
the [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace)
function returns. However, if you are processing real-time events, you can call
this function before **ProcessTrace** returns. (Another way to stop trace
processing is to return FALSE from
[BufferCallback](https://learn.microsoft.com/windows/win32/api/evntrace/nc-evntrace-pevent_trace_buffer_callbacka).)

If you call this function before **ProcessTrace** returns, the **CloseTrace**
function returns ERROR_CTX_CLOSE_PENDING. The ERROR_CTX_CLOSE_PENDING code
indicates that the **CloseTrace** function call was successful; the
**ProcessTrace** function will stop processing events after it processes all
previously-queued events (**ProcessTrace** will not receive any new events after
you call the **CloseTrace** function). You can call the **CloseTrace** function
from your [BufferCallback](https://learn.microsoft.com/windows/desktop/ETW/buffercallback),
[EventCallback](https://learn.microsoft.com/windows/desktop/ETW/eventcallback), or
[EventClassCallback](https://learn.microsoft.com/windows/desktop/ETW/eventclasscallback) callback.

> **Prior to Windows Vista:** You can call **CloseTrace** only after
> [ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace) returns.

### Examples

For an example that uses **CloseTrace**, see
[Retrieving Event Data Using TDH](https://learn.microsoft.com/windows/desktop/ETW/retrieving-event-data-using-tdh).

## See also

[OpenTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-opentracea)

[ProcessTrace](https://learn.microsoft.com/windows/win32/api/evntrace/nf-evntrace-processtrace)