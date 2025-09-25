## Description

Cancels the asynchronous operation.

## Return value

This method returns an **HRESULT** value.

## Remarks

This method guarantees that the callback object will not be invoked. No other form of status is provided, such as a way to check to see if the operation has been canceled.
Also, note that this method does not wait for the cancellation to be processed - it returns immediately.

## See also

[IPrinterExtensionAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensionasyncoperation)