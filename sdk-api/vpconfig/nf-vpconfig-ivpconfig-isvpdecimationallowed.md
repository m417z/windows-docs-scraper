# IVPConfig::IsVPDecimationAllowed

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `IsVPDecimationAllowed` method, given the context, retrieves whether scaling at the video port is possible.

## Parameters

### `pbIsDecimationAllowed` [out]

Receives a Boolean value indicating whether decimation is possible.

## Return value

Returns an **HRESULT** value.

## Remarks

The [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter uses this function to determine whether the driver needs the mixer to decimate video data at its own discretion. This function can be especially useful in a capture with preview situation in which you would not want the VP mixer filter to perform any scaling at the video port.

Include Dvp.h and Vptype.h before Vpconfig.h.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IVPConfig Interface](https://learn.microsoft.com/windows/desktop/api/vpconfig/nn-vpconfig-ivpconfig)