# ITraceRelogger::RegisterCallback

## Description

The **RegisterCallback** method registers an implementation of [IEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback) with the relogger in order to signal trace activity (starting, stopping, and logging new events).

## Parameters

### `Callback` [in]

Type: **[IEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback)***

The trace activity information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)