# FltCurrentOplock function

## Description

A minifilter driver calls the **FltCurrentOplock** routine to determine whether there are any opportunistic locks (oplocks) on a file.

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock).

## Return value

**FltCurrentOplock** returns **TRUE** if there are oplocks that are currently being held. Otherwise, it returns **FALSE**.

## Remarks

**FltCurrentOplock** returns **FALSE** if no opportunistic locks are currently held.

For more information about opportunistic locks, see the Microsoft Windows SDK documentation.

## See also

[FltInitializeOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializeoplock)

[FsRtlCurrentOplock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcurrentoplock)