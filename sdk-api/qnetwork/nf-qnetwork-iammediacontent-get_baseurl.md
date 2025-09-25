# IAMMediaContent::get_BaseURL

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_BaseURL** method gets a base URL for the related web content.

## Parameters

### `pbstrBaseURL`

Receives a **BSTR** with the information.

## Return value

Returns an **HRESULT** value. Possible values include those shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Not implemented. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **VFW_E_NOT_FOUND** | Item not found. |

## Remarks

If the method succeeds, the caller must free the returned **BSTR** by calling the **SysFreeString** function.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMMediaContent Interface](https://learn.microsoft.com/windows/desktop/api/qnetwork/nn-qnetwork-iammediacontent)