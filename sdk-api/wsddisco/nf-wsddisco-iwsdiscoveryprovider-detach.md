# IWSDiscoveryProvider::Detach

## Description

Detaches a callback interface from the discovery provider.

## Return value

Possible return values include, but are not limited to, the following:

| Return code | Description |
| --- | --- |
| **S_OK** | Method completed successfully. |
| **E_ABORT** | A callback interface has not been attached. You must call [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) before calling this method. |

## Remarks

If a callback interface has been attached to a discovery provider via the [Attach](https://learn.microsoft.com/windows/desktop/api/wsddisco/nf-wsddisco-iwsdiscoveryprovider-attach) method, then **Detach** must be called before releasing the reference to the provider interface object.

The **Detach** operation blocks until all callbacks into the associated [IWSDiscoveryProviderNotify](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovidernotify) object have completed.

## See also

[IWSDiscoveryProvider](https://learn.microsoft.com/windows/desktop/api/wsddisco/nn-wsddisco-iwsdiscoveryprovider)