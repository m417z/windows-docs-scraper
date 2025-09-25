# DXGKDDI_OPM_CREATE_PROTECTED_OUTPUT callback function

## Description

The *DxgkDdiOPMCreateProtectedOutput* function creates a new protected output object with Certified Output Protection Protocol (COPP) or OPM semantics.

## Parameters

### `MiniportDeviceContext` [in]

A handle to a context block associated with a display adapter. Previously, the display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function provided this handle to the DirectX graphics kernel subsystem.

### `VidPnTargetId` [in]

An integer that uniquely identifies the video present target that corresponds to the new protected output object. Each video present target must correspond to one physical monitor connector. If *VidPnTargetId* corresponds to multiple physical monitor connectors, *DxgkDdiOPMCreateProtectedOutput* should return the STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED or STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED error code.

### `NewVideoOutputSemantics` [in]

A [DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_video_output_semantics)-typed value that determines whether the new protected output has COPP or OPM semantics.

### `NewProtectedOutputHandle` [out]

A pointer to a variable that receives the handle to the new protected output object if *DxgkDdiOPMCreateProtectedOutput* returns successfully. The DirectX graphics kernel subsystem passes this handle in calls to the display miniport driver's [DxgkDdiOPMGetRandomNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_random_number), [DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)
[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information), [DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information), [DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output), and [DxgkDdiOPMDestroyProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_destroy_protected_output).

If *DxgkDdiOPMCreateProtectedOutput* fails, the value of the variable is unchanged.

## Return value

*DxgkDdiOPMCreateProtectedOutput* returns one of the following values.

|Return code|Description|
|--- |--- |
|STATUS_SUCCESS|The function successfully created a new protected output object.|
|STATUS_GRAPHICS_OPM_NOT_SUPPORTED|The display miniport driver does not support OPM either because the hardware vendor never signed the OPM license agreement or the miniport driver's graphics hardware does not comply with OPM rules.|
|STATUS_GRAPHICS_COPP_NOT_SUPPORTED|The display miniport driver does not support COPP either because the hardware vendor never signed the COPP license agreement or the miniport driver's graphics hardware does not comply with COPP rules.|
|STATUS_NO_MEMORY|DxgkDdiOPMCreateProtectedOutput cannot allocate memory required for it to complete.|
|STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED|DxgkDdiOPMCreateProtectedOutput could not create a protected output because the video present target is in spanning mode. When the video present target is in spanning mode, it corresponds to multiple physical monitor connectors and each connector displays a separate part of the frame buffer. For a diagram of how the display miniport driver typically implements spanning mode, see the Remarks section. The display miniport driver informs the operating system on how the frame buffer corresponds to a particular monitor. The left half of the frame buffer is displayed on one monitor, and the right half of the frame buffer is displayed on the other monitor.|
|STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED|DxgkDdiOPMCreateProtectedOutput could not create a protected output because the video present target is in theater mode. When the video present target is in theater mode, it corresponds to two physical monitor connectors; one connector displays the entire frame buffer and the other connector displays only part of the frame buffer. Theater mode is also known as mirror mode. For a diagram of how the display miniport driver typically implements theater mode, see the Remarks section. The display miniport driver informs the operating system on how the frame buffer corresponds to a particular monitor. The entire frame buffer is displayed on one monitor, and only part of the frame buffer is displayed on the other monitor.|

This function might also return other error codes that are defined in Ntstatus.h.

## Remarks

The following figure shows how the display miniport driver typically implements spanning mode.

![Diagram illustrating spanning mode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/images/opm_span.png)
The following figure shows how the display miniport driver typically implements theater mode.

![Diagram illustrating theater mode](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/images/opm_theater.png)
*DxgkDdiOPMCreateProtectedOutput* should be made pageable.

## See also

[DXGKMDT_OPM_VIDEO_OUTPUT_SEMANTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_dxgkmdt_opm_video_output_semantics)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiOPMConfigureProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_configure_protected_output)

[DxgkDdiOPMDestroyProtectedOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_destroy_protected_output)

[DxgkDdiOPMGetCOPPCompatibleInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_copp_compatible_information)

[DxgkDdiOPMGetInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_information)

[DxgkDdiOPMGetRandomNumber](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_get_random_number)

[DxgkDdiOPMSetSigningKeyAndSequenceNumbers](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_opm_set_signing_key_and_sequence_numbers)