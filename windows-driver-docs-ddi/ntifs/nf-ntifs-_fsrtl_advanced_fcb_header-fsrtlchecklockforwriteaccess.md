# FsRtlCheckLockForWriteAccess function

## Description

The **FsRtlCheckLockForWriteAccess** routine determines whether the process associated with a given IRP has write access to a locked region of a file.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `Irp` [in]

Pointer to the IRP. Must be an IRP for a write operation.

## Return value

**FsRtlCheckLockForWriteAccess** returns **TRUE** if the process has write access, **FALSE** otherwise.

## Remarks

On Microsoft Windows XP and later, **FsRtlCheckLockForWriteAccess** checks the process to which the thread that requested the write operation is currently attached.

On Microsoft Windows 2000 and earlier, **FsRtlCheckLockForWriteAccess** checks the process that created the thread.

**FsRtlCheckLockForWriteAccess** checks to see if there are any conflicting locks in the byte range that is to be written.

**FsRtlCheckLockForWriteAccess** does not complete the IRP specified by *Irp*.

Minifilters must call [FltCheckLockForWriteAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess) instead of **FsRtlCheckLockForWriteAccess**.

## See also

[FltCheckLockForWriteAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[FsRtlAllocateFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[FsRtlCheckLockForReadAccess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[FsRtlFastCheckLockForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlfastchecklockforwrite)

[FsRtlInitializeFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[FsRtlProcessFileLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlprocessfilelock)