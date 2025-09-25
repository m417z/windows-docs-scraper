# IDiskQuotaControl::FindUserSid

## Description

Locates a specific user entry in the volume quota information. The user's security identifier (SID) is used as the search key.

## Parameters

### `pUserSid` [in]

A pointer to the user's SID.

### `fNameResolution` [in]

Indicates how the user account information is to be obtained. The volume's quota information identifies users by SID. The user account information (such as domain name, account name, and full name) must be obtained from the network domain controller, or the local computer if it is not on a network. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DISKQUOTA_USERNAME_RESOLVE_ASYNC**<br><br>2 | Resolve user account information asynchronously. **FindUserSid** returns immediately. The caller must implement the [IDiskQuotaEvents](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotaevents) interface to receive notification when the information is available. If the information was cached during a previous request, notification occurs as soon as the object is serviced. Otherwise, the method obtains the information from the network domain controller, then notifies **IDiskQuotaEvents**. |
| **DISKQUOTA_USERNAME_RESOLVE_NONE**<br><br>0 | Do not resolve user account information. |
| **DISKQUOTA_USERNAME_RESOLVE_SYNC**<br><br>1 | Resolve user account information synchronously. **FindUserSid** returns when the information has been resolved. If the information exists in the disk quota SID cache, it is returned immediately. Otherwise, the method must locate the information. This can take several seconds. |

### `ppUser` [out]

Pointer to receive the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface pointer to the quota user object.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **ERROR_INVALID_SID** | The SID for the user is invalid. |
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