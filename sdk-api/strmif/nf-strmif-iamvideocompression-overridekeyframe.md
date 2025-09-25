# IAMVideoCompression::OverrideKeyFrame

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OverrideKeyFrame` method instructs the filter to compress a particular frame as a key frame.

## Parameters

### `FrameNumber` [in]

Specifies the frame number. The first frame that the filter delivers is numbered zero.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

If the filter supports this method, you can use it to override the normal key-frame distribution for a particular frame. After the filter creates a key frame, it might reset its count to determine when the next key frame should occur. For example, if the key-frame rate is 10, and an application uses this method to force frame 5 as a key frame, the filter might wait another 10 frames (until frame 15) before it creates the next key frame.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)