# IDiskQuotaControl::FindUserName

## Description

Locates a specific entry in the volume quota information. The user's account logon name is used as the search key.

## Parameters

### `pszLogonName` [in]

A pointer to the user's account logon name.

### `ppUser` [out]

A pointer to the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface pointer to the quota user object.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_INVALID_SID** | The SID for the user is invalid. |
| **ERROR_NONE_MAPPED** | There is no mapping available for the SID. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pUserSid* or *ppUser* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## Remarks

This method will return a user object even if there is no quota record for the user in the quota file. This is consistent with the idea of automatic user addition and default quota settings. If there is currently no quota entry for the requested user, and the user would be added to the quota file if he were to request disk space, the returned user object will have warning threshold and hard quota limits equal to the volume default settings.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)