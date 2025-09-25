# PCAM_ALLOCATE_BW_ROUTINE_EX callback function

## Description

A camera minidriver's **CamAllocateBandwidthEx** callback function selects the appropriate alternate setting within the USB video streaming interface and prepares the device to stream.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `RawFrameLength`

Specifies the size, in bytes, of the raw frame data from the packet stream.

### `Format`

Pointer to a [KS_DATAFORMAT_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader) structure associated with this stream.

### `StreamNumber`

Specifies the stream number.

## Return value

**CamAllocateBandwidthEx** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

USBCAMD calls the camera minidriver's **CamAllocateBandwidthEx** callback function immediately before the isochronous video capture stream is started. It is called in connection with a **Run** command.

Typically, this function calls the **USBCAMD_SelectAlternateInterface** service to select the correct alternate interface and prepare for streaming video.

The original USBCAMD does not call **CamAllocateBandwidthEx**.

This function is required.

## See also

[KS_DATAFORMAT_VIDEOINFOHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_dataformat_videoinfoheader)

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)

[USBCAMD_SelectAlternateInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_selectalternateinterface)