# IAMVideoCompression::get_PFramesPerKeyFrame

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_PFramesPerKeyFrame` method retrieves the rate of predicted (P) frames per key frame.

## Parameters

### `pPFramesPerKeyFrame` [out]

Pointer to a variable that receives the number of P frames per key frame. If the value is negative, the filter will use the default rate.

## Return value

Returns an **HRESULT** value.

## Remarks

To determine if the filter supports this method, call the [IAMVideoCompression::GetInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-getinfo) method and check for the **CompressionCaps_CanBFrame** flag in the *pCapabilities* parameter. The **GetInfo** method also returns the default P-frame rate.

P frames are used in MPEG compression; in general, this property does not apply to other compression formats. For example, suppose a key frame occurs once every 10 frames, and there are three P frames per key frame. The P frames will be spaced evenly between the key frames. The remaining six frames are bidirectional (B) frames.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)

[IAMVideoCompression::put_KeyFrameRate](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-put_keyframerate)