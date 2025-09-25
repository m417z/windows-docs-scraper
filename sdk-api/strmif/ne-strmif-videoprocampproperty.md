# VideoProcAmpProperty enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **VideoProcAmpProperty** enumeration specifies video properties on a video capture device.

## Constants

### `VideoProcAmp_Brightness:0`

Specifies the brightness, also called the *black level*. For NTSC, the value is expressed in IRE units * 100. For non-NTSC sources, the units are arbitrary, with zero representing blanking and 10,000 representing pure white. Values range from –10,000 to 10,000.

### `VideoProcAmp_Contrast`

Specifies the contrast, expressed as gain factor * 100. Values range from zero to 10,000.

### `VideoProcAmp_Hue`

Specifies the hue, in degrees * 100. Values range from -180,000 to 180,000 (-180 to +180 degrees).

### `VideoProcAmp_Saturation`

Specifies the saturation. Values range from 0 to 10,000.

### `VideoProcAmp_Sharpness`

Specifies the sharpness. Values range from 0 to 100.

### `VideoProcAmp_Gamma`

Specifies the gamma, as gamma * 100. Values range from 1 to 500.

### `VideoProcAmp_ColorEnable`

Specifies the color enable setting. The possible values are 0 (off) and 1 (on).

### `VideoProcAmp_WhiteBalance`

Specifies the white balance, as a color temperature in degrees Kelvin. The range of values depends on the device.

### `VideoProcAmp_BacklightCompensation`

Specifies the backlight compensation setting. Possible values are 0 (off) and 1 (on).

### `VideoProcAmp_Gain`

Specifies the gain adjustment. Zero is normal. Positive values are brighter and negative values are darker. The range of values depends on the device.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[IAMVideoProcAmp](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideoprocamp)