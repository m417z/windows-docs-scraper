# FsRtlIsAnsiCharacterLegalFat macro

## Description

The **FsRtlIsAnsiCharacterLegalFat** macro determines whether an ANSI character is legal for FAT file names.

## Parameters

### `C`

Pointer to the character to be tested.

### `WILD_OK`

Set to **TRUE** if wildcard characters are to be considered legal, **FALSE** otherwise.

## See also

[FsRtlIsAnsiCharacterLegal](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegal)

[FsRtlIsAnsiCharacterLegalHpfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalhpfs)

[FsRtlIsAnsiCharacterLegalNtfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalntfs)