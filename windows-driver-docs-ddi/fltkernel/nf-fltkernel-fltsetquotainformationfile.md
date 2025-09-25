# FltSetQuotaInformationFile function

## Description

The **FltSetQuotaInformationFile** routine modifies quota entries for a file object.

## Parameters

### `Instance` [in]

An opaque instance pointer for the minifilter driver instance that the operation is to be sent to. The instance must be attached to the volume where the file resides.

### `FileObject` [in]

The file object pointer for the file.

### `Buffer` [in]

A pointer to a caller-supplied, [FILE_GET_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)-structured input buffer that contains the quota information entries to be set.

### `Length` [in]

The length, in bytes, of the buffer that the *Buffer* parameter points to.

## Return value

**FltSetQuotaInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following.

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The instance or volume is being torn down. This is an error code. |

## See also

[FILE_GET_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)

[FltQueryQuotaInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueryquotainformationfile)

[ZwSetQuotaInformationFile](https://learn.microsoft.com/previous-versions/ff567105(v=vs.85))