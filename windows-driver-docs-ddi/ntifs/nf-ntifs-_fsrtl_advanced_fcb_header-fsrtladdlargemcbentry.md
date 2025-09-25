# FsRtlAddLargeMcbEntry function

## Description

The **FsRtlAddLargeMcbEntry** routine adds a new mapping to an existing map control block (MCB).

## Parameters

### `Mcb`

Pointer to an initialized MCB structure.

### `Vbn`

Starting virtual block number (VBN) of the new mapping run to be added to the MCB.

### `Lbn`

Logical block number (LBN) to which *LargeVbn* is to be mapped.

### `SectorCount`

Number of sectors in the new mapping run.

## Return value

**FsRtlAddLargeMcbEntry** returns **TRUE** if the new mapping was successfully added to the MCB, **FALSE** otherwise.

## Remarks

**FsRtlAddLargeMcbEntry** adds a new mapping to an existing map control block (MCB). File systems use MCB structures to map virtual block numbers (VBN) for a file to the corresponding logical block numbers (LBN) on disk.

**Note** The upper 32 bits of the LBN are ignored, but they must be set to zero. Only the lower 32 bits are used.

If a new mapping run to be added overlaps an existing mapping run, **FsRtlAddLargeMcbEntry** merges them into a single mapping run.

If a pool allocation failure occurs, **FsRtlAddLargeMcbEntry** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlAddLargeMcbEntry** in a **try-except** or **try-finally** statement.

To initialize an MCB, call [FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb). To uninitialize an MCB, call [FsRtlUninitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb).

## See also

[FsRtlGetNextLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[FsRtlLookupLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry)

[FsRtlLookupLastLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[FsRtlLookupLastLargeMcbEntryAndIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[FsRtlNumberOfRunsInLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[FsRtlRemoveLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[FsRtlSplitLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[FsRtlTruncateLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[FsRtlUninitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)