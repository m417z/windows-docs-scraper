# TAPE_SET_DRIVE_PARAMETERS structure

## Description

The
**TAPE_SET_DRIVE_PARAMETERS** structure describes the tape drive. It is used by the [SetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeparameters) function.

## Members

### `ECC`

If this member is **TRUE**, hardware error correction is supported. Otherwise, it is not.

### `Compression`

If this member is **TRUE**, hardware data compression is enabled. Otherwise, it is disabled.

### `DataPadding`

If this member is **TRUE**, data padding is enabled. Otherwise, it is disabled. Data padding keeps the tape streaming at a constant speed.

### `ReportSetmarks`

If this member is **TRUE**, setmark reporting is enabled. Otherwise, it is disabled.

### `EOTWarningZoneSize`

Number of bytes between the end-of-tape warning and the physical end of the tape.

## See also

[SetTapeParameters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-settapeparameters)