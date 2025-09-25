# IDiskQuotaControl::GetQuotaState

## Description

Retrieves a set of flags describing the state of the quota system.

## Parameters

### `pdwState` [out]

The quota state flags. This parameter can include one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **DISKQUOTA_FILESTATE_INCOMPLETE**<br><br>0x00000100 | The volume's quota information is out of date. Quotas are probably disabled. |
| **DISKQUOTA_FILESTATE_REBUILDING**<br><br>0x00000200 | The volume is rebuilding its quota information. |
| **DISKQUOTA_STATE_DISABLED**<br><br>0x00000000 | Quotas are not enabled on the volume. |
| **DISKQUOTA_STATE_ENFORCE**<br><br>0x00000002 | Quotas are enabled and the limit value is enforced. Users cannot exceed their quota limit. |
| **DISKQUOTA_STATE_TRACK**<br><br>0x00000001 | Quotas are enabled but the limit value is not being enforced. Users may exceed their quota limit. |

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pdwState* parameter is incorrect. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)