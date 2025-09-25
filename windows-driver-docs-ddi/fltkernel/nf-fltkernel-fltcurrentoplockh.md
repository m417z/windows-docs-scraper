# FltCurrentOplockH function

## Description

A minifilter driver calls the **FltCurrentOplockH** routine to determine whether there are any CACHE_HANDLE_LEVEL opportunistic locks (oplocks) on a file.

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

## Return value

**FltCurrentOplockH** returns **TRUE** if there are CACHE_HANDLE_LEVEL oplocks that are currently being held. Otherwise, it returns **FALSE**.

## Remarks

**FltCurrentOplockH** returns **FALSE** if no CACHE_HANDLE_LEVEL opportunistic locks are currently held.

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

## See also

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FsRtlCurrentOplockH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcurrentoplockh)