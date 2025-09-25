# IDiskQuotaControl::CreateUserBatch

## Description

Creates a batching object for optimizing updates to the quota settings of multiple users simultaneously.

## Parameters

### `ppBatch` [out]

A pointer to the
[IDiskQuotaUserBatch](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauserbatch) interface pointer.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *ppBatch* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)