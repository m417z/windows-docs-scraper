# IAsyncReader::Length

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Length` method retrieves the total length of the stream.

## Parameters

### `pTotal`

Pointer to a variable that receives the length of the stream, in bytes.

### `pAvailable`

Pointer to a variable that receives the portion of the stream that is currently available, in bytes.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_ESTIMATED** | The returned values are estimates; for example, if the file is being read over a network. |
| **E_UNEXPECTED** | The file is not open or no longer exists. |

## Remarks

For streams retrieved over a network, the entire stream may not be available at first. Read operations beyond the available length might block for a long period of time, until that portion of the stream becomes available.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAsyncReader Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iasyncreader)