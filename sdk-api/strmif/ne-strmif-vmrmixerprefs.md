# VMRMixerPrefs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VMRMixerPrefs** enumeration contains flags that specify decimation, filtering, and color space information that will be used when the video image is created on the DirectDraw surface.

## Constants

### `MixerPref_NoDecimation:0x1`

No decimation. The video will be rendered onto the surface in its native size.

### `MixerPref_DecimateOutput:0x2`

Decimate output by 2 in the x and y directions.

### `MixerPref_ARAdjustXorY:0x4`

Adjust the horizontal or vertical size of the video streams to match the target aspect ratio. If this flag is not present, the VMR adjusts the horizontal size only. For more information, see [Aspect Ratio Correction](https://learn.microsoft.com/windows/desktop/DirectShow/aspect-ratio-correction).

### `MixerPref_DecimationReserved:0x8`

Reserved.

### `MixerPref_DecimateMask:0xf`

Bitmask to isolate the flags that control decimation. (This value is not a valid flag.)

### `MixerPref_BiLinearFiltering:0x10`

Use bi-linear filtering. This is the default type of filtering, but not all cards can support it.

### `MixerPref_PointFiltering:0x20`

Use point filtering.

### `MixerPref_FilteringMask:0xf0`

Bitmask to isolate the flags the control filtering. (This value is not a valid flag.)

### `MixerPref_RenderTargetRGB:0x100`

The render target is an RGB surface.

### `MixerPref_RenderTargetYUV:0x1000`

The render target is a YUV surface. Requires Windows XP Service Pack 2. For more information, see [YUV Mixing Mode](https://learn.microsoft.com/windows/desktop/DirectShow/yuv-mixing-mode).

### `MixerPref_RenderTargetYUV420:0x200`

The render target is a YUV 4:2:0 surface.

**Note** Deprecated.

### `MixerPref_RenderTargetYUV422:0x400`

The render target is a YUV 4:2:2 surface.

**Note** Deprecated.

### `MixerPref_RenderTargetYUV444:0x800`

The render target is a YUV 4:4:4 surface.

**Note** Deprecated.

### `MixerPref_RenderTargetReserved:0xe000`

Reserved.

### `MixerPref_RenderTargetMask:0xff00`

Bitmask to isolate flags that control the render target. (This value is not a valid flag.)

### `MixerPref_DynamicSwitchToBOB:0x10000`

In YUV mixing mode only, this flag switches the VMR to bob deinterlacing. You can add or remove this flag while the filter graph is running; the change will be applied when the VMR mixer composes the next video frame.

### `MixerPref_DynamicDecimateBy2:0x20000`

In YUV mixing mode only, this flag causes the VMR to decimate the image by a factor of 2 horizontally and vertically. You can add or remove this flag while the filter graph is running; the change is applied when the VMR mixer composes the next video frame.

### `MixerPref_DynamicReserved:0xc0000`

Reserved.

### `MixerPref_DynamicMask:0xf0000`

Bitmask to isolate the MixerPref_DynamicSwitchToBOB and MixerPref_DynamicDecimateBy2 flags. (This value is not a valid flag.)

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRMixerControl::GetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixercontrol-getmixingprefs)

[IVMRMixerControl::SetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrmixercontrol-setoutputrect)