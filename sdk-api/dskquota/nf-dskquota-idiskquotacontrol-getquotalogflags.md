# IDiskQuotaControl::GetQuotaLogFlags

## Description

Retrieves the flags that control the logging of user-related quota events on the volume. Logging makes an entry in the volume server's event log.

## Parameters

### `pdwFlags` [out]

The volume's quota logging flags. Use the following macros to retrieve the contents of the flag value.

| Macro | Description |
| --- | --- |
| DISKQUOTA_IS_LOGGED_USER_LIMIT | If set, an event log entry will be created when the user exceeds his assigned hard quota limit. |
| DISKQUOTA_IS_LOGGED_USER_THRESHOLD | If set, an event log entry will be created when the user exceeds his assigned warning threshold. |

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pdwFlags* parameter is incorrect. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)