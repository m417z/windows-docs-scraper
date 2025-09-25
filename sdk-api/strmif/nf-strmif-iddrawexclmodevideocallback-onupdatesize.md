# IDDrawExclModeVideoCallback::OnUpdateSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OnUpdateSize` method informs the application that the size of the video rectangle is about to change.

## Parameters

### `dwWidth` [in]

The new width, in pixels, of the video stream.

### `dwHeight` [in]

The new height, in pixels, of the video stream.

### `dwARWidth` [in]

The new horizontal value of the aspect ratio.

### `dwARHeight` [in]

The new vertical value of the aspect ratio.

## Return value

Returns an HRESULT value.

## Remarks

This method is called when the size of the rectangle in the video stream changes, for example from 704x480 to 640x480.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDDrawExclModeVideoCallback Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iddrawexclmodevideocallback)