# FsRtlRemoveLargeMcbEntry function

## Description

The **FsRtlRemoveLargeMcbEntry** routine removes one or more mappings from a map control block (MCB).

## Parameters

### `Mcb`

Pointer to the MCB structure.

### `Vbn`

Starting virtual block number (VBN) of the range for which mappings are to be removed from the MCB.

### `SectorCount`

Number of sectors (VBNs) in the range for which mappings are to be removed.

## Remarks

**FsRtlRemoveLargeMcbEntry** removes all mappings of VBNs to LBNs in the MCB that fall within the range of VBNs that begins with **LargeVbn* and ends with (**LargeVbn* + *LargeSectorCount* - 1).

**Note** The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

Holes (gaps) between mappings are ignored.

If the range of VBNs to be removed includes the highest mapped VBN in the MCB, the MCB's **PairCount** member is adjusted accordingly.

If a pool allocation failure occurs, **FsRtlRemoveLargeMcbEntry** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlRemoveLargeMcbEntry** in a **try-except** or **try-finally** statement.

## See also

[FsRtlAddLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[FsRtlGetNextLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[FsRtlLookupLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry)

[FsRtlLookupLastLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[FsRtlLookupLastLargeMcbEntryAndIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[FsRtlNumberOfRunsInLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[FsRtlSplitLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[FsRtlTruncateLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[FsRtlUninitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)