# IDiskQuotaControl::AddUserSid

## Description

Adds a new quota entry on the volume for the specified user. The user is identified by security identifier (SID).

## Parameters

### `pUserSid` [in]

The user's SID.

### `fNameResolution` [in]

Indicates how the user account information is to be obtained. The volume's quota information identifies users by SID. The user account information (such as domain name, account name, and full name) must be obtained from the network domain controller, or the local computer if it is not on a network. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DISKQUOTA_USERNAME_RESOLVE_ASYNC**<br><br>2 | Resolve user account information asynchronously. **AddUserSid** returns immediately. The caller must implement the [IDiskQuotaEvents](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotaevents) interface to receive notification when the information is available. If the information was cached during a previous request, notification occurs as soon as the object is serviced. Otherwise, the method obtains the information from the network domain controller, then notifies **IDiskQuotaEvents**. |
| **DISKQUOTA_USERNAME_RESOLVE_NONE**<br><br>0 | Do not resolve user account information. |
| **DISKQUOTA_USERNAME_RESOLVE_SYNC**<br><br>1 | Resolve user account information synchronously. **AddUserSid** returns when the information is resolved. If the information exists in the disk quota SID cache, it is returned immediately. Otherwise, the method must locate the information. This can take several seconds. |

### `ppUser` [out]

A pointer to the
[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser) interface pointer to the newly created quota user object.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_INVALID_SID** | The specified SDI is unknown. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pUserSid* or *ppUser* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## Remarks

The NTFS file system automatically creates a user quota entry when a user first writes to the volume. Entries that are created automatically are assigned the default warning threshold and hard quota limit values for the volume. This method allows you to create a user quota entry before a user has written information to the volume. Therefore, you can pre-assign a warning threshold or hard quota limit value different than the volume default settings.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)