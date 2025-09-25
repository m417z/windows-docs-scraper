# IAMStreamConfig::GetNumberOfCapabilities

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetNumberOfCapabilities` method retrieves the number of format capabilities that this pin supports.

## Parameters

### `piCount` [out]

Pointer to a variable that receives the number of format capabilities.

### `piSize` [out]

Pointer to a variable that receives the size of the configuration structure in bytes. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | **NULL** pointer value. |
| **VFW_E_NOT_CONNECTED** | The input pin is not connected. |

## Remarks

An output pin can support more than one set of format capabilities. This method returns the total number of capabilities that the pin supports; the number is returned in the *piCount* parameter. To retrieve a particular set of capabilities, call the [IAMStreamConfig::GetStreamCaps](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getstreamcaps) method. Format capabilities are indexed from zero, so the value returned in *piCount* is one more than the upper bound.

Depending on the pin's format type, the [VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-video_stream_config_caps) structure (for video) or an [AUDIO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-audio_stream_config_caps) structure (for audio). The *piSize* parameter receives the size of the structure, in bytes.

On some compression filters, this method fails if the filter's input pin is not connected.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamconfig)