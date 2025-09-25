# IDiskQuotaControl::DeleteUser

## Description

Removes a user entry from the volume quota information file, if the user's charged quota amount is zero (0) bytes.

## Parameters

### `pUser` [in]

A pointer to the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface of the user whose quota record is marked for deletion.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_FILE_EXISTS** | The user owns files on the volume. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pUser* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## Remarks

This method does not actually remove the quota entry from the volume. It marks the entry for deletion. The NTFS file system performs the actual deletion at a later time. Following a call to **IDiskQuotaControl::DeleteUser**, the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface is still active. This method does not delete the user object from memory. To release the user object, call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)