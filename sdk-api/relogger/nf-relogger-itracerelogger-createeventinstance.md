# ITraceRelogger::CreateEventInstance

## Description

The **CreateEventInstance** method generates a new event.

## Parameters

### `TraceHandle` [in]

Type: **TRACEHANDLE**

The trace from which to create the event.

### `Flags` [in]

Type: **ULONG**

Indicates whether the event is classic or crimson.

### `Event` [out, retval]

Type: **[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)****

The newly generated event.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Event metadata will be pulled from *TraceHandle* but can be modified by the developer before being logged to a trace.

## See also

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)

[ITraceRelogger](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itracerelogger)