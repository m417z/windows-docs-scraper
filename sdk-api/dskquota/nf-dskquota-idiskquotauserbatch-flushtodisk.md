# IDiskQuotaUserBatch::FlushToDisk

## Description

Writes user object changes to disk in a single call to the underlying file system.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## Remarks

There are limitations on the amount of information that can be written to disk in a single call to the file system. The flush operation may generate multiple calls to the file system. Nonetheless, the batch operation will be more efficient than a single call for each user object.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUserBatch](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauserbatch)