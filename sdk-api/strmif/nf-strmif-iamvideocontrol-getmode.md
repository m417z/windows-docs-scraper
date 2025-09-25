# IAMVideoControl::GetMode

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMode` method retrieves the video control mode of operation.

## Parameters

### `pPin` [in]

Pointer to the pin to retrieve the video control mode from.

### `Mode` [out]

Pointer to a value representing a combination of the flags from the [VideoControlFlags](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-videocontrolflags) enumeration, which specify the video control mode.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

Possible modes of operation include one or more of the following: flipping the picture horizontally, flipping the picture vertically, enabling external triggers, and simulating external triggers.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol)