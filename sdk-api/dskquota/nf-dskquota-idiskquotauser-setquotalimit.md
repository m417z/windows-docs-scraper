# IDiskQuotaUser::SetQuotaLimit

## Description

Sets the user's quota limit value on the volume. The limit is set as the maximum amount of disk space available to the volume user.

## Parameters

### `llLimit` [in]

The quota limit, in bytes. If this value is -1, the user has an unlimited quota.

### `fWriteThrough` [in]

If this value is **TRUE**, the value is written immediately to the volume's quota file. Otherwise, the value is written only to the quota user object's local memory. This value should typically be set to **TRUE**. Set it to **FALSE** when using the
[IDiskQuotaUserBatch](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauserbatch) interface to modify multiple user quota entries at once.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |
| **E_FAIL** | An unexpected file system error occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)