# TIMECODE_SAMPLE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `TIMECODE_SAMPLE` structure contains complete timecode information.

## Members

### `qwTick`

Reference time, in 100-nanosecond units.

### `timecode`

[TIMECODE](https://learn.microsoft.com/windows/desktop/DirectShow/getting-timecode-from-the-device) structure.

### `dwUser`

Packed SMPTE userbits.

### `dwFlags`

Timecode flag masks. Specify one or more of the following values.

| Value | Meaning |
| --- | --- |
| **AM_TIMECODE_FLAG_FCM** | Frame code mode; 0 = nondrop; 1 = drop. |
| **AM_TIMECODE_FLAG_CF** | Color frame flag. |
| **AM_TIMECODE_FLAG_FIELD** | Field flag. |
| **AM_TIMECODE_FLAG_DF** | Drop frame flag (from flags in actual timecode on external media). |
| **AM_TIMECODE_COLORFRAME** | Specifies frame in color sequence. |
| **AM_TIMECODE_COLORSEQUENCE** | Duration in frames of complete sequence. |
| **AM_TIMECODE_FILMSEQUENCE_TYPE** | One of the FILM_SEQUENCE_XXX defines. |
| **ED_DEVCAP_TIMECODE_READ** | Read SMPTE timecode; applies to DV camcorders. |
| **ED_DEVCAP_ATN_READ** | Read the absolute track number (ATN); applies to DV camcorders. This constant is defined in the header file Xprtdefs.h. |
| **ED_DEVCAP_RTC_READ** | Read the relative time counter (RTC); applies to MPEG camcorders. This constant is defined in the header file Xprtdefs.h. |

## Remarks

The upper 16 bits in **dwFlags** are reserved; set to zero.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IAMTimecodeReader::GetTimecode](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamtimecodereader-gettimecode)