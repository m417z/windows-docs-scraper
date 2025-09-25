# DXGK_GLITCH_EFFECT enumeration

## Description

Enumeration which describes the user visible effect of a glitch during a [**SetTimingsFromVidPn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn) call.

## Constants

### `DXGK_GLITCH_EFFECT_SYNC_LOSS`

Indicates that the display connected to the target lost sync due to a glitch. Even a short sync loss will likely lead to the user seeing a black screen while the display device re-syncs.

### `DXGK_GLITCH_EFFECT_GARBAGE_CONTENT`

Indicates that garbage content was sent to the display connected to the target due to a glitch. Garbage content will be very noticeable to a user.

### `DXGK_GLITCH_EFFECT_STALE_CONTENT`

Indicates that stale content was sent to the display connected to the target due to a glitch. Display of stale content would cause the affected pixel area to appear frozen.

### `DXGK_GLITCH_EFFECT_BLACK_CONTENT`

Indicates that black content was sent to the display connected to the target due to a glitch. If the content was black, as would be the case when initializing the display, this will be imperceptible; otherwise it is likely that black content will be noticeable to a user.

### `DXGK_GLITCH_EFFECT_DEGRADED_CONTENT`

Indicates that degraded content was sent to the display connected to the target due to a glitch. Degraded content would include pixels which are too bright or too dim or which are displayed using a slightly different color space than intended. Short durations would likely go unnoticed.

### `DXGK_GLITCH_EFFECT_SEAMLESS`

Indicates that there was no user visible glitch.

## See also

[**DXGK_SET_TIMING_PATH_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_set_timing_path_info)

[**DXGKDDI_SETTIMINGSFROMVIDPN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_settimingsfromvidpn)