# IBitsPeerCacheAdministration::EnumRecords

## Description

Gets an [IEnumBitsPeerCacheRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeercacherecords) interface pointer that you use to enumerate the records in the cache. The enumeration is a snapshot of the records in the cache.

## Parameters

### `ppEnum` [out]

An [IEnumBitsPeerCacheRecords](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeercacherecords) interface pointer that you use to enumerate the records in the cache. Release *ppEnum* when done.

## Return value

This method returns S_OK on success or one of the standard COM **HRESULT** values on error.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::ClearPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-clearpeers)

[IBitsPeerCacheAdministration::GetRecord](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-getrecord)