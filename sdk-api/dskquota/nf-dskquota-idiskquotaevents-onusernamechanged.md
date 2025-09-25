# IDiskQuotaEvents::OnUserNameChanged

## Description

Notifies the client's connection sink whenever a user's SID has been asynchronously resolved. If
[IDiskQuotaUser::GetAccountStatus](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-getaccountstatus) returns DISKQUOTA_USER_ACCOUNT_RESOLVED, the user's account container name, logon name, and display name strings are available in the quota user object.

## Parameters

### `pUser` [in]

A pointer to the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface for the quota user object. Do not call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer. The **DiskQuotaControl** object controls the lifetime of the user object.

## Return value

The return value is ignored.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaEvents](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotaevents)