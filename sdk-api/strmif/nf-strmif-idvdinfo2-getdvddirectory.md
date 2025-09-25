# IDvdInfo2::GetDVDDirectory

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDDirectory` method retrieves the root directory that is set in the DVD Navigator.

## Parameters

### `pszwPath` [out]

Pointer to a buffer that receives the path string.

### `ulMaxSize` [in]

Size of the buffer, in WCHARs.

### `pulActualSize` [out]

Pointer to a variable that receives the size of actual data returned, in WCHARs.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The buffer is not large enough to hold the string. |
| **VFW_E_DVD_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not in a valid domain. |

## Remarks

This method is demonstrated in the DVDSample application in **CDvdCore::GetDriveLetter**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)