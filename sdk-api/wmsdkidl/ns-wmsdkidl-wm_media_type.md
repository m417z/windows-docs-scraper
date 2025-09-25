# WM_MEDIA_TYPE structure

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WM_MEDIA_TYPE** structure is the primary structure used to describe media formats for the objects of the Windows Media Format SDK. For more information about media formats and what they are used for, see [Formats](https://learn.microsoft.com/windows/desktop/wmformat/formats).

## Members

### `majortype`

Major type of the media sample. For example, WMMEDIATYPE_Video specifies a video stream. For a list of possible major media types, see [Media Types](https://learn.microsoft.com/windows/desktop/wmformat/media-types).

### `subtype`

Subtype of the media sample. The subtype defines a specific format (usually an encoding scheme) within a major media type. For example, WMMEDIASUBTYPE_WMV3 specifies a video stream encoded with the Windows Media Video 9 codec. Subtypes can be uncompressed or compressed. For lists of possible media subtypes, see [Uncompressed Media Subtypes](https://learn.microsoft.com/windows/desktop/wmformat/uncompressed-media-subtypes) and [Compressed Media Subtypes](https://learn.microsoft.com/windows/desktop/wmformat/compressed-media-subtypes).

### `bFixedSizeSamples`

Set to true if the samples are of a fixed size. Compressed audio samples are of a fixed size while video samples are not.

### `bTemporalCompression`

Set to true if the samples are temporally compressed. Temporal compression is compression where some samples describe the changes in content from the previous sample, instead of describing the sample in its entirety. Only compressed video can be temporally compressed. By definition, no media type can use both fixed sized samples and temporal compression.

### `lSampleSize`

Long integer containing the size of the sample, in bytes. This member is used only if **bFixedSizeSamples** is true.

### `formattype`

GUID of the format type. The format type specifies the additional structure used to identify the media format. This structure is pointed to by **pbFormat**.

### `pUnk`

Not used. Should be **NULL**.

### `cbFormat`

Size, in bytes, of the structure pointed to by pbFormat.

### `pbFormat`

Pointer to the format structure of the media type. The structure referenced is determined by the format type **GUID**. Format types include:

| Media Type | Structure |
| --- | --- |
| WMFORMAT_VideoInfo | [WMVIDEOINFOHEADER](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmvideoinfoheader) |
| WMFORMAT_WaveFormatEx | [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd757720(v=vs.85)) |
| WMFORMAT_MPEG2Video | [WMMPEG2VIDEOINFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmmpeg2videoinfo) |
| WMFORMAT_WebStream | [WMT_WEBSTREAM_FORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmt_webstream_format) |
| WMFORMAT_Script | [WMSCRIPTFORMAT](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmscriptformat) |

## Remarks

This is the same as the DirectShow structure **AM_MEDIA_TYPE** but is redefined in this SDK to avoid conflict with DirectShow names.

## See also

[IWMMediaProps::GetMediaType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmediaprops-getmediatype)

[IWMMediaProps::SetMediaType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmediaprops-setmediatype)

[Media Type Identifiers](https://learn.microsoft.com/windows/desktop/wmformat/media-type-identifiers)

[Media Types](https://learn.microsoft.com/windows/desktop/wmformat/media-types)

[Structures](https://learn.microsoft.com/windows/desktop/wmformat/structures)