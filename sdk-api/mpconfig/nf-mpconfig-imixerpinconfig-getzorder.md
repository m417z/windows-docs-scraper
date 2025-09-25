# IMixerPinConfig::GetZOrder

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetZOrder` method retrieves the z-order of a particular video stream.

This method is not currently implemented and returns E_NOTIMPL.

## Parameters

### `pdwZOrder` [out]

Pointer to a value indicating the order in which streams will clip each other.

## Return value

Returns E_NOTIMPL.

## Remarks

Images with larger z-values are always in front of images with smaller z-values.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::SetZOrder](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-setzorder)