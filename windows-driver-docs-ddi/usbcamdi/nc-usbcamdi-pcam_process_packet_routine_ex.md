## Description

A camera minidriver's **CamProcessUSBPacketEx** callback function processes a USB packet.

## Parameters

### `BusDeviceObject`

Pointer to the camera minidriver's device object created by the USB hub.

### `DeviceContext`

Pointer to the camera minidriver's device context.

### `CurrentFrameContext`

Pointer to the camera minidriver's frame context.

### `SyncPacket`

Pointer to a [**USBD_ISO_PACKET_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor) structure from the sync pipe. This value is **NULL** if the interface has only one pipe.

### `SyncBuffer`

Pointer to the data for the *SyncPacket*.

### `DataPacket`

Specifies the isochronous packet descriptor from data pipe.

### `DataBuffer`

Pointer to *DataPacket.*

### `FrameComplete`

Pointer to a BOOLEAN value that the camera minidriver sets to indicate whether this is the first data packet for a new video frame.

### `PacketFlag`

Pointer to a value that the minidriver sets to indicate the contents of the current frame. It should be set to one of the following values:

| Flag | Meaning |
|---|---|
| USBCAMD_PROCESSPACKETEX_DropFrame | The current frame is unsalvageable. The read IRP should be recycled. |
| USBCAMD_PROCESSPACKETEX_NextFrameIsStill | The frame is a still image. |
| USBCAMD_PROCESSPACKETEX_CurrentFrameIsStill | The current frame is for the still pin. |

### `ValidDataOffset`

Pointer to a ULONG value that indicates an offset from the beginning of the packet. USBCAMD should start the copy from this offset. This eliminates the extra buffer copy in the case of an in-band signal. If the camera is not using in-band signaling, *ValidDataOffset* should be set to zero.

## Return value

This function returns the number of bytes that should be copied.

## Remarks

The minidriver should complete its **CamProcessUSBPacketEx** function as quickly as possible. Image processing should be deferred to the [CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex) function.

This callback function is used with isochronous pipes only (video or still streaming).

The original USBCAMD does not call **CamProcessUSBPacketEx**.

This function is optional.

## See also

[CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex)

[**USBD_ISO_PACKET_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usb/ns-usb-_usbd_iso_packet_descriptor)