# IBitsPeerCacheAdministration::DeleteRecord

## Description

Deletes a record and file from the cache. This method uses the record's identifier to identify the record to delete.

## Parameters

### `id` [in]

Identifier of the record to delete from the cache. The [IBitsPeerCacheRecord::GetId](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacherecord-getid) method returns the identifier.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |
| **BG_E_BUSYCACHERECORD** | The cache record is in use and cannot be changed or deleted. Try again after a few seconds. |

## Remarks

The cache record is not removed until all current activity with the cache record is complete.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::DeleteUrl](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-deleteurl)

[IBitsPeerCacheAdministration::GetRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getrecord)