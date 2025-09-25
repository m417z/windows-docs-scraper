# PCAM_STOP_CAPTURE_ROUTINE callback function

## Description

[CamStopCapture is not supported and may be altered or unavailable in the future. Instead, use [CamStopCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_stop_capture_routine_ex).
]

A camera minidriver's **CamStopCapture** callback function performs any processing after the stream is stopped.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

## Return value

**CamStopCapture** returns STATUS_SUCCESS or an appropriate error code. This return value is the completion code for the read IRP.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the minidriver's **CamStopCapture** callback function immediately after the isochronous video stream is stopped. Typically, a camera minidriver selects an alternate setting within the USB video streaming interface that uses no additional bandwidth.

This function is required.

## See also

[CamStopCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_stop_capture_routine_ex)

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)