## Description

The **USBCAMD_InitializeNewInterface** function provides USBCAMD with all the necessary information to configure the camera minidriver to work correctly with the stream class driver and the USB bus driver.

## Parameters

### `DeviceContext` [in]

Pointer to device-specific context.

### `DeviceData` [in]

Pointer to a [**USBCAMD_DEVICE_DATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2) structure.

### `Version` [in]

Specifies the version information. This value should be set to the value USBCAMD_VERSION_200 for use with USBCAMD version 2.0.

### `CamControlFlag` [in]

Specifies how USBCAMD and the camera minidriver should interact. The camera minidriver should set this value to one or more of the following:

| Flag | Meaning |
|---|---|
| USBCAMD_CamControlFlag_NoVideoRawProcessing | If the camera minidriver does not need to operate on video, it should set the USBCAMD_CamControlFlag_NoVideoRawProcessing. This eliminates one buffer copy. |
| USBCAMD_CamControlFlag_NoStillRawProcessing | If the camera minidriver does not need to operate on the still image raw frame, it should set the USBCAMD_CamControlFlag_NoStillRawProcessing bit to eliminate one buffer copy. |
| USBCAMD_CamControlFlag_AssociatedFormat | The USBCAMD_CamControlFlag_AssociatedFormat bit should be set if the camera minidriver uses the same format for video as it does on the virtual still pin. After this flag is set, USBCAMD does not permit the virtual still pin to be opened in a format different from the video pin. The USBCAMD_CamControlFlag_AssociatedFormat bit should be set only when the virtual still pin produces frames of the same format as the video frames. |
| USBCAMD_CamControlFlag_EnableDeviceEvents | Setting the USBCAMD_CamControlFlag_EnableDeviceEvents exposes a device event to the stream class driver and Microsoft DirectShow. This enables an STI monitor to launch a still image application if the still button is pressed on the camera. USBCAMD sends a [KSEVENT_VIDCAPTOSTI_EXT_TRIGGER](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-vidcaptosti-ext-trigger) event if this bit is set and the camera's still button is pressed. |

## Return value

**USBCAMD_InitializeNewInterface** returns the value USBCAMD_VERSION_200.

## Remarks

This function is only called by USBCAMD version 2.0.

The **USBCAMD_InitializeNewInterface** function must be called by the camera minidriver upon receiving an [SRB_INITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialize-device) request.

## See also

[SRB_INITIALIZE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialize-device)

[**USBCAMD_DEVICE_DATA2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)