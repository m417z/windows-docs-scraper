# IDiskQuotaUser::GetSid

## Description

Retrieves the user's security identifier (SID).

## Parameters

### `pbSidBuffer` [out]

The SID.

### `cbSidBuffer` [in]

The size of the buffer, in bytes. Use the
[IDiskQuotaUser::GetSidLength](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-getsidlength) method to obtain the required size for the buffer.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pbSidBuffer* parameter is **NULL**. |
| **ERROR_INVALID_SID** | The SID for the user is invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | Insufficient destination buffer size. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)