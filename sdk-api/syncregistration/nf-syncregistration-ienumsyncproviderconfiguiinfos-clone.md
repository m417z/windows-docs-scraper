# IEnumSyncProviderConfigUIInfos::Clone

## Description

Clones the enumerator and returns a new enumerator that is in the same state as the current one.

## Parameters

### `ppEnum` [out]

Returns the newly cloned enumerator.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to clone the enumerator. |

## See also

[IEnumSyncProviderConfigUIInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderconfiguiinfos)