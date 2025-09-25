# IAMAnalogVideoDecoder::get_VCRHorizontalLocking

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `get_VCRHorizontalLocking` method indicates whether the decoder is expecting video from a tape source or a broadcast source.

## Parameters

### `plVCRHorizontalLocking` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| 0 | The decoder is expecting video from a broadcast source. |
| 1 | The decoder is expecting video from a tape source. |

## Return value

Returns an HRESULT value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_PROP_ID_UNSUPPORTED** | The device does not support this method. |
| **S_OK** | Success. |

## Remarks

The timing accuracy of synchronization pulses is typically poorer from a tape source than from a broadcast source. If the returned value is 1, the decoder might relax its sync timing standards.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMAnalogVideoDecoder Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamanalogvideodecoder)