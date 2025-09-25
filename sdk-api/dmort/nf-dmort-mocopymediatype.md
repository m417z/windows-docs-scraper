# MoCopyMediaType function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MoCopyMediaType** function copies the members of one media type structure into another media type structure.

## Parameters

### `pmtDest`

Pointer to the target [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure. The caller must allocate, but not initialize, this structure.

### `pmtSrc`

Pointer to the source [DMO_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mediaobj/ns-mediaobj-dmo_media_type) structure.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory |
| **E_POINTER** | **NULL** pointer argument |
| **S_OK** | Success |

## Remarks

This function copies all the members of *pmtSrc* to *pmtDest* and copies the format block. The caller must free the target media type by calling the [MoFreeMediaType](https://learn.microsoft.com/windows/desktop/api/dmort/nf-dmort-mofreemediatype) function.