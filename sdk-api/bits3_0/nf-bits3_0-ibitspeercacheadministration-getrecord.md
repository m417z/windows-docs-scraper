# IBitsPeerCacheAdministration::GetRecord

## Description

Gets a record from the cache.

## Parameters

### `id` [in]

Identifier of the record to get from the cache. The [IBitsPeerCacheRecord::GetId](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacherecord-getid) method returns the identifier.

### `ppRecord` [out]

An [IBitsPeerCacheRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacherecord) interface of the cache record. Release *ppRecord* when done.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::DeleteRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-deleterecord)

[IBitsPeerCacheAdministration::EnumRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-enumrecords)