# FltUninitializeFileLock function

## Description

The **FltUninitializeFileLock** routine uninitializes a FILE_LOCK structure.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock) or [**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock).

## Return value

None

## Remarks

**FltUninitializeFileLock** uninitializes an initialized FILE_LOCK structure, freeing all file locks and completing any outstanding lock operations. The uninitialized FILE_LOCK structure can be initialized for reuse by a subsequent call to [**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock).

**FltUninitializeFileLock** can be used to uninitialize a FILE_LOCK structure allocated by a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock). Do not use **FltUninitializeFileLock** for such a FILE_LOCK structure unless the structure is to be initialized for reuse. It is a programming error to call [**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock) for an uninitialized FILE_LOCK structure.

To allocate and initialize a new file lock structure, call [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

To free an initialized FILE_LOCK structure, call [**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock).

## See also

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FltCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforreadaccess)

[**FltCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock)

[**FsRtlUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtluninitializefilelock)