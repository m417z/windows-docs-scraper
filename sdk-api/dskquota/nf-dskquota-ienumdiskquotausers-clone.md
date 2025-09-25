# IEnumDiskQuotaUsers::Clone

## Description

Creates another enumerator of user quota entries that contains the same enumeration state as the current one. Using this method, a client can record a particular point in the enumeration sequence, and then return to that point at a later time. The new enumerator supports the same interface as the original one.

## Parameters

### `ppEnum` [out]

A pointer to the
[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers) interface pointer. If the method is unsuccessful, the value of this variable is undefined.

## Return value

This method returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *ppEnum* parameter is **NULL**. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_UNEXPECTED** | An unexpected exception occurred. |

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers)