# IDiskQuotaUser::GetQuotaThresholdText

## Description

Retrieves the user's warning threshold for the volume. This threshold is expressed as a text string, for example "10.5 MB". If the user's threshold is unlimited, the string returned is "No Limit" (localized). If the destination buffer is too small, the string is truncated to fit the buffer.

## Parameters

### `pszText` [out]

The text string.

### `cchText` [in]

The size of the destination buffer, in characters.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **ERROR_ACCESS_DENIED** | The caller has insufficient access rights. |
| **ERROR_LOCK_FAILED** | Failure to obtain an exclusive lock. |
| **E_INVALIDARG** | The *pszText* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_FAIL** | An unexpected file system error occurred. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IDiskQuotaUser](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-idiskquotauser)