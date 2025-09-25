# FsRtlGetNextLargeMcbEntry function

## Description

The **FsRtlGetNextLargeMcbEntry** routine retrieves a mapping run from a map control block (MCB).

## Parameters

### `Mcb`

Pointer to an initialized MCB structure.

### `RunIndex` [in]

Zero-based index of the requested mapping run.

### `Vbn`

Pointer to a variable that receives the starting virtual block number (VBN) of the mapping run, or zero if the run does not exist. Its value is meaningless if **FsRtlGetNextLargeMcbEntry** returns **FALSE**.

### `Lbn`

Pointer to a variable that receives the starting logical block number (LBN) of the mapping run, or zero if the run does not exist. Its value is meaningless if **FsRtlGetNextLargeMcbEntry** returns **FALSE**.

### `SectorCount`

Pointer to a variable that receives the number of sectors in the mapping run, or zero if the run does not exist. Its value is meaningless if **FsRtlGetNextLargeMcbEntry** returns **FALSE**.

## Return value

**FsRtlGetNextLargeMcbEntry** returns **TRUE** if the requested mapping run exists in the MCB, **FALSE** otherwise.

## Remarks

**FsRtlGetNextLargeMcbEntry** retrieves the starting VBN, starting LBN, and sector count for a mapping run in an MCB.

**Note** The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

Holes are counted as runs.

The following code snippet shows how to print out all of the runs in a file:

```
for (i = 0; FsRtlGetNextLargeMcbEntry(Mcb,i,&Vbn,&Lbn,&Count); i++) {

    // print out vbn, lbn, and count

}
```

## See also

[FsRtlAddLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[FsRtlInitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializelargemcb)

[FsRtlLookupLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry)

[FsRtlLookupLastLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[FsRtlLookupLastLargeMcbEntryAndIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[FsRtlNumberOfRunsInLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[FsRtlRemoveLargeMcbEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[FsRtlSplitLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[FsRtlTruncateLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[FsRtlUninitializeLargeMcb](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)