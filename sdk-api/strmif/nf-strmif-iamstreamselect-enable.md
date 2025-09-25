# IAMStreamSelect::Enable

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Enable` method enables or disables a given stream.

## Parameters

### `lIndex` [in]

Zero-based index of the stream.

### `dwFlags` [in]

Flag indicating whether to enable or disable the stream. Use one of the following values.

| Value | Description |
| --- | --- |
| Zero | Disable all streams in the group containing this stream. |
| AMSTREAMSELECTENABLE_ENABLE | Enable only this stream within the given group and disable all others. |
| AMSTREAMSELECTENABLE_ENABLEALL | Enable all streams in the group containing this stream. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_INVALIDARG** | Invalid stream ID. |
| **E_NOTIMPL** | The filter does not support the specified flag. |
| **S_OK** | Success. |
| **VFW_E_NOT_CONNECTED** | The pins are not connected. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamSelect Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamselect)