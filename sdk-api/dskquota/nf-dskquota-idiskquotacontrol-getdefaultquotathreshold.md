# IDiskQuotaControl::GetDefaultQuotaThreshold

## Description

Retrieves the default quota warning threshold for the volume. This threshold is applied automatically to new users of the volume.

## Parameters

### `pllThreshold` [out]

The default warning threshold value, in bytes.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pllThreshold* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)