# _timecode structure

## Description

The TIMECODE union describes a timecode from an external device. This structure is no longer used.

## Members

### `wFrameRate`

Specifies the frame rate.

### `wFrameFract`

Specifies the fractional frame. The full-scale frame is 0x1000.

### `dwFrames`

Specifies a timecode value as a binary frame count.

### `qw`

Specifies the timecode as a quad-word.

## Remarks

This structure is defined for the purpose of searching to a timecode based on an absolute track number (ATN) and/or relative time counter (RTC). However, not all devices support searching to a timecode using this structure.

## See also

[KSPROPERTY_EXTXPORT_RAW_AVC_CMD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-raw-avc-cmd)