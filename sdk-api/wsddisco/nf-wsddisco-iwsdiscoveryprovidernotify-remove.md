# IWSDiscoveryProviderNotify::Remove

## Description

Provides information on a recently departed discovery host (from a Bye message).

## Parameters

### `pService` [in]

A pointer to an [IWSDiscoveredService](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveredservice) interface that represents a remote discovery host.

## Return value

The return value is not meaningful. An implementer should return S_OK.

## Remarks

**Remove** will be called once per announcement of a departing discovery host.

**Note** Multiple simultaneous calls may be made to **Remove** by the provider, so it is essential that shared data be synchronized when implementing this callback routine.

## See also

[IWSDiscoveryProviderNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovidernotify)