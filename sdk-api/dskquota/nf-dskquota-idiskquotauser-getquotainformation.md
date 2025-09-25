# IDiskQuotaUser::GetQuotaInformation

## Description

Retrieves the values for the user's warning threshold, hard quota limit, and quota used.

## Parameters

### `pbQuotaInfo` [out]

A pointer to the
[DISKQUOTA_USER_INFORMATION](https://learn.microsoft.com/windows/win32/api/dskquota/ns-dskquota-diskquota_user_information) structure to receive the quota information.

### `cbQuotaInfo` [in]

The size of the quota information structure, in bytes.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |
| **E_INVALIDARG** | The *pQuotaInfo* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)