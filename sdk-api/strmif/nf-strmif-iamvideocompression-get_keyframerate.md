# IAMVideoCompression::get_KeyFrameRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_KeyFrameRate` method retrieves the current key-frame rate.

## Parameters

### `pKeyFrameRate` [out]

Pointer to a variable that receives the current key-frame rate. If the value is negative, the filter will use the default key-frame rate. If the value is zero, only the first frame is a key frame.

## Return value

Returns an **HRESULT** value.

## Remarks

The key-frame rate is the number of frames per key frame. For example, if the rate is 15, then a key frame occurs every 15 frames.

To determine if the filter supports this method, call the [IAMVideoCompression::GetInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-getinfo) method and check for the **CompressionCaps_CanKeyFrame** flag in the *pCapabilities* parameter. The **GetInfo** method also returns the default key-frame rate.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)

[IAMVideoCompression::put_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_keyframerate)