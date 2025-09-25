# AM_ASPECT_RATIO_MODE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the aspect ratio of a video image in a display window.

## Constants

### `AM_ARMODE_STRETCHED`

No aspect ratio correction.

### `AM_ARMODE_LETTER_BOX`

Put the video in letterbox format. Paint background color in the excess region so the video is not distorted.

### `AM_ARMODE_CROP`

Crop the video to the correct aspect ratio.

### `AM_ARMODE_STRETCHED_AS_PRIMARY`

Use whatever mode is currently set for the primary stream. This value is valid only for secondary streams.

## Remarks

The AM_ARMODE_STRETCHED member causes a video stream to occupy the entire region of the display window when the window is resized, possibly stretching the video. The AM_ARMODE_LETTER_BOX member eliminates video stretching and distortions by keeping the aspect ratio consistent and painting the excess areas of the window a background color. The AM_ARMODE_CROP member also prevents stretching, by cropping the image if necessary.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IMixerPinConfig::GetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getaspectratiomode)

[IMixerPinConfig::SetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-setaspectratiomode)