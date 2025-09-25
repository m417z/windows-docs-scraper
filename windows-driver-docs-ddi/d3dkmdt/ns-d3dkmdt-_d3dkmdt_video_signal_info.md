# _D3DKMDT_VIDEO_SIGNAL_INFO structure

## Description

The D3DKMDT_VIDEO_SIGNAL_INFO structure contains information about a video signal driven by a video output on a display adapter.

## Members

### `VideoStandard`

A constant from the [D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard) enumeration that indicates the video standard (if any) that defines the video signal.

### `TotalSize`

A [D3DKMDT_2DREGION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_2dregion) structure that specifies the width and height (in pixels) of the entire video signal.

### `ActiveSize`

A D3DKMDT_2DREGION structure that specifies the width and height (in pixels) of the active portion of the video signal.

### `VSyncFreq`

A [D3DDDI_RATIONAL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_rational) structure that specifies the vertical refresh rate in Hz.

### `HSyncFreq`

A D3DDDI_RATIONAL structure that specifies the horizontal refresh rate in Hz.

### `PixelRate`

The pixel clock rate.

### `AdditionalSignalInfo`

Supported by WDDM 1.3 and later display miniport drivers running on Windows 8.1 and later.

### `AdditionalSignalInfo.ScanLineOrdering`

A constant from the [D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering) enumeration that indicates the scanline ordering (for example, progressive or interlaced) of the video signal.

Supported starting with Windows 8.1.

### `AdditionalSignalInfo.VSyncFreqDivider`

The ratio of the VSync rate of a monitor that displays through a Miracast connected session to the VSync rate of the Miracast sink.

To avoid visual artifacts, the VSync rate of the display monitor that's connected to the Miracast sink must be an integer multiple of the VSync rate of the Miracast sink. The display miniport driver reports the latter rate to the operating system as the refresh rate of the desktop present path.

**Note** The operating system fails any attempt by the driver to add a target mode that results in a Miracast target having a VSync rate below 23.9 Hz.

For a non-Miracast target, the driver should set **VSyncFreqDivider** to zero.

Supported starting with Windows 8.1.

### `AdditionalSignalInfo.Reserved`

Reserved for system use. Do not use in your driver.

Supported starting with Windows 8.1.

### `ScanLineOrdering`

A constant from the [D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_video_signal_scanline_ordering) enumeration that indicates the scanline ordering (for example, progressive or interlaced) of the video signal.

## See also

[D3DKMDT_VIDEO_PRESENT_TARGET](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_present_target)

[D3DKMDT_VIDPN_TARGET_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_vidpn_target_mode)