# FsRtlLookupLargeMcbEntry function

## Description

Given a virtual block number (VBN) and a map control block (MCB), the **FsRtlLookupLargeMcbEntry** routine searches the MCB for mapping information corresponding to the specified VBN.

## Parameters

### `Mcb`

Pointer to an initialized MCB structure.

### `Vbn`

Pointer to the requested VBN.

### `Lbn`

Pointer to a variable that receives the LBN that is mapped to **LargeVbn** in the mapping entry, or -1 if no such LBN exists. This parameter is optional and can be NULL.

### `SectorCountFromLbn`

Pointer to a variable that receives the number of sectors that follow **LargeVbn** in the mapping run. This parameter is optional and can be NULL.

### `StartingLbn`

Pointer to a variable that receives the LBN corresponding to the start of the mapping run, or -1 if no such LBN exists. This parameter is optional and can be NULL.

### `SectorCountFromStartingLbn`

Pointer to a variable that receives the number of sectors in the mapping run. This parameter is optional and can be NULL.

### `Index` [out, optional]

Pointer to a variable that receives the index of the mapping run that contains the VBN. This parameter is optional and can be NULL.

## Return value

**FsRtlLookupLargeMcbEntry** returns TRUE if the specified VBN is within the range of VBNs that are mapped by the MCB, FALSE otherwise.

## Remarks

**FsRtlLookupLargeMcbEntry** searches for a mapping entry in the MCB whose run includes the specified VBN.

* If such a mapping exists, the lookup operation yields positive values for the corresponding LBN and sector count, and **FsRtlLookupLargeMcbEntry** returns TRUE.

* If no such mapping exists, but the specified VBN is lower than the highest VBN mapped by the MCB, this is referred to as a hole in the mapping. In this case, **FsRtlLookupLargeMcbEntry** still returns TRUE, but the lookup operation yields a value of -1 for the LBN.

* If the specified VBN is higher than the highest VBN mapped by the MCB, or if the MCB contains no mappings, **FsRtlLookupLargeMcbEntry** returns FALSE.

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