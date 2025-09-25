## Description

The display miniport driver uses **DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO3** to report per-plane flip completion after a Vsync.

## Members

### `LayerIndex`

The zero-based index of the overlay plane to display. The top plane (in the z-direction) has index zero. The planes' index values must be sequential from top to bottom.

### `FirstFreeFlipQueueLogEntryIndex`

The index after the last written entry in the flip queue log buffer.

## Remarks

**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO3** is a member of the [**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data) structure. It is filled out by the driver to report each plane’s flip completion after a Vsync occurs in the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue). It should be filled out when the display adapter generates an interrupt after a Vsync.

## See also

[**DXGK_MULTIPLANE_OVERLAY_VSYNC_INFO2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_vsync_info2)

[**DXGKARGCB_NOTIFY_INTERRUPT_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_notify_interrupt_data)

[**DXGKCB_NOTIFY_INTERRUPT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_notify_interrupt)