# FsRtlCurrentOplock function

## Description

A file system or filter driver calls **FsRtlCurrentOplock** to determine whether there are any opportunistic locks (oplocks) on a file.

## Parameters

### `Oplock` [in]

An opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

## Return value

**FsRtlCurrentOplock** returns **TRUE** if there are opportunistic locks (oplocks) that are currently being held. Otherwise, it returns **FALSE**.

## Remarks

**FsRtlCurrentOplock** returns **FALSE** if no opportunistic locks are currently held.

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [FltCurrentOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentoplock) instead of **FsRtlCurrentOplock**.

## See also

[FltCurrentOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentoplock)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)