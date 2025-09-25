# DXGK_CRTC_VSYNC_STATE enumeration

## Description

The **DXGK_CRTC_VSYNC_STATE** enumeration provides additional information for [**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2) when VSYNC is being utilized.

## Constants

### `DXGK_VSYNC_ENABLE:0`

Indicates that the VSYNC interrupt is enabled and will call into the interrupt callback whenever a display target enters the VBLANK state.

### `DXGK_VSYNC_DISABLE_KEEP_PHASE:1`

Indicates that the VSYNC interrupt is disabled and the display driver will ensure that any request to re-enter the VSYNC enabled state will do so in the phase of interrupts prior to disable.

### `DXGK_VSYNC_DISABLE_NO_PHASE:2`

Indicates that the VSYNC interrupt is disabled, but that the display driver will not require re-entering the VSYNC enabled state in phase of prior interrupts.

## See also

[**DxgkDdi_ControlInterrupt2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_controlinterrupt2)