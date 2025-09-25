# _USBCAMD_DEVICE_DATA structure

## Description

This structure is **obsolete** and is provided to maintain backward compatibility with the original USBCAMD. New camera minidrivers should use the [USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2) structure.

The USBCAMD_DEVICE_DATA structure specifies the entry points for a camera minidriver's functions that the original USBCAMD calls.

## Members

### `Sig`

Reserved. Do not use.

### `CamInitialize`

Pointer to the camera minidriver defined [CamInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_initialize_routine) callback function. This entry point is required.

### `CamUnInitialize`

Pointer to the camera minidriver defined [CamUnInitialize](https://learn.microsoft.com/previous-versions/ff557646(v=vs.85)) callback function. This entry point is required.

### `CamProcessUSBPacket`

Pointer to the camera minidriver defined [CamProcessUSBPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_packet_routine) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamNewVideoFrame`

Pointer to the camera minidriver defined [CamNewVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamProcessRawVideoFrame`

Pointer to the camera minidriver defined [CamProcessRawVideoFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamStartCapture`

Pointer to the camera minidriver defined [CamStartCapture](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_start_capture_routine) callback function. This entry point is required.

### `CamStopCapture`

Pointer to the camera minidriver defined [CamStopCapture](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_stop_capture_routine) callback function. This entry point is required.

### `CamConfigure`

Pointer to the camera minidriver defined [CamConfigure](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine) callback function. This entry point is required.

### `CamSaveState`

Pointer to the camera minidriver defined [CamSaveState](https://learn.microsoft.com/previous-versions/ff557635(v=vs.85)) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamRestoreState`

Pointer to the camera minidriver defined [CamRestoreState](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_state_routine) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamAllocateBandwidth`

Pointer to the camera minidriver defined [CamAllocateBandwidth](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_allocate_bw_routine) callback function. This entry point is required.

### `CamFreeBandwidth`

Pointer to the camera minidriver defined [CamFreeBandwidth](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_free_bw_routine) callback function. This entry point is required.

## Remarks

A camera minidriver passes a USBCAMD_DEVICE_DATA structure to USBCAMD as a parameter to the USBCAMD library routine [USBCAMD_AdapterReceivePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_adapterreceivepacket) in the original USBCAMD.

## See also

[USBCAMD_DEVICE_DATA2](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data2)