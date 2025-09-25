## Description

Called when a bidi response is received.

## Parameters

### `bstrResponse` [in]

The received response.

### `hrStatus` [in]

An HRESULT value.

## Return value

This method returns an **HRESULT** value.

## Remarks

The *bstrResponse* parameter is formatted according to the schema that is described in [Bidi Request and Response Schemas](https://learn.microsoft.com/previous-versions/dd183368(v=vs.85)).

## See also

[Bidi Request and Response Schemas](https://learn.microsoft.com/previous-versions/dd183368(v=vs.85))

[IPrinterQueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueue)

[IPrinterQueue::SendBidiQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterqueue-sendbidiquery)

[IPrinterQueueEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueueevent)