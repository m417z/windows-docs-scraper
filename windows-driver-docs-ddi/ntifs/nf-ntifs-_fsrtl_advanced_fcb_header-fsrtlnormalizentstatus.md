# FsRtlNormalizeNtstatus function

## Description

The **FsRtlNormalizeNtstatus** routine translates an arbitrary exception into a status value that is handled by the exception filter.

## Parameters

### `Exception` [in]

Status value of the exception.

### `GenericException` [in]

Generic status value to return if *Exception* is not within the set of exceptions handled by the filter.

## Return value

**FsRtlNormalizeNtstatus** returns *Exception* if the status value is handled by the exception filter, *GenericException* otherwise.

## See also

[FsRtlIsNtstatusExpected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisntstatusexpected)