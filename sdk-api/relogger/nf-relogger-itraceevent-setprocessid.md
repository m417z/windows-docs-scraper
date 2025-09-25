# ITraceEvent::SetProcessId

## Description

The **SetProcessId** method assigns an event to a specific process.

## Parameters

### `ProcessId` [in]

Type: **ULONG**

Identifier of the process that should own this event.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)