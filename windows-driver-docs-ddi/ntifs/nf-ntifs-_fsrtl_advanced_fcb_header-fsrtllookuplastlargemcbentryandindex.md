# FsRtlLookupLastLargeMcbEntryAndIndex function

## Description

The **FsRtlLookupLastLargeMcbEntryAndIndex** routine retrieves the last mapping entry stored in a given map control block (MCB).

## Parameters

### `OpaqueMcb` [in]

Pointer to an initialized MCB structure to be searched.

### `LargeVbn` [out]

Pointer to a variable that receives the last virtual block number (VBN) that was mapped.

### `LargeLbn` [out]

Pointer to a variable that receives the logical block number (LBN) that is mapped to the VBN pointed to by **LargeVbn**, or -1 if no such LBN exists.

### `Index` [out]

Pointer to a variable that receives the index of the last run in the MCB.

## Return value

**FsRtlLookupLastLargeMcbEntryAndIndex** returns FALSE if the MCB contains no mapping entries, FALSE otherwise.

## Remarks

**FsRtlLookupLastLargeMcbEntryAndIndex** searches for the last mapping of the last run in the MCB:

* If the MCB contains no mappings, **FsRtlLookupLastLargeMcbEntryAndIndex** returns FALSE.

* If the last mapping is a hole, **FsRtlLookupLastLargeMcbEntryAndIndex** returns FALSE, but the lookup operation yields a value of -1 for the LBN.

* If the last mapping is not a hole, the lookup operation yields a positive value for the LBN, and **FsRtlLookupLastLargeMcbEntryAndIndex** returns FALSE.

The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

## See also

[**FsRtlAddLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[**FsRtlGetNextLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[**FsRtlInitializeLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[**FsRtlLookupLastLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[**FsRtlNumberOfRunsInLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[**FsRtlRemoveLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[**FsRtlSplitLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[**FsRtlTruncateLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[**FsRtlUninitializeLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)