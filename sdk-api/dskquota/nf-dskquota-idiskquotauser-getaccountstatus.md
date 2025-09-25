# IDiskQuotaUser::GetAccountStatus

## Description

Retrieves the status of the user object's account. User information is identified in the quota system by user security identifier (SID). This SID must resolve to a user account for the user's account name information to be retrieved.

## Parameters

### `pdwStatus` [out]

The user's account status. The status value can be one of the following.

| Value | Meaning |
| --- | --- |
| **DISKQUOTA_USER_ACCOUNT_RESOLVED**<br><br>0 | The SID was resolved to a user account. Names are available through [IDiskQuotaUser::GetName](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-getname). |
| **DISKQUOTA_USER_ACCOUNT_UNAVAILABLE**<br><br>1 | The user account is unavailable at this time. The network domain controller may not be available. Name information is not available. |
| **DISKQUOTA_USER_ACCOUNT_DELETED**<br><br>2 | The user account was deleted from the domain. Name information is not available. |
| **DISKQUOTA_USER_ACCOUNT_INVALID**<br><br>3 | The user account is invalid. Name information is not available. |
| **DISKQUOTA_USER_ACCOUNT_UNKNOWN**<br><br>4 | The user account is unknown. Name information is not available. |
| **DISKQUOTA_USER_ACCOUNT_UNRESOLVED**<br><br>5 | The SID has not been resolved to a user account. |

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pdwStatus* parameter is **NULL**. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/win32/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/win32/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/win32/api/dskquota/nn-dskquota-idiskquotauser)