# ITraceEventCallback::OnBeginProcessTrace

## Description

The **OnBeginProcessTrace** trace method indicates that a trace is about to begin so that relogging can be started.

## Parameters

### `HeaderEvent` [in]

Type: **[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)***

Supplies a pointer to the header event.

### `Relogger` [in]

Type: **[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)***

Supplies a pointer to the **ITraceRelogger** interface, which exposes
APIs for actual event injection, synthesizing new events, and cloning
existing events.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback)