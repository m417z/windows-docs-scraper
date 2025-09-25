# FsRtlProcessFileLock function

## Description

The **FsRtlProcessFileLock** routine processes and completes an IRP for a file lock operation.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `Irp` [in]

Pointer to the IRP. Must be an IRP for a file-lock operation.

### `Context` [in, optional]

Optional context pointer to be used when completing IRPs.

## Return value

**FsRtlProcessFileLock** returns STATUS_SUCCESS on success; otherwise it returns an appropriate error status code.

## Remarks

**FsRtlProcessFileLock** performs the specified lock operation on behalf of the process associated with thread that originally requested the operation.

On Microsoft Windows XP and later, this is the process to which the thread is currently attached.

On Microsoft Windows 2000 and earlier, it is the process that created the thread.

Callers of **FsRtlProcessFileLock** relinquish control of the input IRP.

Minifilters must call [**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock) instead of **FsRtlProcessFileLock**.

## See also

[**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock)

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)