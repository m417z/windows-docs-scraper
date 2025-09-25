# IDvdInfo::GetAllGPRMs

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** The **IDvdInfo** interface is deprecated. Use [IDvdInfo2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo2) instead.

Retrieves the current contents of all general parameter registers (GPRMs).

## Parameters

### `pRegisterArray` [out]

Pointer to the retrieved array of general parameter registers.

## Return value

Returns an **HRESULT** value.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | DVD is not initialized or domain is not DVD_DOMAIN_Title. |
| **S_OK** | Success. |
| **VFW_E_DVD_INVALIDDOMAIN** | Requested action is not supported on this domain ([DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain)). |
| **VFW_E_DVD_OPERATION_INHIBITED** | Requested action cannot occur at this point in the movie due to the authoring of the current DVD-Video disc. |

## Remarks

This method is valid in any domain. For more information, see [DVD_DOMAIN](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-dvd_domain).

Use of GPRMs is title specific. GPRMs are general parameter registers. For an explanation of GPRMs, see the DVD specifications.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IDvdInfo Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-idvdinfo)