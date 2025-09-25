# ITraceRelogger::AddLogfileTraceStream

## Description

The **AddLogfileTraceStream** method adds a new logfile-based ETW trace stream to the relogger.

## Parameters

### `LogfileName` [in]

Type: **BSTR**

The file that contains the events to be relogged.

### `UserContext` [in]

Type: **void***

The user context under which to relog these events.

### `TraceHandle` [out, retval]

Type: **TRACEHANDLE***

Handle to be used when adding new artificial events to the trace stream.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Events in the newly-added stream will generate callbacks to the [IEventCallback](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceeventcallback) object associated with this relogger.

## See also

[Consuming Events](https://learn.microsoft.com/windows/desktop/ETW/consuming-events)

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)