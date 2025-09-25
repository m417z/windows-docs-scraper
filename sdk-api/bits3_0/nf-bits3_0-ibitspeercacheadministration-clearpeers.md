# IBitsPeerCacheAdministration::ClearPeers

## Description

Removes all peers from the list of peers that can serve content.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

You should not have to call this method.

BITS automatically discovers new peers when a job requests content from a peer. You can also call the [IBitsPeerCacheAdministration::DiscoverPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-discoverpeers) method to force discovery of peers.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::DiscoverPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-discoverpeers)

[IBitsPeerCacheAdministration::EnumPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-enumpeers)