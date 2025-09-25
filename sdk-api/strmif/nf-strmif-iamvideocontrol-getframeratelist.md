# IAMVideoControl::GetFrameRateList

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetFrameRateList` method retrieves a list of available frame rates.

## Parameters

### `pPin` [in]

Pointer to the pin to query for the list of frame rates.

### `iIndex` [in]

Index of the format to query for frame rates. This index corresponds to the order in which formats are enumerated by [VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-video_stream_config_caps) structures returned by [IAMStreamConfig::GetNumberOfCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getnumberofcapabilities)) minus one.

### `Dimensions` [in]

Frame image size (width and height) in pixels.

### `ListSize` [out]

Pointer to the number of elements in the list of frame rates.

### `FrameRates` [out]

Address of a pointer to an array of frame rates in 100-nanosecond units. Can be **NULL** if you only need *ListSize*.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## Remarks

The caller is responsible for freeing the memory through a call to **CoTaskMemFree**.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol)

[VIDEO_STREAM_CONFIG_CAPS Structure](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-video_stream_config_caps)