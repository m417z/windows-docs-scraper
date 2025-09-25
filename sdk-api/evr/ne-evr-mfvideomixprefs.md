# MFVideoMixPrefs enumeration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Contains flags that are used to configure how the enhanced video renderer (EVR) performs deinterlacing.

## Constants

### `MFVideoMixPrefs_ForceHalfInterlace:0x1`

Force the EVR to skip the second field (in temporal order) of every interlaced frame.

### `MFVideoMixPrefs_AllowDropToHalfInterlace:0x2`

If the EVR is falling behind, allow it to skip the second field (in temporal order) of every interlaced frame.

### `MFVideoMixPrefs_AllowDropToBob:0x4`

If the EVR is falling behind, allow it to use bob deinterlacing, even if the driver supports a higher-quality deinterlacing mode.

### `MFVideoMixPrefs_ForceBob:0x8`

Force the EVR to use bob deinterlacing, even if the driver supports a higher-quality mode.

### `MFVideoMixPrefs_EnableRotation:0x10`

### `MFVideoMixPrefs_Mask:0x1f`

The bitmask of valid flag values. This constant is not itself a valid flag.

## Remarks

To set these flags, call the [IMFVideoMixerControl2::SetMixingPrefs](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideomixercontrol2-setmixingprefs) method.

These flags control some trade-offs between video quality and rendering speed. The constants named "MFVideoMixPrefs_Allow..." enable lower-quality settings, but only when the quality manager requests a drop in quality. The constants named "MFVideoMixPrefs_Force..." force the EVR to use lower-quality settings regardless of what the quality manager requests. (For more information about the quality manager, see [IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise).)

Currently two lower-quality modes are supported, as described in the following table. Either is preferable to dropping an entire frame.

| Mode | Description |
| --- | --- |
| Half interface | The EVR's video mixer skips the second field (relative to temporal order) of each interlaced frame. The video mixer still deinterlaces the first field, and this operation typically interpolates data from the second field. The overall frame rate is unaffected. |
| Bob deinterlacing | The video mixer uses bob deinterlacing, even if the driver supports a higher-quality deinterlacing algorithm. |

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)