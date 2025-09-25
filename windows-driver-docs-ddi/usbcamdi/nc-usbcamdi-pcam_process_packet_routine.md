# PCAM_PROCESS_PACKET_ROUTINE callback function

## Description

[CamProcessUSBPacket is not supported and may be altered or unavailable in the future. Instead, use CamProcessUSBPacketEx.
]

A camera minidriver's **CamProcessUSBPacket** callback function processes a USB packet.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `CurrentFrameContext`

Pointer to the minidriver's frame context.

### `SyncPacket`

Pointer to a [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) structure from the sync pipe. This value is **NULL** if the interface has only one pipe.

### `SyncBuffer`

Pointer to the data for the *SyncPacket.*

### `DataPacket`

Pointer to a [USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) structure from the data pipe.

### `DataBuffer`

Pointer to *DataPacket.*

### `FrameComplete`

Pointer to a BOOLEAN value that the camera minidriver sets to indicate whether this is the first data packet for a new video frame. Set to **TRUE** if this is the first data packet for a new video frame.

### `NextFrameIsStill`

Pointer to a BOOLEAN value that the camera minidriver sets to indicate whether the next frame is a still frame or not. This value should be set to **FALSE** if the video stream is providing a live image or **TRUE** if the next frame is a still image or an image capture stream.

## Return value

This callback function returns a ULONG that indicates the number of bytes that should be copied into the buffer (*RawFrameBuffer* or *FrameBuffer)*.

## Remarks

Camera minidrivers that must maintain backward compatibility with the original USBCAMD must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure and its associated callback functions (that is, callback functions that do not contain the "Ex" suffix).

The minidriver should complete this function as quickly as possible. Image processing should be deferred to the [CamProcessRawVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine) function.

This function is optional.

## See also

[CamProcessRawVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine)

[CamProcessUSBPacketEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_packet_routine_ex)

[USBD_ISO_PACKET_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor)