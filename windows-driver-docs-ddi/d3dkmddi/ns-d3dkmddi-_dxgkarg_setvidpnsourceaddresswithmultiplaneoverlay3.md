# DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3 structure

## Description

**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3** contains arguments for the [**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3) function.

## Members

### `VidPnSourceId`

An integer that identifies a video present source on the display adapter.

### `InputFlags`

A [**DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_input_flags) structure that identifies the type of display operation to perform.

### `OutputFlags`

A [**DXGK_SETVIPNSOURCEADDRESS_OUTPUT_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_output_flags) structure that returns information from the driver.

### `PlaneCount`

The number of overlay planes in the **ppPlanes** list.

### `ppPlanes`

An array of pointers to a [**DXGK_MULTIPLANE_OVERLAY_PLANE3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane3) structures that specify the overlay planes to display.

### `pPostComposition`

Pointer to a [**DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_post_composition) structure containing virtual mode information and other transform information that should be applied after the planes have been composed.

If NULL, no post composition transforms should be applied.

### `Duration`

The length of time, in units of 100 nanoseconds, between when the current present operation flips to the screen and the next vertical blanking interrupt occurs.

If zero, the refresh rate should be the default rate based on the current mode.

### `pHDRMetaData`

Pointer to a [**DXGK_HDR_METADATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_hdr_metadata) structure indicating any metadata information that might be available. A NULL value indicates that no new metadata is available.

### `TargetFlipTime`

Value that describes the target flip time in QPC units. When the clock reaches this value, the frame is allowed to be sent to the display while honoring VSync and tearing flags. See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

## See also

[**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)