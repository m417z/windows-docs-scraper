# IDiskQuotaControl::CreateEnumUsers

## Description

Creates an enumerator object for enumerating quota users on the volume. The newly created object implements the
[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers) interface.

## Parameters

### `rgpUserSids` [in]

An array of security identifier (SID) pointers representing the user objects to be included in the enumeration. If this value is **NULL**, all user entries are enumerated.

### `cpSids` [in]

The number of items in the *rgpUserSids* array. Ignored if *rgpUserSids* is **NULL**.

### `fNameResolution` [in]

Indicates how the user account information is to be obtained. The volume's quota information identifies users by SID. The user account information (such as domain name, account name, and full name) must be obtained from the network domain controller, or the local computer if it is not on a network. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DISKQUOTA_USERNAME_RESOLVE_ASYNC**<br><br>2 | Resolve user account information asynchronously. The [IEnumDiskQuotaUsers::Next](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-ienumdiskquotausers-next) method returns immediately. The caller must implement the [IDiskQuotaEvents](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotaevents) interface to receive notification when the information is available. If the information was cached during a previous request, notification occurs as soon as the object is serviced. Otherwise, the method obtains the information from the network domain controller, then notifies **IDiskQuotaEvents**. |
| **DISKQUOTA_USERNAME_RESOLVE_NONE**<br><br>0 | Do not resolve user account information. |
| **DISKQUOTA_USERNAME_RESOLVE_SYNC**<br><br>1 | Resolve user account information synchronously. The [IEnumDiskQuotaUsers::Next](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-ienumdiskquotausers-next) method returns when the information is resolved. If the information exists in the disk quota SID cache, it is returned immediately. Otherwise, the method must locate the information. This can take several seconds. |

### `ppEnum` [out]

A pointer to a pointer to the
[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers) enumerator.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The DiskQuotaControl object is not initialized. |
| **E_INVALIDARG** | The *ppEnum* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)