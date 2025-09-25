# IAMDecoderCaps::GetDecoderCaps

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDecoderCaps` method queries the decoder for its capabilities.

## Parameters

### `dwCapIndex` [in]

Specifies the capability being queried for.

| Constant | Value | Description |
| --- | --- | --- |
| AM_QUERY_DECODER_VMR_SUPPORT | 0x00000001 | Video Mixing Renderer Filter 7 (VMR-7) support |
| AM_QUERY_DECODER_DXVA_1_SUPPORT | 0x00000002 | DirectX Video Acceleration support |
| AM_QUERY_DECODER_DVD_SUPPORT | 0x00000003 | DVD Video support |
| AM_QUERY_DECODER_ATSC_SD_SUPPORT | 0x00000004 | Standard-definition (SD) ATSC video support |
| AM_QUERY_DECODER_ATSC_HD_SUPPORT | 0x00000005 | High-definition (HD) ATSC video support |
| AM_GETDECODERCAP_QUERY_VMR9_SUPPORT | 0x00000006 | Video Mixing Renderer Filter 9 (VMR-9) support |
| AM_GETDECODERCAP_QUERY_EVR_SUPPORT | 0x00000007 | Enhanced Video Renderer (EVR) support. |

### `lpdwCap` [out]

Receives one of the following values.

| Value | Description |
| --- | --- |
| DECODER_CAP_NOTSUPPORTED | The decoder does not support this capability. |
| DECODER_CAP_SUPPORTED | The decoder supports this capability. |

## Return value

If the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## Remarks

The DVD Graph Builder uses this method when it builds a DVD graph. If the decoder does not support the Video Mixing Renderer filter, then the DVD Graph Builder uses the [Overlay Mixer](https://learn.microsoft.com/windows/desktop/DirectShow/overlay-mixer-filter) filter instead.

## See also

[Building the DVD Filter Graph](https://learn.microsoft.com/windows/desktop/DirectShow/building-the-dvd-filter-graph)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMDecoderCaps Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamdecodercaps)