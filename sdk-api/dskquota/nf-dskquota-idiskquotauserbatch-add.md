# IDiskQuotaUserBatch::Add

## Description

Adds an
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) pointer to the batch list. This method calls **AddRef** on the *pUser* interface pointer. [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) is automatically called on each contained
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface pointer when the batch object is destroyed.

When setting values on a quota user object in preparation for batch processing, specify **FALSE** for the *fWriteThrough* parameter in the
[IDiskQuotaUser::SetQuotaLimit](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-setquotalimit) and
[IDiskQuotaUser::SetQuotaThreshold](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-setquotathreshold) methods. This stores the values in memory without writing to disk. To write the changes to disk, call the
[IDiskQuotaUserBatch::FlushToDisk](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauserbatch-flushtodisk) method.

## Parameters

### `pUser` [in]

A pointer to the quota user object's
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pUser* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUserBatch](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauserbatch)