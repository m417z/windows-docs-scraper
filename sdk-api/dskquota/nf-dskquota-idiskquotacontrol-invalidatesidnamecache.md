# IDiskQuotaControl::InvalidateSidNameCache

## Description

Invalidates the contents of the system's SID-to-name cache so subsequent requests for new user objects ([IEnumDiskQuotaUsers::Next](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-ienumdiskquotausers-next),
[IDiskQuotaControl::FindUserSid](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-findusersid), and
[IDiskQuotaControl::FindUserName](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-findusername)) must obtain user names from the domain controller. As names are obtained, they are cached.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |
| **E_FAIL** | The SID-to-name cache is not available or could not be exclusively locked. |

## Remarks

In general, there is no reason to call this method. It is included to provide a method for programmatically refreshing the entire SID-to-name cache.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)