# IAMVideoCompression::OverrideFrameSize

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `OverrideFrameSize` method overrides the frame size of a specified frame.

## Parameters

### `FrameNumber` [in]

Specifies the frame number. The first frame that the filter delivers is numbered zero.

### `Size` [in]

Specifies the maximum size of the specified frame, in bytes.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

If the filter supports this method, the [IAMVideoCompression::GetInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-getinfo) method will return the **CompressionCaps_CanCrunch** flag in the *pCapabilities* parameter. However, this flag can also indicate that the filter supports setting the bit rate, so it does not guarantee that the `OverrideFrameSize` method is supported.

## See also

[CompressionCaps Enumeration](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-compressioncaps)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)