# PFNUSBCAMD_BulkReadWrite callback function

## Description

The **USBCAMD_BulkReadWrite** service performs a read or write operation on the specified bulk pipe.

## Parameters

### `DeviceContext` [in]

Pointer to the camera minidriver's device context.

### `PipeIndex` [in]

Specifies the index of the bulk pipe.

### `Buffer` [in]

Pointer to the read or write buffer. If this parameter is set to **NULL** for a read request, USBCAMD pulls a data SRB from the SRB read queue of the stream associated with this pipe. Write requests with a **NULL** buffer pointer are only permitted on the still pin if an SRB_WRITE_DATA request has been submitted to the still pin.

### `BufferLength` [in]

Specifies the length of the read/write buffer in bytes.

### `CommandComplete` [in]

Pointer to a camera minidriver defined [CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function), which is called when the bulk read or write is completed. This value can be **NULL**.

### `CommandContext` [in]

Pointer to a block of memory, that is passed as an argument to the camera minidriver defined [CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function).

## Return value

**USBCAMD_BulkReadWrite** returns STATUS_SUCCESS if the call was successful. Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_FILE_CLOSED** | The device has been removed. |
| **STATUS_INVALID_PARAMETER** | USBCAMD may return STATUS_INVALID_PARAMETER for a number of reasons, including:<br><br>The value passed in the *PipeIndex* argument is invalid.<br><br>The type of the pipe specified by the *PipeIndex* argument represents an invalid type of pipe.<br><br>A bulk read/write request already exists. The *Buffer* argument is **NULL**. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient resources to schedule a transfer. |

## Remarks

USBCAMD can accept one read and one write request at a time.

**USBCAMD_BulkReadWrite** is not available in USBCAMD version 1.0.

## See also

[CommandCompleteFunction](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcommand_complete_function)

[**USBCAMD_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-usbcamd_interface)