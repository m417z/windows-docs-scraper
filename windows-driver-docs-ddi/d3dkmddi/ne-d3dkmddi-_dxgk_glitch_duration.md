# DXGK_GLITCH_DURATION enumeration

## Description

Enumeration that describes the duration of a user visible effect of a glitch during a [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call.

## Constants

### `DXGK_GLITCH_DURATION_INDEFINITE`

Indicates that a glitch is unresolved.

### `DXGK_GLITCH_DURATION_MULTI_FRAME`

Indicates that a glitch lasted for multiple frames.

### `DXGK_GLITCH_DURATION_SINGLE_FRAME`

Indicates that a glitch lasted for no more than one frame.

### `DXGK_GLITCH_DURATION_MULTI_LINE`

Indicates that a glitch lasted for multiple lines within a frame.

### `DXGK_GLITCH_DURATION_SINGLE_LINE`

Indicates that a glitch lasted for no more than one line.

### `DXGK_GLITCH_DURATION_NONE`

Indicates that there was no user visible glitch.

## See also

[**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info)

[**DXGKDDI_SETTIMINGSFROMVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn)