# ITraceEventCallback::OnFinalizeProcessTrace

## Description

The **OnFinalizeProcessTrace** trace method indicates that a trace is about to end so that relogging can be finalized.

## Parameters

### `Relogger` [in]

Type: **[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)***

The trace relogger that was used to register this callback and relog this trace.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback)