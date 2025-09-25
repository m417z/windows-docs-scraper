# ITraceRelogger::Inject

## Description

The **Inject** method injects a non-system-generated event into the event stream being written to the output trace logfile.

## Parameters

### `Event` [in]

Type: **IEvent***

The event to be injected into the stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is the primary way to indicate which events should go into the output trace logfile.

To preserve an existing event provided by [IEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nf-relogger-itraceeventcallback-onevent), this method should be called.

## See also

[IEventCallback::OnEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nf-relogger-itraceeventcallback-onevent)

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)