## Description

The **KS_MPEGVIDEOINFO2** structure describes an MPEG-2 video stream, including bob or weave settings.

## Members

### `hdr`

Specifies a [**KS_VIDEOINFOHEADER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader2) structure that describes the details of the video stream.

### `dwStartTimeCode`

A 25-bit "group-of-pictures" time code at the start of data (not used for DVD).

### `cbSequenceHeader`

The length of the **bSequenceHeader** member, in bytes (zero for DVD).

### `dwProfile`

Specifies the MPEG-2 profile. This member must be one of the values from the [KS_MPEG2Profile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_mpeg2profile) enumeration.

### `dwLevel`

Specifies the MPEG-2 level. This member must be one of the values from the [KS_MPEG2Level](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_mpeg2level) enumeration.

### `dwFlags`

Specifies the flags that indicate preferences. This member can be set to one or more (logical OR) values that are defined in *ksmedia.h*.

| Flag | Meaning |
|---|---|
| **KS_MPEG2_DoPanScan** | If set, the MPEG-2 video decoder should crop the output image based on pan-scan vectors in the picture display extension and change the picture aspect ratio accordingly. |
| **KS_MPEG2_DVDLine21Field1** | If set, the MPEG-2 decoder must be able to produce an output pin for DVD-style closed caption data found in the GOP layer of Field 1. |
| **KS_MPEG2_DVDLine21Field2** | If set, the MPEG-2 decoder must be able to produce an output pin for DVD-style closed caption data found in the GOP layer of Field 2. |
| **KS_MPEG2_SourceIsLetterboxed** | If set, indicates that black bars have been encoded in the top and bottom of the video. |
| **KS_MPEG2_FilmCameraMode** | If set, indicates "film mode" used for 625/50 content. If cleared, indicates that "camera mode" was used. |
| **KS_MPEG2_LetterboxAnalogOut** | If set, and the stream is sent to an analog output, then the stream should be letterboxed. Streams sent to VGA should be letterboxed only by renderers. |
| **KS_MPEG2_DSS_UserData** | If set, the MPEG-2 decoder must process DSS-style user data. |
| **KS_MPEG2_DVB_UserData** | If set, the MPEG-2 decoder must process DVB-style user data. |
| **KS_MPEG2_27MHzTimebase** | If set, the PTS and DTS timestamps advance at 27 MHz rather than 90 kHz. |

### `bSequenceHeader`

The length of the **bSequenceHeader** member, in bytes (zero for DVD).

## See also

[**KS_VIDEOINFOHEADER2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-tagks_videoinfoheader2)