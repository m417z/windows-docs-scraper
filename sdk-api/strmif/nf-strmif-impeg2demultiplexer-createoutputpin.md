# IMpeg2Demultiplexer::CreateOutputPin

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `CreateOutputPin` method creates a new output pin on the Demux.

## Parameters

### `pMediaType` [in]

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type information for the new pin.

### `pszPinName` [in]

Pointer to a wide character string that specifies a name for the new pin. The maximum length is 128 characters, including the **NULL** terminator.

### `ppIPin` [out]

Address of a variable that receives a pointer to the pin's [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface.

## Return value

Returns an **HRESULT** value. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | Success. |
| **VFW_E_DUPLICATE_NAME** | Duplicate pin name. |

## Remarks

Duplicate pin names are not allowed. To configure the pin, query the returned [IPin](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-ipin) interface for the [IMPEG2StreamIdMap](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-impeg2streamidmap) interface (for program streams) or for the [IMPEG2PIDMap](https://learn.microsoft.com/previous-versions/windows/desktop/api/bdaiface/nn-bdaiface-impeg2pidmap) interface (for transport streams). Depending on which interface is queried for on the first output pin, the Demux configures itself for either transport or program stream mode. Once the Demux is configured, any calls to **QueryInterface** to retrieve the other interface will fail.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IMpeg2Demultiplexer Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-impeg2demultiplexer)