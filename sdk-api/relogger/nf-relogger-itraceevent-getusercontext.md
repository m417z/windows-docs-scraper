# ITraceEvent::GetUserContext

## Description

The **GetUserContext** method retrieves the user context associated with the stream to which the event belongs.

## Parameters

### `UserContext` [out, retval]

Type: **void****

The user context. This is the context specified in the call to [ITraceRelogger::AddLogfileTraceStream](https://learn.microsoft.com/windows/desktop/api/relogger/nf-relogger-itracerelogger-addlogfiletracestream).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)

[ITraceRelogger::AddLogfileTraceStream](https://learn.microsoft.com/windows/desktop/api/relogger/nf-relogger-itracerelogger-addlogfiletracestream)

[ITraceRelogger::AddRealtimeTraceStream](https://learn.microsoft.com/windows/desktop/api/relogger/nf-relogger-itracerelogger-addrealtimetracestream)