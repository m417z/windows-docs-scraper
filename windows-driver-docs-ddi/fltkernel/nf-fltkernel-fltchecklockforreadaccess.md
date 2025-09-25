# FltCheckLockForReadAccess function

## Description

The **FltCheckLockForReadAccess** routine determines whether the caller has read access to a locked byte range of a file.

## Parameters

### `FileLock` [in]

Pointer to the FILE_LOCK structure for the file. This structure must have been initialized by a previous call to [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock) or [**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock).

### `CallbackData` [in]

Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the [**IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) operation.

## Return value

**FltCheckLockForReadAccess** returns TRUE if the process has read access, FALSE otherwise.

## Remarks

**FltCheckLockForReadAccess** checks whether the caller has read access to the entire byte range indicated in the callback data structure.

**FltCheckLockForReadAccess** does not complete the [**IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) operation.

To allocate and initialize a new file lock structure, call [**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock).

To free an initialized FILE_LOCK structure, call [**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock).

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatefilelock)

[**FltCheckLockForWriteAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltchecklockforwriteaccess)

[**FltFreeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreefilelock)

[**FltInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltinitializefilelock)

[**FltProcessFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprocessfilelock)

[**FltUninitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltuninitializefilelock)

[**FsRtlCheckLockForReadAccess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlchecklockforreadaccess)

[**IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read)