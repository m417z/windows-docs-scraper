# FsRtlTestAnsiCharacter macro

## Description

The **FsRtlTestAnsiCharacter** macro determines whether an ANSI or double-byte character set (DBCS) character meets the specified criteria.

## Parameters

### `C`

Pointer to the character to be tested.

### `DEFAULT_RET`

Default value to be returned if the value of *(SCHAR *)Character* is < 0.

### `WILD_OK`

Set to **TRUE** if wildcard characters are to be considered legal, **FALSE** otherwise.

### `FLAGS`

Combination of one or more of the flag values described following.

| Flag | Meaning |
| --- | --- |
| FSRTL_FAT_LEGAL | Valid characters for FAT file names are legal. |
| FSRTL_HPFS_LEGAL | Valid characters for HPFS file names are legal. |
| FSRTL_NTFS_LEGAL | Valid characters for NTFS file names are legal. |
| FSRTL_WILD_CHARACTER | Wildcard characters are legal. |
| FSRTL_OLE_LEGAL | Valid characters for NTFS stream names are legal. |
| FSRTL_NTFS_STREAM_LEGAL | FSRTL_NTFS_LEGAL \| FSRTL_OLE_LEGAL |

## Remarks

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[FsRtlIsAnsiCharacterLegal](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegal)

[FsRtlIsAnsiCharacterLegalFat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalfat)

[FsRtlIsAnsiCharacterLegalHpfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalhpfs)

[FsRtlIsAnsiCharacterLegalNtfs](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlisansicharacterlegalntfs)