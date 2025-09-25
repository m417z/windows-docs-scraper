# DISPLAYCONFIG_VIDEO_SIGNAL_INFO structure

## Description

The DISPLAYCONFIG_VIDEO_SIGNAL_INFO structure contains information about the video signal for a display.

## Members

### `pixelRate`

The pixel clock rate.

### `hSyncFreq`

A [DISPLAYCONFIG_RATIONAL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_rational) structure that represents horizontal sync.

### `vSyncFreq`

A [DISPLAYCONFIG_RATIONAL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_rational) structure that represents vertical sync.

### `activeSize`

A [DISPLAYCONFIG_2DREGION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that specifies the width and height (in pixels) of the active portion of the video signal.

### `totalSize`

A [DISPLAYCONFIG_2DREGION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_2dregion) structure that specifies the width and height (in pixels) of the entire video signal.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.AdditionalSignalInfo`

Supported by WDDM 1.3 and later display miniport drivers running on Windows 8.1 and later.

### `DUMMYUNIONNAME.AdditionalSignalInfo.videoStandard`

The video standard (if any) that defines the video signal. For a list of possible values, see the [D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard) enumerated type.

Supported starting with Windows 8.1.

### `DUMMYUNIONNAME.AdditionalSignalInfo.vSyncFreqDivider`

The ratio of the VSync rate of a monitor that displays through a Miracast connected session to the VSync rate of the Miracast sink.

To avoid visual artifacts, the VSync rate of the display monitor that's connected to the Miracast sink must be an integer multiple of the VSync rate of the Miracast sink. The display miniport driver reports the latter rate to the operating system as the refresh rate of the desktop present path.

**Note** The operating system fails any attempt by the driver to add a target mode that results in a Miracast target having a VSync rate below 23.9 Hz.

For a non-Miracast target, the driver should set **vSyncFreqDivider** to zero.

Supported starting with Windows 8.1.

### `DUMMYUNIONNAME.AdditionalSignalInfo.reserved`

Reserved for system use. Do not use in your driver.

Supported starting with Windows 8.1.

### `DUMMYUNIONNAME.videoStandard`

The video standard (if any) that defines the video signal. For a list of possible values, see the [D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard) enumerated type.

### `scanLineOrdering`

The scan-line ordering (for example, progressive or interlaced) of the video signal. For a list of possible values, see the [DISPLAYCONFIG_SCANLINE_ORDERING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scanline_ordering) enumerated type.

## See also

[D3DKMDT_VIDEO_SIGNAL_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dkmdt/ne-d3dkmdt-_d3dkmdt_video_signal_standard)

[DISPLAYCONFIG_2DREGION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_2dregion)

[DISPLAYCONFIG_RATIONAL](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-displayconfig_rational)

[DISPLAYCONFIG_SCANLINE_ORDERING](https://learn.microsoft.com/windows/desktop/api/wingdi/ne-wingdi-displayconfig_scanline_ordering)