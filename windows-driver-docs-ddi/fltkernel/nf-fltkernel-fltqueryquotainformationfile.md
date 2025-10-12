# FltQueryQuotaInformationFile function

## Description

The **FltQueryQuotaInformationFile** routine retrieves quota entries associated with a file object.

## Parameters

### `Instance` [in]

An opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `FileObject` [in]

A file object pointer for an open file, directory, storage device, or volume. This parameter is required and cannot be **NULL**.

### `IoStatusBlock` [out]

A caller-supplied **IO_STATUS_BLOCK** to receive the result of the call to **FltQueryQuotaInformationFile**. If the call fails because of an invalid **SID** list, the **Information** field will contain the location in *SidList* where the error occurred.

### `Buffer` [out]

A pointer to a caller-supplied [FILE_GET_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)-structured input buffer where the quota information values are to be returned.

### `Length` [in]

The length, in bytes, of the buffer that the *Buffer* parameter points to.

### `ReturnSingleEntry` [in]

Set to **TRUE** if **FltQueryQuotaInformationFile** should return only the first entry that is found.

### `SidList` [in, optional]

A pointer to a caller-supplied [FILE_GET_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)-structured input buffer that specifies the quota information to be queried. This parameter is optional and can be **NULL**.

### `SidListLength` [in]

The length, in bytes, of the buffer that the *SidList* parameter points to.

### `StartSid` [in, optional]

The index of the entry at which to begin scanning the file's quota information list. This parameter is ignored if the *SidList* parameter points to a nonempty list. This parameter is optional and can be **NULL**.

### `RestartScan` [in]

Set to **TRUE** if **FltQueryQuotaInformationFile** should begin the scan at the first entry in the file's quota information list. If this parameter is not set to **TRUE**, the scan is resumed from a previous call to **FltQueryQuotaInformationFile**.

### `LengthReturned` [out, optional]

A pointer to a caller-allocated variable that receives the size, in bytes, of the information returned in *Buffer*. This parameter is optional and can be **NULL**.

## Return value

**FltQueryQuotaInformationFile** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as the following.

| Return code | Description |
| --- | --- |
| **STATUS_FLT_DELETING_OBJECT** | The instance or volume is being torn down. This is an error code. |

## See also

[FILE_GET_QUOTA_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_get_quota_information)

[FltSetQuotaInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetquotainformationfile)

[ZwQueryQuotaInformationFile](https://learn.microsoft.com/previous-versions/ff567064(v=vs.85))