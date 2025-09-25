# PCAM_NEW_FRAME_ROUTINE callback function

## Description

[CamNewVideoFrame is not supported and may be altered or unavailable in the future. Instead, use [CamNewVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine_ex).
]

A camera minidriver's **CamNewVideoFrame** callback function initializes a new video frame context structure.

## Parameters

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `FrameContext`

Pointer to the camera minidriver's frame context.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the camera minidriver's **CamNewVideoFrame** callback function at IRQL = DISPATCH_LEVEL.

This function is optional.

## See also

[CamNewVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine_ex)