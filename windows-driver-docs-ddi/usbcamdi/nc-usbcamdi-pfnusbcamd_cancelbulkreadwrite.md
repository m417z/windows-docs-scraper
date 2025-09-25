## Description

The **USBCAMD_CancelBulkReadWrite** service cancels a pending bulk read or write request.

## Parameters

### `DeviceContext` [in]

Pointer to device-specific context.

### `PipeIndex` [in]

Specifies the index of the bulk pipe to cancel the read or write request.

## Return value

**USBCAMD_CancelBulkReadWrite** returns STATUS_SUCCESS if the call was successful. Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | USBCAMD may return STATUS_INVALID_PARAMETER for a number of reasons, including: The value passed in the *PipeIndex* argument is invalid, the type of the pipe specified by the *PipeIndex* argument represents an invalid type of pipe, or the current IRQL \>= DISPATCH_LEVEL. |

## Remarks

**USBCAMD_CancelBulkReadWrite** is not available in USBCAMD version 1.0.

## See also

[**USBCAMD_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-usbcamd_interface)