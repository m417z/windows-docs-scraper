# AM_MEDIA_TYPE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_MEDIA_TYPE** structure describes the format of a media sample.

## Members

### `majortype`

Globally unique identifier (GUID) that specifies the major type of the media sample. For a list of possible major types, see [Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types).

### `subtype`

GUID that specifies the subtype of the media sample. For a list of possible subtypes, see [Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types). For some formats, the value might be MEDIASUBTYPE_None, which means the format does not require a subtype.

### `bFixedSizeSamples`

If **TRUE**, samples are of a fixed size. This field is informational only. For audio, it is generally set to **TRUE**. For video, it is usually **TRUE** for uncompressed video and **FALSE** for compressed video.

### `bTemporalCompression`

If **TRUE**, samples are compressed using temporal (interframe) compression. A value of **TRUE** indicates that not all frames are key frames. This field is informational only.

### `lSampleSize`

Size of the sample in bytes. For compressed data, the value can be zero.

### `formattype`

GUID that specifies the structure used for the format block. The **pbFormat** member points to the corresponding format structure. Format types include the following:

| Format type | Format structure |
| --- | --- |
| **FORMAT_DvInfo** | [DVINFO](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-dvinfo) |
| **FORMAT_MPEG2Video** | [MPEG2VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-mpeg2videoinfo) |
| **FORMAT_MPEGStreams** | [AM_MPEGSYSTEMTYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpegtype/ns-mpegtype-am_mpegsystemtype) |
| **FORMAT_MPEGVideo** | [MPEG1VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-mpeg1videoinfo) |
| **FORMAT_None** | None. |
| **FORMAT_VideoInfo** | [VIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/amvideo/ns-amvideo-videoinfoheader) |
| **FORMAT_VideoInfo2** | [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) |
| **FORMAT_WaveFormatEx** | [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) |
| **GUID_NULL** | None |

### `pUnk`

Not used. Set to **NULL**.

### `cbFormat`

Size of the format block, in bytes.

### `pbFormat`

Pointer to the format block. The structure type is specified by the **formattype** member. The format structure must be present, unless **formattype** is GUID_NULL or FORMAT_None.

The **pbFormat** buffer must be allocated by calling [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc). To release the format block, call [FreeMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/freemediatype).

## Remarks

When two pins connect, they negotiate a media type, which is defined by an **AM_MEDIA_TYPE** structure. The media type describes the format of the data that the filters will exchange. If the filters do not agree on a media type, they cannot connect.

The stream type is specified by two **GUID**s, called the *major type* and the *subtype*. The major type defines the general category, such as video, audio, or byte stream. The subtype defines a narrower category within the major type. For example, video subtypes include 8-bit, 16-bit, 24-bit, and 32-bit RGB.

The **AM_MEDIA_TYPE** structure is followed by a variable-length block of data that contains format-specific information. The **pbFormat** member points to this block, called the *format block*. The layout of the format block depends on the type of data in the stream, and is specified by the **formattype** member. The format block might be **NULL**. Check the **cbFormat** member to determine the size. Cast the **pbFormat** member to access the format block. For example:

| C++ |
| --- |
| ``` if (pmt->formattype == FORMAT_VideoInfo) {     // Check the buffer size.     if (pmt->cbFormat >= sizeof(VIDEOINFOHEADER))     {         VIDEOINFOHEADER *pVih =              reinterpret_cast<VIDEOINFOHEADER*>(pmt->pbFormat);         /* Access VIDEOINFOHEADER members through pVih. */     } } ``` |

In some situations, you can set the format block to **NULL** and the format type to GUID_NULL, resulting in a *partial media type*. This enables you to specify a range of possible formats. For example, you can specify 24-bit RGB (MEDIASUBTYPE_RGB24) without giving an exact width or height.

To obtain detailed information about a specified media type for debugging purposes, use the [DisplayType](https://learn.microsoft.com/windows/desktop/DirectShow/displaytype) method.

## See also

[About Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/about-media-types)

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[Media Type Functions](https://learn.microsoft.com/windows/desktop/DirectShow/media-type-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/DirectShow/media-types)