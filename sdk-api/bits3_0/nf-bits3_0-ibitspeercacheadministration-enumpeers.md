# IBitsPeerCacheAdministration::EnumPeers

## Description

Gets an [IEnumBitsPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeers) interface pointer that you use to enumerate the peers that can serve content. The enumeration is a snapshot of the records in the cache.

## Parameters

### `ppEnum` [out]

An [IEnumBitsPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ienumbitspeers) interface pointer that you use to enumerate the peers that can serve content. Release *ppEnum* when done.

## Return value

This method returns S_OK on success or one of the standard COM **HRESULT** values on error.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::ClearPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-clearpeers)

[IBitsPeerCacheAdministration::DiscoverPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-discoverpeers)