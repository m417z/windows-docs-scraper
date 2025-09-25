# FsRtlNumberOfRunsInLargeMcb function

## Description

The **FsRtlNumberOfRunsInLargeMcb** routine returns the number of runs in a map control block (MCB).

## Parameters

### `Mcb`

Supplies the MCB being examined.

## Return value

Returns the number of distinct runs mapped by the input MCB.

## Remarks

**FsRtlNumberOfRunsInLargeMcb** returns the number of distinct runs mapped by an MCB.

Runs can be mappings or holes. A *mapping* is a continuous range of VBNs that is mapped to a corresponding range of logical block numbers (LBN). Mappings cannot overlap. A *hole* is a continuous range of unmapped VBNs that falls between two mappings. Within the entire range of mapped VBNs, every VBN belongs to exactly one mapping or hole.

**Note** The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

**FsRtlNumberOfRunsInLargeMcb** counts both types of runs. For example, an MCB containing a mapping for only VBNs zero and three will have three runs: one for VBN 0, one for the hole covering VBN 1 and VBN 2, and one for VBN 3.

## See also

[FsRtlAddLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[FsRtlGetNextLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[FsRtlLookupLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry)

[FsRtlLookupLastLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[FsRtlLookupLastLargeMcbEntryAndIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[FsRtlRemoveLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[FsRtlSplitLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[FsRtlTruncateLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[FsRtlUninitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)