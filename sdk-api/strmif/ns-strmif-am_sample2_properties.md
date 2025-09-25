# AM_SAMPLE2_PROPERTIES structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AM_SAMPLE2_PROPERTIES** structure describes the properties of a media sample. The [IMediaSample2](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-imediasample2) interface uses this structure.

## Members

### `cbData`

Length of property data, in bytes. This structure member is for extensibility.

### `dwTypeSpecificFlags`

Type-specific flags. Flags are defined separately for each media type. The default value is AM_VIDEO_FLAG_INTERLEAVED_FRAME (zero). The following flags are used for video streams. They are defined in the header file dvdmedia.h.

| Flag | Meaning |
| --- | --- |
| **AM_VIDEO_FLAG_FIELD_MASK**<br><br>0x0003 | Use this mask to check whether the sample is a field or a frame. |
| **AM_VIDEO_FLAG_INTERLEAVED_FRAME**<br><br>0x0000 | The sample is a frame. (Use the AM_VIDEO_FLAG_FIELD_MASK bitmask to test for this value.) |
| **AM_VIDEO_FLAG_FIELD1**<br><br>0x0001 | The sample is field 1. (Use the AM_VIDEO_FLAG_FIELD_MASK bitmask to test for this value.) |
| **AM_VIDEO_FLAG_FIELD2**<br><br>0x0002 | The sample is the field 2. (Use the AM_VIDEO_FLAG_FIELD_MASK bitmask to test for this value.) |
| **AM_VIDEO_FLAG_FIELD1FIRST**<br><br>0x0004 | If this flag is set, display field 1 first. Otherwise, display field 2 first. (Applies only when there are two fields per sample.) |
| **AM_VIDEO_FLAG_WEAVE**<br><br>0x0008 | If this flag is set, use weave mode (that is, do not deinterlace the sample). Otherwise, use bob mode. This flag applies only when there are two fields per sample. |
| **AM_VIDEO_FLAG_REPEAT_FIELD**<br><br>0x0040 | If this flag is set, display the first field again after displaying the second field. (Applies only when there are two fields per sample.) |
| **AM_ReverseBlockStart**<br><br>0x2 | Signals the start of a VOBU during reverse playback of DVD video. For more information, see [DVD Playback Enhancements in Windows Vista](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-playback-enhancements-in-windows-vista). |
| **AM_ReverseBlockEnd**<br><br>0x4 | Signals the end of a VOBU during reverse playback of DVD video. The DVD Navigator sets this flag on an empty sample to signal the end of a VOBU. For more information, see [DVD Playback Enhancements in Windows Vista](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-playback-enhancements-in-windows-vista). |
| **AM_UseNewCSSKey**<br><br>0x1 | For DVD playback, indicates the point in the stream when the decoder should apply a new Content Scramble System (CSS) key.<br><br>The [DVD Navigator](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-navigator-filter) sets this flag on an empty media sample just before it renegotiate a CSS title key.<br><br>Previously, the DVD Navigator incorrectly sent this key before negotiating the disc key. Starting in Windows 7, if the decoder's **AM_PROPERTY_DVDCOPY_SUPPORTS_NEW_KEYCOUNT** property returns **TRUE**, the DVD Navigator does not send this flag before negotiating the disc key. See [DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set). |

Other flags are defined but not currently used. See dvdmedia.h.

### `dwSampleFlags`

Bitwise combination of flags the [AM_SAMPLE_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-tagam_sample_property_flags) enumerated data type. Undefined bits are reserved and must be zero.

### `lActual`

Length of the valid data in the buffer.

### `tStart`

Start time, if valid. The **dwSampleFlags** member specifies whether this member is valid.

### `tStop`

Stop time, if valid. The **dwSampleFlags** member specifies whether this member is valid.

### `dwStreamId`

Stream identifier. If the value is AM_STREAM_MEDIA, the stream contains media data. If the value is AM_STREAM_CONTROL, the stream contains control information. Applications can define values of 0x80000000 or greater for their own use. (See [AM_SAMPLE_PROPERTY_FLAGS](https://learn.microsoft.com/windows/desktop/api/strmif/ne-strmif-tagam_sample_property_flags).)

### `pMediaType`

Pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that specifies the media type if the format has changed. If this format has not changed, this member is **NULL**.

### `pbBuffer`

Pointer to the sample buffer.

### `cbBuffer`

Size of the sample buffer, in bytes.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)