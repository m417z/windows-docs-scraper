# IAMVideoCompression::put_Quality

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `put_Quality` method sets the compression quality.

## Parameters

### `Quality` [in]

Specifies the quality as a value between 0.0 and 1.0, where 1.0 indicates the best quality and 0.0 indicates the worst quality. If the value is negative, the filter will use the default quality.

## Return value

Returns an **HRESULT** value.

## Remarks

To determine if the filter supports this method, call the [IAMVideoCompression::GetInfo](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-getinfo) method and check for the **CompressionCaps_CanQuality** flag in the *pCapabilities* parameter. The **GetInfo** method also returns the default quality.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoCompression Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocompression)

[IAMVideoCompression::get_Quality](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamvideocompression-get_quality)