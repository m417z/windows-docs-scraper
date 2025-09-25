# PCAM_ALLOCATE_BW_ROUTINE callback function

## Description

[CamAllocateBandwidth is not supported and may be altered or unavailable in the future. Instead, use [CamAllocateBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_allocate_bw_routine_ex).
]

A camera minidriver's **CamAllocateBandwidth** callback function selects the appropriate alternate setting within the USB video streaming interface and prepares the device to stream.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `RawFrameLength`

Specifies the size, of the raw frame data from the packet stream, in bytes.

### `Format`

Pointer to a [KS_DATAFORMAT_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader) structure that is associated with this stream.

## Return value

**CamAllocateBandwidth** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

USBCAMD calls the camera minidriver's **CamAllocateBandwidth** callback function immediately before the isochronous video capture stream is started. It is called in connection with a **Run** command.

Typically, this function calls the **USBCAMD_SelectAlternateInterface** service to select the correct alternate interface and prepare for streaming video.

This function is required.

## See also

[CamAllocateBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_allocate_bw_routine_ex)

[KS_DATAFORMAT_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader)

[USBCAMD_SelectAlternateInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_selectalternateinterface)