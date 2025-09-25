# MFVideoAspectRatioMode enumeration

## Description

[The component described on this page, [Enhanced Video Renderer](https://learn.microsoft.com/windows/win32/medfound/enhanced-video-renderer), is a legacy feature. It has been superseded by the Simple Video Renderer (SVR) exposed through the [MediaPlayer](https://learn.microsoft.com/uwp/api/windows.media.playback.mediaplayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine) components. To play video content you should send data into one of these components and allow them to instantiate the new video renderer. These components have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** or the lower level **IMFMediaEngine** APIs to play video media in Windows instead of the EVR, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.]

Specifies the aspect-ratio mode.

## Constants

### `MFVideoARMode_None:0`

Do not maintain the aspect ratio of the video. Stretch the video to fit the output rectangle.

### `MFVideoARMode_PreservePicture:0x1`

Preserve the aspect ratio of the video by letterboxing or within the output rectangle.

### `MFVideoARMode_PreservePixel:0x2`

**Note** Currently the EVR ignores this flag.

Correct the aspect ratio if the physical size of the display device does not match the display resolution. For example, if the native resolution of the monitor is 1600 by 1200 (4:3) but the display resolution is 1280 by 1024 (5:4), the monitor will display non-square pixels.

If this flag is set, you must also set the **MFVideoARMode_PreservePicture** flag.

### `MFVideoARMode_NonLinearStretch:0x4`

Apply a non-linear horizontal stretch if the aspect ratio of the destination rectangle does not match the aspect ratio of the source rectangle.

The non-linear stretch algorithm preserves the aspect ratio in the middle of the picture and stretches (or shrinks) the image progressively more toward the left and right. This mode is useful when viewing 4:3 content full-screen on a 16:9 display, instead of pillar-boxing. Non-linear vertical stretch is not supported, because the visual results are generally poor.

This mode may cause performance degradation.

If this flag is set, you must also set the **MFVideoARMode_PreservePixel** and **MFVideoARMode_PreservePicture** flags.

### `MFVideoARMode_Mask:0x7`

Bitmask to validate flag values. This value is not a valid flag.

## See also

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[IMFVideoDisplayControl::GetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-getaspectratiomode)

[IMFVideoDisplayControl::SetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setaspectratiomode)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)