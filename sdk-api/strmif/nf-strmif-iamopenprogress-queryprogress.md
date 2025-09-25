# IAMOpenProgress::QueryProgress

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `QueryProgress` method retrieves the progress of the file-open operation.

## Parameters

### `pllTotal` [out]

Pointer to a variable that receives the length of the entire file, in bytes.

### `pllCurrent` [out]

Pointer to a variable that receives the length of the downloaded portion of the file, in bytes.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **VFW_S_ESTIMATED** | The returned values are estimates. |
| **E_UNEXPECTED** | Unexpected error. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMOpenProgress Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamopenprogress)