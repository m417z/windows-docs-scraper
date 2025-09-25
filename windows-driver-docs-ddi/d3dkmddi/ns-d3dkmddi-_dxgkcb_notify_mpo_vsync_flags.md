# DXGKCB_NOTIFY_MPO_VSYNC_FLAGS structure

## Description

The **DXGKCB_NOTIFY_MPO_VSYNC_FLAGS** structure contains the flags set by the driver to process a flip entry.

## Members

### `PostPresentNeeded`

The driver sets this flag to indicate that scheduler must call [**DxgkDdiPostMultiplaneOverlayPresent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_postmultiplaneoverlaypresent) for this flip entry.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

The 32-bit value that indicates all of the flags set in the union.

## See also

[**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_vsync_info2)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)