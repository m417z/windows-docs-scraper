## Description

Uses an XML string value to send a Bidi Set request as an asynchronous operation.

This method allows the user to perform device maintenance tasks from within a UWP device app for printers.

## Parameters

### `bstrBidiRequest` [in]

XML string that is used to transfer the data for the Set request.

### `pCallback` [in]

Callback object for the Bidi Set request.

### `ppAsyncOperation` [out, retval]

Context object associated with the asynchronous Bidi Set request (operation).

## Return value

This method returns the appropriate **HRESULT** value.

## See also

[IPrinterBidiSetRequestCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterbidisetrequestcallback)

[IPrinterExtensionAsyncOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterextensionasyncoperation)

[IPrinterQueue2](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprinterqueue2)