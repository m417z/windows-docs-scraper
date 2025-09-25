# IDvdInfo2::GetDiscID

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDiscID` method retrieves a system-generated 64-bit identification number for the specified DVD.

## Parameters

### `pszwPath` [in]

Path of the volume to use for the disc ID. Specify **NULL** to use the current or default DVD volume.

### `pullDiscID` [out]

Receives the 64-bit disc ID.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not initialized. |
| **VFW_E_DVD_INVALID_DISC** | The specified path is not a valid DVD disc. |

## Remarks

The DVD Navigator calculates an identifier ID based on file sizes, dates, and other information, and not the BCA (burst cutting area) value. This number is guaranteed to be the same each time the disc is played. The ID applies to all replicated copies of a disc. In other words, all copies of a specific movie will have the same ID. The odds that two separate titles will have the same ID is sufficiently remote that this ID can be considered "unique" for all practical purposes.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)