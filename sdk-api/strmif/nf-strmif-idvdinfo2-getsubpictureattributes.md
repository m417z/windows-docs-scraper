# IDvdInfo2::GetSubpictureAttributes

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetSubpictureAttributes` method retrieves the attributes of the specified subpicture stream in the specified title or menu.

## Parameters

### `ulStream` [in]

Index number, from 0 through 31, of the subpicture stream to query. See Remarks.

### `pATR` [out]

Pointer to a [DVD_SubpictureAttributes](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvd_subpictureattributes) structure that receives the subpicture attributes.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | No subpicture streams were found. |
| **E_POINTER** | Invalid argument. |
| **VFW_E_DVD_NO_ATTRIBUTES** | The subpicture has no defined attributes. |

## Remarks

The index numbers 0-31 are valid only for titles. Menus have only one subpicture stream, which must be specified using one of the constants in the table below:

| Value | Description |
| --- | --- |
| DVD_STREAM_DATA_CURRENT (0x800) | To query the currently selected subpicture stream. |
| DVD_STREAM_DATA_VMGM (0x400) | To query the subpicture attributes for the Video Manager or "Top" Menu. |
| DVD_STREAM_DATA_VTSM (0x401) | To query the subpicture attributes for the currently selected Video Title Set Menu. |

This method is demonstrated in the DVDSample application in **CDvdCore::GetSPAttributes()** and **CSPLangDlg::GetSPLang**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)

[Working With DVD Menus](https://learn.microsoft.com/windows/desktop/DirectShow/working-with-dvd-menus)