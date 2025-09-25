# EVT_NFC_CX_DEVICE_IO_CONTROL callback function

## Description

Called by the NFC CX to send an unhandled IOCTL to the client driver.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `Request` [in]

A handle to a framework request object.

### `OutputBufferLength` [in]

The length, in bytes, of the request's output buffer, if an output buffer is available.

### `InputBufferLength` [in]

The length, in bytes, of the request's input buffer, if an input buffer is available.

### `IoControlCode` [in]

The driver-defined or system-defined I/O control code ([IOCTL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)) that is associated with the request.

## Remarks

The client can complete the request either synchronously or asynchronously. The NFC CX will complete the request if a status code other than STATUS_PENDING is returned by the client. To prevent request double completion, the client should not complete the WDFREQUEST (that is, call [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) or [WdfRequestCompleteWithInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcompletewithinformation)) if it returns STATUS_SUCCESS or a failure status code.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)