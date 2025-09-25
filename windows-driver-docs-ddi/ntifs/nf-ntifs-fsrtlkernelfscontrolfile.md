## Description

The **FsRtlKernelFsControlFile** function builds an explicit FSCTL_XXX IRP, sends it down the stack, synchronously waits for it to complete, and returns the result. This function allows the caller to complete this action by **FileObject** instead of handle.

## Parameters

### `FileObject` [in]

Pointer to the [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) to send the operation on.

### `FsControlCode` [in]

FSCTL_XXX code that indicates which file system control operation is to be carried out. The value of this parameter determines the formats and required lengths of the **InputBuffer** and **OutputBuffer**, as well as which of the following parameter pairs are required. For detailed information about the system-defined FSCTL_XXX codes, see the "Remarks" section of the reference entry for [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) in the Microsoft Windows SDK documentation.

### `InputBuffer` [in]

Pointer to a caller-allocated input buffer that contains device-specific information to be given to the target driver. If **FsControlCode** specifies an operation that does not require input data, this pointer is optional and can be NULL. Note that this buffer might be modified upon return and the caller must adapt to this. This is because this buffer might be used to hold the output data.

### `InputBufferLength` [in]

Length of the **InputBuffer** in bytes.

### `OutputBuffer` [out]

Pointer to a caller-allocated output buffer in which information is returned from the target driver. If **FsControlCode** specifies an operation that does not produce output data, this pointer is optional and can be NULL.

### `OutputBufferLength` [out]

Length of the **OutputBuffer** in bytes.

### `RetOutputBufferSize` [out]

Receives the number of bytes actually written (returned) in the output buffer.

## Return value

**FsRtlKernelFsControlFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following.

| Value | Meaning |
| ----- | ------- |
| STATUS_INSUFFICIENT_RESOURCES | A pool allocation failure occurred. |
| STATUS_INVALID_PARAMETER | An invalid parameter was provided (for example, an invalid **FileObject**). |

## Remarks

**FsRtlKernelFsControlFile** sets the IRP_MN_KERNEL_CALL minor code which allows it to perform operations without requiring manage volume privilege for certain operations.

This function assumes that all buffers passed to it are kernel-mode buffers.

## See also

[**ZwFsControlFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwfscontrolfile)