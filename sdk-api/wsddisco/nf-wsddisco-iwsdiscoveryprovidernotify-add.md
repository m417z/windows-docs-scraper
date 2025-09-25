# IWSDiscoveryProviderNotify::Add

## Description

Provides information on either a newly announced discovery host (from a Hello message), or a match to a user initiated query.

## Parameters

### `pService` [in]

A pointer to an [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) interface that represents a remote discovery host.

## Return value

The return value is not meaningful. An implementer should return S_OK.

## Remarks

**Add** will be called once for each successful match to an outstanding query, and once per announcement of a new discovery host.

**Note** Multiple simultaneous calls may be made to **Add** by the provider, so it is essential that shared data be synchronized when implementing this callback routine.

## See also

[IWSDiscoveryProviderNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovidernotify)