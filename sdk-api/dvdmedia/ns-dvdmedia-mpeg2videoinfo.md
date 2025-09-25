# MPEG2VIDEOINFO structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MPEG2VIDEOINFO** structure describes an MPEG-2 video stream.

## Members

### `hdr`

[VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure.

### `dwStartTimeCode`

25-bit group-of-pictures (GOP) time code at start of data. This field is not used for DVD.

### `cbSequenceHeader`

Length of the sequence header, in bytes. For DVD, set this field to zero. The sequence header is given in the **dwSequenceHeader** field.

### `dwProfile`

Specifies the MPEG-2 profile as an [AM_MPEG2Profile](https://learn.microsoft.com/windows/desktop/api/dvdmedia/ne-dvdmedia-am_mpeg2profile) enumeration type.

### `dwLevel`

Specifies the MPEG-2 level as an [AM_MPEG2Level](https://learn.microsoft.com/windows/desktop/api/dvdmedia/ne-dvdmedia-am_mpeg2level) enumeration type.

### `dwFlags`

Flag indicating preferences. Set one or a combination of the following values.

| Value | Meaning |
| --- | --- |
| **AMMPEG2_DoPanScan**<br><br>0x00000001 | If this flag is set, the MPEG-2 video decoder should crop the output image based on pan-scan vectors in picture_display_extension and change the picture aspect ratio to 4x3. The VMR should not receive a 16x9 sample with this flag. A simple implementation might alter the source rectangle to indicate a 540 wide source region with a left edge equal to the display offset in the picture_display_extension. |
| **AMMPEG2_DVDLine21Field1**<br><br>0x00000002 | If set, the MPEG-2 decoder must be able to produce an output pin for DVD style closed-captioned data found in the Group Of Pictures (GOP) layer of field 1. |
| **AMMPEG2_DVDLine21Field2**<br><br>0x00000004 | If set, the MPEG-2 decoder must be able to produce an output pin for DVD style closed-captioned data found in the GOP layer of field 2. |
| **AMMPEG2_SourceIsLetterboxed**<br><br>0x00000008 | If set, indicates that black bars have been encoded in the top and bottom of the video. |
| **AMMPEG2_FilmCameraMode**<br><br>0x00000010 | If set, indicates "film mode" used for the 625/50 (line/field) content. If cleared, indicates that "camera mode" was used. |
| **AMMPEG2_LetterboxAnalogOut**<br><br>0x00000020 | If set and this stream is sent to an analog output, it should be letterboxed. Streams sent to VGA should be letterboxed only by renderers. |
| **AMMPEG2_DSS_UserData**<br><br>0x00000040 | If set, the MPEG-2 decoder must process DSS style user data. |
| **AMMPEG2_DVB_UserData**<br><br>0x00000080 | If set, the MPEG-2 decoder must process DVB style user data. |
| **AMMPEG2_27MhzTimebase**<br><br>0x00000100 | If set, the PTS, DTS timestamps advance at 27MHz rather than 90KHz. |
| **AMMPEG2_WidescreenAnalogOut**<br><br>0x00000200 | If set and this stream is sent to an analog output, it should be in widescreen format (4x3 content should be centered on a 16x9 output). Streams sent to VGA should be widescreened only by renderers. |

Set undefined flags to zero or connection will be rejected. For more information on how to use these flags, see [MPEG Decoder Preprocessing Transformations](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-decoder-preprocessing-transformations).

### `dwSequenceHeader`

Start of an array that contains the sequence header, including quantization matrices and the sequence extension, if required. This field is typed as **DWORD** array to enforce 32-bit alignment. The size of the array, in bytes, is given in the **cbSequenceHeader** member.

## Remarks

The [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure contained in the [VIDEOINFOHEADER2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvdmedia/ns-dvdmedia-videoinfoheader2) structure (**hdr**) cannot be followed by any palette entries or color masks, because this structure is immediately followed by the **dwStartTimeCode** member.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)