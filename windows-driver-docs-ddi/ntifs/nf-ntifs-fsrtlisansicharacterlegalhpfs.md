# FsRtlIsAnsiCharacterLegalHpfs macro

## Description

The **FsRtlIsAnsiCharacterLegalHpfs** macro determines whether an ANSI character is legal for HPFS file names.

## Parameters

### `C`

Pointer to the character to be tested.

### `WILD_OK`

Set to **TRUE** if wildcard characters are to be considered legal, **FALSE** otherwise.

## Remarks

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[FsRtlIsAnsiCharacterLegal](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegal)

[FsRtlIsAnsiCharacterLegalFat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalfat)

[FsRtlIsAnsiCharacterLegalNtfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalntfs)