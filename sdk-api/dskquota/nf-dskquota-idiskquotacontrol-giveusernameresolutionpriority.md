# IDiskQuotaControl::GiveUserNameResolutionPriority

## Description

Promotes the specified user object to the head of the queue so that it is next in line for resolution. By default, quota user objects are serviced in the order in which they were placed in the queue.

This method is applicable only when asynchronous name resolution is used.

## Parameters

### `pUser` [in]

A pointer to the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **S_FALSE** | Quota user object not in the resolver queue. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)