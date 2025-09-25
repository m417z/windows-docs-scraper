# PCAM_START_CAPTURE_ROUTINE callback function

## Description

[CamStartCapture is not supported and may be altered or unavailable in the future. Instead, use [CamStartCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_start_capture_routine_ex).
]

A camera minidriver's **CamStartCapture** callback function selects the appropriate alternate setting within the USB video streaming interface and prepares the device to stream.

## Parameters

### `BusDeviceObject`

Pointer to camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to camera minidriver's device context.

## Return value

**CamStartCapture** returns STATUS_SUCCESS or an appropriate error code. This return value is the completion code for the read IRP.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the camera minidriver's **CamStartCapture** callback function immediately prior to the start of the isochronous video capture stream. **CamStartCapture** is called in the context of a **Run** command.

This function is required.

## See also

[CamStartCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_start_capture_routine_ex)

[USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data)

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)