# WdfRequestGetRequestorProcessId function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetRequestorProcessId** method retrieves the identifier of the process that sent an I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetRequestorProcessId** returns the identifier of the process that sent the I/O request.

## See also

[WdfFileObjectGetInitiatorProcessId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffileobject/nf-wdffileobject-wdffileobjectgetinitiatorprocessid)