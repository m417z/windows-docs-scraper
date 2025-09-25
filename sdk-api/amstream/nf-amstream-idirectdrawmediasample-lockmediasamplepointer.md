# IDirectDrawMediaSample::LockMediaSamplePointer

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `LockMediaSamplePointer` method locks the surface that the sample represents.

## Return value

Returns an **HRESULT** value.

## Remarks

Call this method only after calling [IDirectDrawMediaSample::GetSurfaceAndReleaseLock](https://learn.microsoft.com/windows/desktop/api/amstream/nf-amstream-idirectdrawmediasample-getsurfaceandreleaselock).

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDirectDrawMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-idirectdrawmediasample)