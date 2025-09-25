# _USBCAMD_DEVICE_DATA2 structure

## Description

The USBCAMD_DEVICE_DATA2 structure specifies the entry points for a camera minidriver's functions that USBCAMD calls.

## Members

### `Sig`

Reserved. Do not use.

### `CamInitialize`

Pointer to the camera minidriver defined [CamInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_initialize_routine) callback function. This entry point is required.

### `CamUnInitialize`

Pointer to the camera minidriver defined [CamUnInitialize](https://learn.microsoft.com/previous-versions/ff557646(v=vs.85)) callback function. This entry point is required.

### `CamProcessUSBPacketEx`

Pointer to the camera minidriver defined [CamProcessUSBPacketEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_packet_routine_ex) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamNewVideoFrameEx`

Pointer to the camera minidriver defined [CamNewVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine_ex) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamProcessRawVideoFrameEx`

Pointer to the camera minidriver defined [CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamStartCaptureEx`

Pointer to the camera minidriver defined [CamStartCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_start_capture_routine_ex) callback function. This entry point is required.

### `CamStopCaptureEx`

Pointer to the camera minidriver defined [CamStopCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_stop_capture_routine_ex) callback function. This entry point is required.

### `CamConfigureEx`

Pointer to the camera minidriver defined [CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex) callback function. This entry point is required.

### `CamSaveState`

Pointer to the camera minidriver defined [CamSaveState](https://learn.microsoft.com/previous-versions/ff557635(v=vs.85)) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamRestoreState`

Pointer to the camera minidriver defined [CamRestoreState](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_state_routine) callback function. This is an optional entry point. If the minidriver does not implement this function, it must point to an empty function.

### `CamAllocateBandwidthEx`

Pointer to the camera minidriver defined [CamAllocateBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_allocate_bw_routine_ex) callback function. This entry point is required.

### `CamFreeBandwidthEx`

Pointer to the camera minidriver defined [CamFreeBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_free_bw_routine_ex) callback function. This entry point is required.

## Remarks

A camera minidriver passes a USBCAMD_DEVICE_DATA2 structure to USBCAMD as a parameter to USBCAMD service [USBCAMD_InitializeNewInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_initializenewinterface).

Camera minidrivers that must be backward compatible with the original USBCAMD library must use the [USBCAMD_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/ns-usbcamdi-_usbcamd_device_data) structure.

## See also

[CamAllocateBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_allocate_bw_routine_ex)

[CamConfigureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_configure_routine_ex)

[CamFreeBandwidthEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_free_bw_routine_ex)

[CamInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_initialize_routine)

[CamNewVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_new_frame_routine_ex)

[CamProcessRawVideoFrameEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_raw_frame_routine_ex)

[CamProcessUSBPacketEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_process_packet_routine_ex)

[CamRestoreState](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_state_routine)

[CamSaveState](https://learn.microsoft.com/previous-versions/ff557635(v=vs.85))

[CamStartCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_start_capture_routine_ex)

[CamStopCaptureEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nc-usbcamdi-pcam_stop_capture_routine_ex)

[CamUnInitialize](https://learn.microsoft.com/previous-versions/ff557646(v=vs.85))

[USBCAMD_InitializeNewInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbcamdi/nf-usbcamdi-usbcamd_initializenewinterface)