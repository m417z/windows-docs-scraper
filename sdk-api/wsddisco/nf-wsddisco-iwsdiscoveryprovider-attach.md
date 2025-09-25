# IWSDiscoveryProvider::Attach

## Description

Attaches a callback interface to the discovery provider.

## Parameters

### `pSink` [in]

Interface to receive callback notifications. Search results as well as the Hello and Bye messages are communicated to this interface via the callbacks.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_POINTER** | *pSink* is **NULL**. |
| **E_ABORT** | A callback interface has already been attached to the provider. |

## Remarks

**Note** Attach must be called before any other [IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider) method is used, except for [SetAddressFamily](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-setaddressfamily).

## See also

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)