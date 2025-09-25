# IDiskQuotaUser::GetSidLength

## Description

Retrieves the length of the user's security identifier (SID), in bytes. Use the return value to determine the size of the destination buffer you pass to
[IDiskQuotaUser::GetSid](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-getsid).

## Parameters

### `pdwLength` [out]

The SID length, in bytes.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The *pdwLength* parameter is **NULL**. |
| **ERROR_INVALID_SID** | The SID for the user is invalid. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)