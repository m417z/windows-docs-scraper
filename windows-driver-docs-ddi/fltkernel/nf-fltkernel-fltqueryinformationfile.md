# FltQueryInformationFile function

## Description

**FltQueryInformationFile** retrieves information for a given file.

## Parameters

### `Instance` [in]

Opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

File object pointer for the file. This parameter is required and cannot be **NULL**.

### `FileInformation` [out]

Pointer to a caller-allocated buffer that receives information about the file. The *FileInformationClass* parameter specifies the type of information. This parameter is required and cannot be **NULL**.

### `Length` [in]

Size, in bytes, of the *FileInformation* buffer.

### `FileInformationClass` [in]

A [FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class) value that specifies the type of file information to be returned in the *FileInformation* buffer.

### `LengthReturned` [out, optional]

Pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in the *FileInformation* buffer. This parameter is optional and can be **NULL**.

## Return value

**FltQueryInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| --- | --- |
| STATUS_VOLUME_DISMOUNTED | The file resides on a volume that is not currently mounted. This is an error code. |

## Remarks

A minifilter driver calls **FltQueryInformationFile** to retrieve information for the file identified by *FileObject*. The file must currently be open.

**FltQueryInformationFile** returns zero in any member of a FILE_*XXX*_INFORMATION structure that is not supported by a particular file system.

Callers of **FltQueryInformationFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

**NOTE:**
Do not call this routine with a non-NULL top level IRP value, as this can cause a system deadlock.

## See also

[FILE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_file_information_class)

[FltQueryVolumeInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryvolumeinformationfile)

[FltSetInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetinformationfile)

[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)