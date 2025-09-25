# PCAM_FREE_BW_ROUTINE callback function

## Description

[CamFreeBandwidth is not supported and may be altered or unavailable in the future. Instead, use [CamFreeBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_free_bw_routine_ex).
]

A camera minidriver's **CamFreeBandwidth** callback function selects an alternate setting within the USB video streaming interface that uses no bandwidth.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

## Return value

**CamFreeBandwidth** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the camera minidriver's **CamFreeBandwidth** callback function after the isochronous video stream has stopped.

Typically, this function calls the **USBCAMD_SelectAlternateInterface** service to select the correct alternate interface and prepare for streaming video.

This function is required.

## See also

[CamFreeBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_free_bw_routine_ex)

[USBCAMD_SelectAlternateInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_selectalternateinterface)