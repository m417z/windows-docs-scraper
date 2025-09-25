## Description

The **USBCAMD_DriverEntry** function registers the minidriver with USBCAMD, effectively binding USBCAMD and the minidriver together.

## Parameters

### `Context1` [in]

Pointer to the first argument that is passed to the camera minidriver's DriverEntry function. This is effectively a pointer to the driver object that is created by the system and passed to DriverEntry.

### `Context2` [in]

Pointer to the second argument that is passed to the camera minidriver's DriverEntry function. This is effectively a pointer to the registry path that describes the minidriver's registry key.

### `DeviceContextSize` [in]

Specifies the size, in bytes, required for the minidriver's device-specific context.

### `FrameCOntextSize` [in]

Specifies the size, in bytes, required for the minidriver's frame-specific context structure. Use **NULL** if not needed.

### `ReceivePacket` [in]

Pointer to the minidriver-defined [AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-padapter_receive_packet_routine) function that handles adapter-based SRB requests.

## Return value

**USBCAMD_DriverEntry** returns the status of the registration attempt. If a value other than STATUS_SUCCESS is returned, the minidriver is unloaded.

## Remarks

A camera minidriver must call **USBCAMD_DriverEntry** from the minidriver's **DriverEntry** routine. For more information, see [DriverEntry for Stream Class Minidrivers](https://learn.microsoft.com/previous-versions/ff558717(v=vs.85))

*FrameContextSize* is optional. A non-**NULL** value should be provided only with calls to [CamNewVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine) or [CamProcessRawVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine).

## See also

[AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-padapter_receive_packet_routine)

[CamNewVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine)

[CamProcessRawVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine)