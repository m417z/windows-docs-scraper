# FsRtlCheckLockForReadAccess function

## Description

The **FsRtlCheckLockForReadAccess** routine determines whether the process associated with a given IRP has read access to a locked region of a file.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `Irp` [in]

Pointer to the IRP. Must be an IRP for a read operation.

## Return value

**FsRtlCheckLockForReadAccess** returns **TRUE** if the process has read access, **FALSE** otherwise.

## Remarks

On Microsoft Windows XP and later, **FsRtlCheckLockForReadAccess** checks the process to which the thread that requested the read operation is currently attached.

On Microsoft Windows 2000 and earlier, **FsRtlCheckLockForReadAccess** checks the process that created the thread.

**FsRtlCheckLockForReadAccess** checks to see if there are any conflicting locks in the byte range that is to be read.

**FsRtlCheckLockForReadAccess** does not complete the IRP specified by *Irp*.

Minifilters must call [FltCheckLockForReadAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess) instead of **FsRtlCheckLockForReadAccess**.

## See also

[FltCheckLockForReadAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess)

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlCheckLockForWriteAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforwriteaccess)

[FsRtlFastCheckLockForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforread)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[FsRtlProcessFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)