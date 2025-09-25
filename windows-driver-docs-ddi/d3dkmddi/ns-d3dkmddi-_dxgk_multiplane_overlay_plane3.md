# _DXGK_MULTIPLANE_OVERLAY_PLANE3 structure

## Description

Specifies an overlay plane to display in a call to the [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3) function.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `PresentId`

A 64 bit per-plane identifier used by the driver to report completion of the overlay command.

### `InputFlags`

A [DXGK_PLANE_SPECIFIC_INPUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_input_flags) structure that identifies any plane specific display operations to perform.

### `OutputFlags`

A [DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_output_flags) structure containing status returned by the driver.

### `MaxImmediateFlipLine`

The display line delineating whether a VSYNC flip should be promoted to an immediate flip, where line 0 corresponds to the first active pixel of the frame. This value is ignored for non-VSYNC flips.

This value is -1 when promotion from a VSYNC flip to an immediate flip is not desired. In this case, the flip will always wait for the next VSYNC.

For a value other than -1, the driver should promote this flip to an immediate flip if the HW has not yet started reading from the specified display line. Values of 0 can be promoted to immediate flips if the HW has latched registers for the current display frame but has not yet started scanning the first active pixel.

The display line value is relative to the physical mode that is set. If the display is performing scaling, display line is relative to the size after scaling has been applied.

When a VSYNC flip is promoted to an immediate flip, the driver should set [DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_plane_specific_output_flags). FlipConvertedToImmediate to TRUE.

### `ContextCount`

The number of contexts in the array that the Context member specifies.

### `ppContextData`

An array of handles to the contexts that contributed to a display operation.

### `DriverPrivateDataSize`

The size of the private driver data.

### `pDriverPrivateData`

Private driver data.

### `PlaneAttributes`

A structure of type [DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES3](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_attributes3) that specifies overlay plane attributes.