# GetFriendlyIfIndex function

## Description

The
**GetFriendlyIfIndex** function takes an interface index and returns a backward-compatible interface index, that is, an index that uses only the lower 24 bits.

## Parameters

### `IfIndex` [in]

The interface index from which the backward-compatible or "friendly" interface index is derived.

## Return value

A backward-compatible interface index that uses only the lower 24 bits.

## See also

[GetIfEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getifentry)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)