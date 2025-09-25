# FsRtlInitializeLargeMcb function

## Description

The **FsRtlInitializeLargeMcb** routine initializes a map control block (MCB) structure.

## Parameters

### `Mcb`

Pointer to a caller-allocated MCB structure to initialize.

### `PoolType` [in]

Type of pool to use when allocating additional internal storage for the MCB. One of the following:

* **NonPagedPool**
* **PagedPool**
* **NonPagedPoolCacheAligned**
* **PagedPoolCacheAligned**

The **NonPagedPoolMustSucceed** and **NonPagedPoolCacheAlignedMustS** pool types are obsolete and should no longer be used.

## Remarks

**FsRtlInitializeLargeMcb** initializes a map control block (MCB) structure. File systems use MCB structures to map virtual block numbers (VBN) for a file to the corresponding logical block numbers (LBN) on disk.

The upper 32 bits of the LBN are ignored. Only the lower 32 bits are used.

File systems must call **FsRtlInitializeLargeMcb** before using any other **FsRtl*Xxx*Mcb*Yyy*** routines on the MCB structure.

If a pool allocation failure occurs, **FsRtlInitializeLargeMcb** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlInitializeLargeMcb** in a *try-except* or *try-finally* statement.

## See also

[**FsRtlAddLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtladdlargemcbentry)

[**FsRtlGetNextLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlgetnextlargemcbentry)

[**FsRtlLookupLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplargemcbentry)

[**FsRtlLookupLastLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentry)

[**FsRtlLookupLastLargeMcbEntryAndIndex**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtllookuplastlargemcbentryandindex)

[**FsRtlNumberOfRunsInLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnumberofrunsinlargemcb)

[**FsRtlRemoveLargeMcbEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlremovelargemcbentry)

[**FsRtlSplitLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlsplitlargemcb)

[**FsRtlTruncateLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtltruncatelargemcb)

[**FsRtlUninitializeLargeMcb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializelargemcb)