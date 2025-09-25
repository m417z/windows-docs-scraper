## Description

A camera minidriver's **CamFreeBandwidthEx** callback function selects an alternate setting within the USB video streaming interface that uses no bandwidth.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `STreamNumber`

Indicates stream number.

## Return value

**CamFreeBandwidthEx** returns STATUS_SUCCESS or an appropriate error code.

## Remarks

USBCAMD calls the camera minidriver's **CamFreeBandwidthEx** callback function after the isochronous video stream has stopped.

Typically, this function calls the **USBCAMD_SelectAlternateInterface** service to select the correct alternate interface and prepare for streaming video.

The original USBCAMD does not call **CamFreeBandwidthEx**.

This function is required.

## See also

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)

[USBCAMD_SelectAlternateInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_selectalternateinterface)