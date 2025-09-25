# VMR9MixerPrefs enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `VMR9MixerPrefs` enumeration type contains flags that specify how the Video Mixing Render 9 filter (VMR-9) mixes the video streams. Settings include decimation, filtering, and render target preferences.

## Constants

### `MixerPref9_NoDecimation:0x1`

No decimation. The video will be rendered onto the surface in its native size.

### `MixerPref9_DecimateOutput:0x2`

Decimate output by 2 in the x and y directions.

### `MixerPref9_ARAdjustXorY:0x4`

Adjust the horizontal or vertical size of the video streams to match the target aspect ratio. If this flag is not present, the VMR adjusts the horizontal size only. Requires Windows XP Service Pack 2. For more information, see [Aspect Ratio Correction](https://learn.microsoft.com/windows/desktop/DirectShow/aspect-ratio-correction).

### `MixerPref9_NonSquareMixing:0x8`

Do not perform aspect ratio correction on the composited stream if the input video streams have the same aspect ratio. Requires Windows XP Service Pack 2. For more information, see [Non-Square Mixing](https://learn.microsoft.com/windows/desktop/DirectShow/non-square-mixing).

### `MixerPref9_DecimateMask:0xf`

Bitmask to isolate the flags that control decimation. (This value is not a valid flag.)

### `MixerPref9_BiLinearFiltering:0x10`

Bilinear interpolation filtering. A weighted average of a 2 x 2 area of neighboring pixels is used.

### `MixerPref9_PointFiltering:0x20`

Point filtering. The value of the nearest is pixel is used.

### `MixerPref9_AnisotropicFiltering:0x40`

Anisotropic filtering.

### `MixerPref9_PyramidalQuadFiltering:0x80`

Four-sample tent filtering.

### `MixerPref9_GaussianQuadFiltering:0x100`

Four-sample Gaussian filtering.

### `MixerPref9_FilteringReserved:0xe00`

Reserved for future use.

### `MixerPref9_FilteringMask:0xff0`

Bitmask to isolate flags that control filtering. (This value is not a valid flag.)

### `MixerPref9_RenderTargetRGB:0x1000`

Use an RGB render target.

### `MixerPref9_RenderTargetYUV:0x2000`

Indicates that the target is a YUV surface. Requires Windows XP Service Pack 2. For more information, see [YUV Mixing Mode](https://learn.microsoft.com/windows/desktop/DirectShow/yuv-mixing-mode).

### `MixerPref9_RenderTargetReserved:0xfc000`

Reserved for future use.

### `MixerPref9_RenderTargetMask:0xff000`

Bitmask to isolate flags that control the render target. (This value is not a valid flag.)

### `MixerPref9_DynamicSwitchToBOB:0x100000`

In YUV mixing mode only, this flag switches the VMR to bob deinterlacing. You can add or remove this flag while the filter graph is running; the change is applied when the VMR mixer composes the next video frame.

### `MixerPref9_DynamicDecimateBy2:0x200000`

In YUV mixing mode only, this flag causes the VMR to decimate the image by a factor of 2 horizontally and vertically. You can add or remove this flag while the filter graph is running; the change will be applied when the VMR mixer composes the next video frame.

### `MixerPref9_DynamicReserved:0xc00000`

Reserved.

### `MixerPref9_DynamicMask:0xf00000`

Bitmask to isolate the MixerPref9_DynamicSwitchToBOB and MixerPref9_DynamicDecimateBy2 flags. (This value is not a valid flag.)

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IVMRMixerControl9::GetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixercontrol9-getmixingprefs)

[IVMRMixerControl9::SetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/vmr9/nf-vmr9-ivmrmixercontrol9-setmixingprefs)