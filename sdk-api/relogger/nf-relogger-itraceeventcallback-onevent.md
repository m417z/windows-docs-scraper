# ITraceEventCallback::OnEvent

## Description

The **OnEvent** method indicates that an event has been received on the trace streams associated with a relogger.

## Parameters

### `Event` [in]

Type: **[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)***

The event being logged.

### `Relogger` [in]

Type: **[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)***

The trace relogger that was used to register this callback and relog this trace.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback)