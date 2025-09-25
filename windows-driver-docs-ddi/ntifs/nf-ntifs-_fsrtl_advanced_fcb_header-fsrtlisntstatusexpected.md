# FsRtlIsNtstatusExpected function

## Description

The **FsRtlIsNtstatusExpected** routine determines whether the specified exception is handled by the exception filter.

## Parameters

### `Exception` [in]

Status value of the exception.

## Return value

**FsRtlIsNtstatusExpected** returns **TRUE** if the status value indicates a nonfatal system error status, **FALSE** otherwise.

## Remarks

File systems use **FsRtlIsNtstatusExpected** to determine whether to attempt to handle an exception.

## See also

[FsRtlNormalizeNtstatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnormalizentstatus)