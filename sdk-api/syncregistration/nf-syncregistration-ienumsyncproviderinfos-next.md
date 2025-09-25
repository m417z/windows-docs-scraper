# IEnumSyncProviderInfos::Next

## Description

Returns the next **ISyncProviderInfo** object.

## Parameters

### `cInstances` [in]

The number of **ISyncProviderInfo** objects to retrieve in the range of zero to 1.

### `ppSyncProviderInfo` [out]

Returns the next *pcFetched***ISyncProviderInfo** objects.

### `pcFetched` [out]

Returns the number of **ISyncProviderInfo** objects that are retrieved.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The requested number of objects was not available. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the next **ISyncProviderInfo** object. |

## Remarks

This method will attempt to return the number of items specified by the *cInstances* parameter. If the specified number of items is not available, **S_FALSE** will be returned, and *pcFetched* will contain the number of items that were able to be retrieved.

## See also

[IEnumSyncProviderInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderinfos)