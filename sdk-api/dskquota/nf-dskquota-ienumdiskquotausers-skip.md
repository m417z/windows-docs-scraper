# IEnumDiskQuotaUsers::Skip

## Description

Skips over the specified number of user quota entries that are next in the enumeration
sequence.

## Parameters

### `cUsers` [in]

The number of elements to be skipped.

## Return value

The return value is **S_OK** if the number of elements skipped is
*cUsers*; otherwise, the return value is **S_FALSE**.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers)