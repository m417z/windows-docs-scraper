# IEnumSyncProviderConfigUIInfos::Next

## Description

Returns the next **ISyncProviderConfigUIInfo** object.

## Parameters

### `cFactories` [in]

The number of **ISyncProviderConfigUIInfo** objects to retrieve in the range of zero to 1.

### `ppSyncProviderConfigUIInfo` [out]

Returns the next *pcFetched***ISyncProviderConfigUIInfo** objects.

### `pcFetched` [out]

Returns the number of **ISyncProviderConfigUIInfo** objects that are retrieved.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The requested number of objects was not available. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the next **ISyncProviderConfigUIInfo** object. |

## Remarks

This method will attempt to return the number of items specified by the *cFactories* parameter. If the specified number of items is not available, **S_FALSE** will be returned, and *pcFetched* will contain the number of items that were able to be retrieved.

## See also

[IEnumSyncProviderConfigUIInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderconfiguiinfos)