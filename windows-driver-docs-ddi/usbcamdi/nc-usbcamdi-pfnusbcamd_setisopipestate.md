## Description

The **USBCAMD_SetIsoPipeState** service permits the camera minidriver to control the streaming state on the isochronous pipe.

## Parameters

### `DeviceContext` [in]

Pointer to device-specific context.

### `PipeStateFlags` [in]

Specifies the isochronous pipe state. This argument should be set to either of the following values:

| Flag | Meaning |
|---|---|
| USBCAMD_STOP_STREAM | This flags indicates to stop streaming. |
| USBCAMD_START_STREAM | This flags indicates to start streaming. |

## Return value

**USBCAMD_SetIsoPipeState** returns STATUS_SUCCESS if the call was successful. Other possible error codes include:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The requested pipe state is the same as the current pipe state. |
| **STATUS_PENDING** | The pipe state change is deferred. |
| **STATUS_INSUFFICIENT_RESOURCES** | There are insufficient resources to allocate a work item to change the pipe state. |

## Remarks

Note that the streaming state on the isochronous pipe works differently from the streaming state in the stream class and in Microsoft DirectShow. It is possible to stop the isochronous pipe from streaming for a short period while the overall video capture graph is still in a Run state.

This function is used to enable dual-mode cameras. In a dual-mode camera, if there is a request to get still data while streaming is in progress, the stream must be stopped on the isochronous pipe. The still call is then serviced and then the isochronous stream must be restarted, all while the overall stream class/DirectShow graph is still in a **Run** state.

Using this function does not enable you to change the alternate setting within the USB video streaming interface or the channel bandwidth. The isochronous stream must be closed before the alternate setting is changed.

**USBCAMD_SetIsoPipeState** is not available in USBCAMD version 1.0.

## See also

[USBCAMD_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-usbcamd_interface)