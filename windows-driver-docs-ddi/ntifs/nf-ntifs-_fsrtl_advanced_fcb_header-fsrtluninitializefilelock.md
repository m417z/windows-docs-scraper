# FsRtlUninitializeFileLock function

## Description

The **FsRtlUninitializeFileLock** routine uninitializes a [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure.

## Parameters

### `FileLock` [in]

Pointer to the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure for the file. This structure must have been initialized by a previous call to [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

## Remarks

**FsRtlUninitializeFileLock** uninitializes an initialized FILE_LOCK structure and completes any outstanding [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control) requests. The uninitialized FILE_LOCK structure can be initialized for reuse by a subsequent call to [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

**FsRtlUninitializeFileLock** can be used to uninitialize a FILE_LOCK structure that was initialized by a previous call to [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock). Do not use **FsRtlUninitializeFileLock** for such a FILE_LOCK structure unless the structure is to be initialized for reuse. It is a programming error to call **FsRtlFreeFileLock** for an uninitialized FILE_LOCK structure.

Minifilters must call [**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock) instead of **FsRtlIninitializeFileLock**.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock)

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)

[**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control)

[**PCOMPLETE_LOCK_IRP_ROUTINE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nc-ntifs-pcomplete_lock_irp_routine)