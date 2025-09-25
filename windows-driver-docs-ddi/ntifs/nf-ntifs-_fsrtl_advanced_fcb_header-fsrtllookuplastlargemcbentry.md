# FsRtlLookupLastLargeMcbEntry function

## Description

The **FsRtlLookupLastLargeMcbEntry** routine retrieves the last mapping entry stored in the map control block (MCB).

## Parameters

### `Mcb`

Pointer to an initialized MCB structure to be searched.

### `Vbn`

Pointer to a variable that receives the last virtual block number (VBN) that was mapped.

### `Lbn`

Pointer to a variable that receives the logical block number (LBN) that is mapped to the VBN pointed to by **LargeVbn**, or -1 if no such LBN exists.

## Return value

**FsRtlLookupLastLargeMcbEntry** returns FALSE if the MCB contains no mapping entries, TRUE otherwise.

## Remarks

**FsRtlLookupLastLargeMcbEntry** searches for the last mapping of the last run in the MCB:

* If the MCB contains no mappings, **FsRtlLookupLastLargeMcbEntry** returns FALSE.

* If the last mapping is a hole, **FsRtlLookupLastLargeMcbEntry** returns TRUE, but the lookup operation yields a value of -1 for the LBN.

* If the last mapping is not a hole, the lookup operation yields a positive value for the LBN, and **FsRtlLookupLastLargeMcbEntry** returns TRUE.

The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

## See also

[**FsRtlAddLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[**FsRtlGetNextLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[**FsRtlInitializeLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[**FsRtlLookupLastLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[**FsRtlLookupLastLargeMcbEntryAndIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[**FsRtlNumberOfRunsInLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[**FsRtlRemoveLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[**FsRtlSplitLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[**FsRtlTruncateLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[**FsRtlUninitializeLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)