# ITraceEvent::SetPayload

## Description

The **SetPayload** method sets the payload for an event.

## Parameters

### `Payload` [in]

Type: **BYTE***

The event payload data.

### `PayloadSize` [in]

Type: **ULONG**

Size of the payload data, in bytes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Payloads contain only developer-defined data.

## See also

[ITraceEvent](https://learn.microsoft.com/windows/desktop/api/relogger/nn-relogger-itraceevent)