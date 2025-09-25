# IDiskQuotaControl::SetQuotaState

## Description

Sets the state of the quota system.

## Parameters

### `dwState` [in]

State to be applied to the volume. Use the following macros to set the proper bits.

| Macro | Enable | Track | Enforce |
| --- | --- | --- | --- |
| DISKQUOTA_SET_DISABLED | No | No | No |
| DISKQUOTA_SET_TRACKED | Yes | Yes | No |
| DISKQUOTA_SET_ENFORCED | Yes | Yes | Yes |

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *dwState* parameter is incorrect. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## Remarks

Not all state attributes can be modified. The enable, track, and enforce attributes can be modified.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)