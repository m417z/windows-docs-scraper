# IDiskQuotaControl::SetQuotaLogFlags

## Description

Controls the logging of user-related quota events on the volume. Logging makes an entry in the volume server system's event log.

## Parameters

### `dwFlags` [in]

The log flags to be applied to the volume. Use the following macros to set the proper bits in the *dwFlags* parameter.

| Macro | Description |
| --- | --- |
| DISKQUOTA_SET_LOG_USER_LIMIT | Turn on/off logging of user quota limit violations. If set, an event log entry will be created when the user exceeds his assigned hard quota limit. |
| DISKQUOTA_SET_LOG_USER_THRESHOLD | Turn on/off logging of user warning threshold violations. If set, an event log entry will be created when the user exceeds his assigned warning threshold. |

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)