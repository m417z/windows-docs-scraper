# IDiskQuotaUser::GetName

## Description

Retrieves the name strings associated with a disk quota user.

## Parameters

### `pszAccountContainer` [out]

The name of the user's account container. This value can be **NULL**. For accounts without directory service information, this string is simply the domain name. For accounts with directory service information available, this string is a canonical name with the terminating object name removed.

### `cchAccountContainer` [in]

The size of the account container buffer, in characters. Ignored if *pszAccountContainer* is **NULL**.

### `pszLogonName` [out]

A pointer to the buffer to receive the name the user specified to log on the computer. This value can be **NULL**. The format of the name returned depends on whether directory service information is available.

### `cchLogonName` [in]

The size of the logon name buffer, in characters. Ignored if *pszLogonName* is **NULL**.

### `pszDisplayName` [out]

A pointer to the buffer to receive the display name for the quota user. This value can be **NULL**. If the information is not available, the string returned is of zero length.

### `cchDisplayName` [in]

The size of the display-name buffer, in characters. Ignored if *pszDisplayName* is **NULL**.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)