# MoDuplicateMediaType function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MoDuplicateMediaType** function duplicates a media type structure.

## Parameters

### `ppmtDest`

Address of a pointer to a [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure that receives the duplicated structure.

### `pmtSrc`

Pointer to the media type structure to duplicate.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

This method is equivalent to calling [MoCreateMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-mocreatemediatype) and [MoCopyMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-mocopymediatype). The caller must delete the returned media type structure by calling the [MoDeleteMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-modeletemediatype) function.