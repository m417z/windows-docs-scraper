# IDvdInfo2::GetTitleAttributes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetTitleAttributes` method retrieves attributes of all video, audio, and subpicture streams for the specified title and its menus.

## Parameters

### `ulTitle` [in]

Variable of type ULONG, from 1 through 99, specifying the requested title number. Specify 0xFFFFFFFF for the current title.

### `pMenu` [out]

Pointer to a [DVD_MenuAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_menuattributes) structure that receives the attributes of the menu associated with the specified title.

### `pTitle` [out]

Pointer to a [DVD_TitleAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_titleattributes) structure that receives the attributes of the specified title.

## Return value

Returns one of the following `HRESULT` values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *nTitle* parameter is invalid. |
| **E_INVALIDDOMAIN** | The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) is not in the title domain. |
| **E_POINTER** | The *pMenu* or *pTitle* parameter is invalid. |
| **E_UNEXPECTED** | DVD Navigator is not initialized or some other internal error occurred. |

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)