# DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2 structure

## Description

The **DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2** structure is used by display miniport drivers to report per-plane flip completion after a VSYNC.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `PresentId`

The video present source ID provided during a [**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3) call.

### `Flags`

A [**DXGKCB_NOTIFY_MPO_VSYNC_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_notify_mpo_vsync_flags) structure containing driver-set flags. These flags are used to determine whether the scheduler should call [**DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_postmultiplaneoverlaypresent) for this plane.

## Remarks

**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2** is a member of the [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure. It is filled out by the driver to report each plane’s flip completion after a VSYNC occurs. It should be filled out when the display adapter generates an interrupt after a VSYNC.

## See also

[**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_multiplane_overlay_vsync_info3)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)

[**DXGKCB_NOTIFY_MPO_VSYNC_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkcb_notify_mpo_vsync_flags)

[**DXGKDDI_POSTMULTIPLANEOVERLAYPRESENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_postmultiplaneoverlaypresent)

[**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)