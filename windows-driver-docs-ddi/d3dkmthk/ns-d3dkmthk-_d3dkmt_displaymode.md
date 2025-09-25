# _D3DKMT_DISPLAYMODE structure

## Description

The D3DKMT_DISPLAYMODE structure describes a display mode.

## Members

### `Width` [out]

The screen width of the display mode, in pixels.

### `Height` [out]

The screen height of the display mode, in pixels.

### `Format` [out]

A [D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)-typed value that indicates the pixel format of the display mode.

### `IntegerRefreshRate` [out]

A UINT value that indicates the refresh rate of the display mode.

### `RefreshRate` [out]

A [D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational) structure that indicates the refresh rate of the display mode.

### `ScanLineOrdering` [out]

A [D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering)-typed value that indicates how scan lines are ordered in the display mode.

### `DisplayOrientation` [out]

A [D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)-typed value that identifies the orientation of the display mode.

### `DisplayFixedOutput` [out]

The fixed output of the display mode.

### `Flags` [out]

A [D3DKMDT_DISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmdt_displaymode_flags) structure that indicates information about the display mode.

## See also

[D3DDDIFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddiformat)

[D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational)

[D3DDDI_ROTATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_rotation)

[D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering)

[D3DKMDT_DISPLAYMODE_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmdt_displaymode_flags)

[D3DKMTGetDisplayModeList](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdisplaymodelist)

[D3DKMT_GETDISPLAYMODELIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdisplaymodelist)