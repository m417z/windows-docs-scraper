# IDvdInfo2::GetDVDVolumeInfo

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetDVDVolumeInfo` method retrieves the current DVD volume information.

## Parameters

### `pulNumOfVolumes` [out]

Receives the number of volumes in the volume set.

### `pulVolume` [out]

Receives the volume number for this root directory.

### `pSide` [out]

Pointer to a variable of type [DVD_DISC_SIDE](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_disc_side) that receives the current disc side.

### `pulNumOfTitles` [out]

Pointer to a variable of type ULONG that receives the number of titles available in this volume.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Invalid argument. |

## Remarks

Some discs can be distributed as part of multidisc set. "Volume" in this context can mean either "disc" or "disc side", depending on how the disc was authored.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)