# IMediaSample::SetDiscontinuity

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `SetDiscontinuity` method specifies whether this sample represents a break in the data stream.

## Parameters

### `bDiscontinuity` [in]

Boolean value that specifies whether this sample is a discontinuity. If **TRUE**, the media sample is discontinuous with the previous sample.

## Return value

Returns S_OK, or an **HRESULT** value indicating the cause of the error.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMediaSample Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample)

[IMediaSample::IsDiscontinuity](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-imediasample-isdiscontinuity)