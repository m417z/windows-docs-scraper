# IMixerPinConfig::SetAspectRatioMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetAspectRatioMode` method sets the aspect ratio correction mode for window resizing.

## Parameters

### `amAspectRatioMode` [in]

Value specifying one of the [AM_ASPECT_RATIO_MODE](https://learn.microsoft.com/windows/desktop/api/mpconfig/ne-mpconfig-am_aspect_ratio_mode) enumerated type members.

## Return value

Returns an **HRESULT** value. Possible values include the following:

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Method called on secondary stream. |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |

## Remarks

Currently this function is implemented only on the primary pin of the [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter. Calling it on a secondary pin will result in an error.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMixerPinConfig Interface](https://learn.microsoft.com/windows/desktop/api/mpconfig/nn-mpconfig-imixerpinconfig)

[IMixerPinConfig::GetAspectRatioMode](https://learn.microsoft.com/windows/desktop/api/mpconfig/nf-mpconfig-imixerpinconfig-getaspectratiomode)