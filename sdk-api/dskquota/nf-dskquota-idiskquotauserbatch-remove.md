# IDiskQuotaUserBatch::Remove

## Description

Removes an
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) pointer from the batch list.

## Parameters

### `pUser` [in]

A pointer to the quota user object's
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | Quota user object not found in batch. |
| **E_INVALIDARG** | The *pUser* parameter is **NULL**. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUserBatch](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauserbatch)