# IEnumDiskQuotaUsers::Next

## Description

Retrieves the specified number of user quota entries that are next in the enumeration sequence. If there are fewer than the requested number of elements left in the sequence, it retrieves the remaining elements.

## Parameters

### `cUsers` [in]

The number of elements being requested.

### `rgUsers` [out]

An array of size *cUsers* or larger.

### `pcUsersFetched` [in, out]

On input, the number of elements in *rgUsers*, on input. On output, the number of elements actually retrieved. The caller can pass in **NULL** if *cUsers* is one and the number of elements retrieved is of no interest.

## Return value

The return value is **S_OK** if the number of elements supplied is *cUsers*; otherwise, the return value is **S_FALSE**.

## See also

[Disk Management Interfaces](https://learn.microsoft.com/windows/desktop/FileIO/disk-management-interfaces)

[Disk Quotas](https://learn.microsoft.com/windows/desktop/FileIO/managing-disk-quotas)

[IEnumDiskQuotaUsers](https://learn.microsoft.com/windows/desktop/api/dskquota/nn-dskquota-ienumdiskquotausers)