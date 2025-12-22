# FsRtlIsAnsiCharacterLegal macro

## Description

The **FsRtlIsAnsiCharacterLegal** macro determines whether a character is a legal ANSI character.

## Parameters

### `C`

The character to be tested.

### `FLAGS`

Combination of one or more of the following flag values:

| Flag | Meaning |
| --- | --- |
| FSRTL_FAT_LEGAL | Valid characters for FAT file names are legal. |
| FSRTL_HPFS_LEGAL | Valid characters for high-performance file system (HPFS) file names are legal. |
| FSRTL_NTFS_LEGAL | Valid characters for NTFS file names are legal. |
| FSRTL_WILD_CHARACTER | Wildcard characters are legal. |
| FSRTL_OLE_LEGAL | Valid characters for NTFS stream names are legal. |
| FSRTL_NTFS_STREAM_LEGAL | FSRTL_NTFS_LEGAL \| FSRTL_OLE_LEGAL |

## Remarks

To be a legal ANSI character, a character must be present in the ANSI legal character array and must satisfy the input flag settings.

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[FsRtlIsAnsiCharacterLegalFat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalfat)

[FsRtlIsAnsiCharacterLegalHpfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalhpfs)

[FsRtlIsAnsiCharacterLegalNtfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalntfs)