# DMO_MEDIA_TYPE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DMO_MEDIA_TYPE** structure describes the format of the data used by a stream in a Microsoft DirectX Media Object (DMO).

## Members

### `majortype`

Major type GUID of the stream.

### `subtype`

Subtype GUID of the stream.

### `bFixedSizeSamples`

If **TRUE**, samples are of a fixed size. This field is informational only. For audio, it is generally set to **TRUE**. For video, it is usually **TRUE** for uncompressed video and **FALSE** for compressed video.

### `bTemporalCompression`

If **TRUE**, samples are compressed using temporal (interframe) compression. (A value of **TRUE** indicates that not all frames are key frames.) This field is informational only.

### `lSampleSize`

Size of the sample in bytes. For compressed data, the value can be zero.

### `formattype`

GUID specifying the format type. The **pbFormat** member points to the corresponding format structure. Format types include the following.

| Format type | Format structure |
| --- | --- |
| **FORMAT_DvInfo** | [DVINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvinfo) |
| **FORMAT_MPEG2Video** | [MPEG2VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-mpeg2videoinfo) |
| **FORMAT_MPEGVideo** | [MPEG1VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-mpeg1videoinfo) |
| **FORMAT_None** | None. |
| **FORMAT_VideoInfo** | [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) |
| **FORMAT_VideoInfo2** | [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) |
| **FORMAT_WaveFormatEx** | [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) |

### `pUnk`

Not used. Set to **NULL**.

### `cbFormat`

Size of the format block of the media type.

### `pbFormat`

Pointer to the format structure. The structure type is specified by the **formattype** member. The format structure must be present, unless **formattype** is GUID_NULL or FORMAT_None.

## Remarks

This structure is identical to the DirectShow [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure. The **bFixedSizeSamples**, **bTemporalCompression**, and **lSampleSize** members are for compatibility with DirectShow. Other DMO clients are not required to use them.

## See also

[DMO Structures](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-structures)