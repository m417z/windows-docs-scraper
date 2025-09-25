# IDirectDrawVideo::SetDefault

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDefault` method makes the current property settings the global default.

## Return value

Returns an **HRESULT** value.

## Remarks

All properties set through **IDirectDrawVideo** are specific to that particular instance. Call this method to make properties set on this instance of **IDirectDrawVideo** the global default of all DirectShow instances of this interface. After it is called, the current property settings will persist between the subsequent starting of other DirectShow filter graphs and between any computer restarts.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawVideo Interface](https://learn.microsoft.com/windows/desktop/api/amvideo/nn-amvideo-idirectdrawvideo)