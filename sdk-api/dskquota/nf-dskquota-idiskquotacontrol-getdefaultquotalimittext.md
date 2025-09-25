# IDiskQuotaControl::GetDefaultQuotaLimitText

## Description

Retrieves the default quota limit for the volume. The limit is expressed as a text string; for example, 10.5 MB. This limit is applied automatically to new users of the volume.

## Parameters

### `pszText` [out]

The text string. If the volume has no limit, the string returned is "No Limit" (localized). If the buffer is too small, the string is truncated to fit the buffer.

### `cchText` [in]

The size of the buffer, in characters.

## Return value

This method returns a file system error or one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_NOT_READY** | The **DiskQuotaControl** object is not initialized. |
| **E_INVALIDARG** | The *pszText* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaControl](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotacontrol)