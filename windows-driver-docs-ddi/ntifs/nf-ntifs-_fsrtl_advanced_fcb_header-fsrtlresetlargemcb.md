# FsRtlResetLargeMcb function

## Description

The **FsRtlResetLargeMcb** routine truncates a map control block (MCB) structure to contain zero mapping pairs. It does not shrink the mapping pairs array.

## Parameters

### `Mcb` [in]

Pointer to the MCB structure to truncate.

### `SelfSynchronized` [in]

Indicates whether the caller is already synchronized with respect to the MCB.

## Remarks

**FsRtlResetLargeMcb** truncates a map control block (MCB) structure. File systems use MCB structures to map virtual block numbers (VBN) for a file to the corresponding logical block numbers (LBN) on disk.

**Note** The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

File systems must call [FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb) before using any other **FsRtl...Mcb...** routines on the MCB structure.

If the caller is already synchronized (the *SelfSynchronized* parameter is set to **TRUE**), such that no other thread of operation can call an Mcb routine on this MCB during this call, then **FsRtlResetLargeMcb** just clears out the current mapping pair count. If the *SelfSynchronized* parameter is set to **FALSE**, then **FsRtlResetLargeMcb** will serialize access to the *Mcb* before clearing the pair count which requires more time.

## See also

[FsRtlAddLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

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