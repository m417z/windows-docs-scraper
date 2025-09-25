# IBitsPeerCacheAdministration::DeleteUrl

## Description

Deletes all cache records and the file from the cache for the given URL.

## Parameters

### `url` [in]

Null-terminated string that contains the URL of the file whose cache records and file you want to delete from the cache.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **S_FALSE** | The URL does not exist. |
| **BG_E_BUSYCACHERECORD** | The cache record is in use and cannot be changed or deleted. Try again after a few seconds. |

## Remarks

The cache records for the file are not removed until all current activity with the cache records is complete.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::DeleteRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-deleterecord)