## Description

**FsRtlQueryInformationFile** builds an explicit file query information IRP (IRP_MJ_QUERY_INFORMATION), sends it down the stack, synchronously waits for it to complete, and returns the result. This function allows the caller to complete this action by **FileObject** instead of handle.

## Parameters

### `FileObject` [in]

Pointer to the [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) to send the operation on.

### `FileInformation` [out]

Pointer to a caller-allocated buffer to receive the queried file information.

### `Length` [in]

Size in bytes of the buffer that **FileInformation** points to.

### `FileInformationClass` [in]

A [**FILE_INFORMATION_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) value that specifies the type of file information being queried.

### `RetFileInformationSize` [out]

Receives the number of bytes written (returned) into the buffer that **FileInformation** points to.

## Return value

**FsRtlKernelFsControlFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following.

| Value | Meaning |
| ----- | ------- |
| STATUS_INSUFFICIENT_RESOURCES | A pool allocation failure occurred. |
| STATUS_INVALID_PARAMETER | An invalid parameter was provided (for example, an invalid **FileObject**). |

## Remarks

This routine assumes all passed in buffers are kernel mode buffers.

## See also

[**ZwQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwqueryinformationfile)