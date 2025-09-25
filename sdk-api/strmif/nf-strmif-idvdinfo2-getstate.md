# IDvdInfo2::GetState

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `GetState` method retrieves a bookmark containing the disc location and DVD Navigator state information.

## Parameters

### `pStateData` [out]

Receives a pointer to the [IDvdState](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdstate) interface of a **DvdState** object allocated by the DVD Navigator.

## Return value

Returns one of the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | DVD Navigator is not initialized. |

## Remarks

When this method is called, the DVD Navigator creates a new state object and saves the current location into it, as well as the current parental level and other state information. The **DVDState** object can be used to restore the DVD Navigator to the saved location at a later time through a call to [IDvdControl2::SetState](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-idvdcontrol2-setstate). This enables viewers to stop viewing in the middle of a disc, save the location, and come back at some later time to begin viewing where they left off, with all the internal settings restored as they were before.

The DVD Navigator calls **AddRef** on the **DvdState** object before returning it to the application. The application must call **Release** on the object when it is finished with it.

This method is demonstrated in the DVDSample application in **CDvdCore::RestoreBookmark**.

## See also

[DVD Applications](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-applications)

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2)