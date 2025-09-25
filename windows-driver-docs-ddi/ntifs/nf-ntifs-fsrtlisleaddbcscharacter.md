# FsRtlIsLeadDbcsCharacter macro

## Description

The **FsRtlIsLeadDbcsCharacter** macro determines whether a character is a lead byte (the first byte of a character) in a double-byte character set (DBCS).

## Parameters

### `DBCS_CHAR`

The character to be tested.

## Remarks

Lead bytes are unique to double-byte character sets. A lead byte introduces a double-byte character. Lead bytes occupy a specific range of byte values. The **FsRtlIsLeadDbcsCharacter** macro uses the system code page to check lead-byte ranges.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[FsRtlDissectDbcs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldissectdbcs)

[FsRtlDoesDbcsContainWildCards](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtldoesdbcscontainwildcards)

[FsRtlIsDbcsInExpression](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlisdbcsinexpression)