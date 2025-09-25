## Description

The TIMECODE_SAMPLE structure describes a complete timecode.

## Members

### `qwTick`

Specifies a reference time, in 100-nanosecond units.

### `timecode`

Specifies the [**TIMECODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_timecode) structure.

### `dwUser`

Specifies packed SMPTE user-bits.

### `dwFlags`

Specifies any optional timecode flag masks.

| Flag | Meaning |
|---|---|
| AM_TIMECODE_FLAG_FCM | Frame-code mode; 0 = nondrop; 1 = drop. |
| AM_TIMECODE_FLAG_CF | Color-frame flag. |
| AM_TIMECODE_FLAG_FIELD | Field flag. |
| AM_TIMECODE_FLAG_DF | Drop-frame flag (from flags in actual timecode on external media). |
| AM_TIMECODE_COLORFRAME | Specifies frame, in color sequence. |
| AM_TIMECODE_COLORSEQUENCE | Duration, in frames, of complete sequence. |
| AM_TIMECODE_FILMSEQUENCE_TYPE | One of the FILM_SEQUENCE\_*XXX* tokens. |
| ED_DEVCAP_TIMECODE_READ | Read SMPTE timecode; applies to DV camcorders. |
| ED_DEVCAP_ATN_READ | Read the absolute track number (ATN); applies to DV camcorders. |
| ED_DEVCAP_RTC_READ | Read the relative time counter (RTC); applies to MPEG camcorders. |

## Remarks

Any ED_Xxx tokens are defined in *xprtdefs.h* in the DirectX SDK.

The upper 16 bits in **dwFlags** are reserved for future use and must be set to zero.

## See also

[**TIMECODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-_timecode)