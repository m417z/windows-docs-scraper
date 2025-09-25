# IBitsPeerCacheAdministration::DiscoverPeers

## Description

Generates a list of peers that can serve content.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

You should not have to call this method.

BITS automatically discovers new peers when a job requests content from a peer and there are not enough peers in the client's peer list. Peers must be in the same Windows domain and subnet as the client and be enabled to serve content to peers.

## See also

[IBitsPeerCacheAdministration](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeercacheadministration)

[IBitsPeerCacheAdministration::ClearPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-clearpeers)

[IBitsPeerCacheAdministration::EnumPeers](https://learn.microsoft.com/windows/desktop/api/bits3_0/nf-bits3_0-ibitspeercacheadministration-enumpeers)