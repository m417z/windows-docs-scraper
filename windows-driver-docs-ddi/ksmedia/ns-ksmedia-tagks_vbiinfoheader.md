# tagKS_VBIINFOHEADER structure

## Description

The KS_VBIINFOHEADER structure describes raw vertical blanking interval (VBI) streams.

## Members

### `StartLine`

Specifies the line number of the first digitized VBI line.

### `EndLine`

Specifies the line number of the last digitized VBI line.

### `SamplingFrequency`

Specifies the sampling frequency in hertz (Hz).

### `MinLineStartTime`

Specifies the shortest possible interval from the leading edge of H-sync in 10-nanosecond units (that is, in hundredths of microseconds).

### `MaxLineStartTime`

Specifies the longest possible interval from the leading edge of H-sync in 10-nanosecond units (that is, in hundredths of microseconds).

### `ActualLineStartTime`

Specifies the actual starting point of VBI digitization from the leading edge of H-sync in 10-nanosecond units (that is, in hundredths of microseconds).

### `ActualLineEndTime`

Specifies the actual ending point for VBI digitization from the leading edge of H-sync in 10-nanosecond units (that is, in hundredths of microseconds).

### `VideoStandard`

Specifies one or more (logically ORed) values from the [KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard) enumeration.

### `SamplesPerLine`

Specifies the number of samples digitized per video line.

### `StrideInBytes`

Specifies the stride in bytes between the first sample on a given line and the first sample on the next line. This value can be larger than **SamplesPerLine**.

### `BufferSize`

Specifies the size in bytes of the buffer to store the entire digitized VBI signal.

## Remarks

VBI streams are usually converted to NABTS, CC, and WST streams by downstream filters.

## See also

[KS_AnalogVideoStandard](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ks_analogvideostandard)