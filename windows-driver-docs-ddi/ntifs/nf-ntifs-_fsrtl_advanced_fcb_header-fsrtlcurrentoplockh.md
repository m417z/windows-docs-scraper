# FsRtlCurrentOplockH function

## Description

A file system or filter driver calls **FsRtlCurrentOplockH** to determine whether there are any CACHE_HANDLE_LEVEL opportunistic locks (oplocks) on a file.

## Parameters

### `Oplock` [in]

An opaque opportunistic lock pointer for the file. This pointer must have been initialized by a previous call to [FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

## Return value

**FsRtlCurrentOplockH** returns **TRUE** if there are CACHE_HANDLE_LEVEL opportunistic locks that are currently being held. Otherwise, it returns **FALSE**.

## Remarks

**FsRtlCurrentOplockH** returns **FALSE** if no CACHE_HANDLE_LEVEL opportunistic locks (oplocks) are currently held.

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

Minifilters should call [FltCurrentOplockH](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentoplockh) instead of **FsRtlCurrentOplock**.

## See also

[FltCurrentOplockH](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcurrentoplockh)

[FsRtlInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock)