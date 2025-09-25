# IAMVideoControl::GetMaxAvailableFrameRate

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetMaxAvailableFrameRate` method retrieves the maximum frame rate currently available, based on bus bandwidth usage for connections, such as USB and IEEE 1394, where the maximum frame rate may be limited by bandwidth availability.

## Parameters

### `pPin` [in]

Pointer to the pin to retrieve the maximum frame rate from.

### `iIndex` [in]

Index of the format to query for maximum frame rate. This index corresponds to the order in which formats are enumerated by [IAMStreamConfig::GetStreamCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getstreamcaps). The value must range between zero and the number of supported **VIDEO_STREAM_CONFIG_CAPS** structures returned by [IAMStreamConfig::GetNumberOfCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getnumberofcapabilities)) minus one.

### `Dimensions` [in]

Frame image size (width and height) in pixels.

### `MaxAvailableFrameRate` [out]

Pointer to the maximum available frame rate. The frame rate is expressed as frame duration in 100-nanosecond units.

## Return value

Returns an **HRESULT** value that depends on the implementation of the interface.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMVideoControl Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamvideocontrol)

[VIDEO_STREAM_CONFIG_CAPS Structure](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-video_stream_config_caps)