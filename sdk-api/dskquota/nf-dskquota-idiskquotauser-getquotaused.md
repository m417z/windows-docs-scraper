# IDiskQuotaUser::GetQuotaUsed

## Description

Retrieves the user's quota used value on the volume. This is the amount of information stored on the volume by the user. This is the amount of uncompressed information. Therefore, the use of NTFS file system compression does not affect this value.

## Parameters

### `pllUsed` [out]

The quota used value.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |
| **E_INVALIDARG** | The *pllUsed* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)