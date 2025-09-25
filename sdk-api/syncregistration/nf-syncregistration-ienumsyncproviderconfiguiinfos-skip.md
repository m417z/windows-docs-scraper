# IEnumSyncProviderConfigUIInfos::Skip

## Description

Skips the specified number of **ISyncProviderConfigUIInfo** objects.

## Parameters

### `cFactories` [in]

The number of **ISyncProviderConfigUIInfo** objects to skip.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The end of the collection was reached before the specified number of items was skipped. |

## Remarks

If the end of the collection is reached before the number of items to skip is reached, **S_FALSE** will be returned, and the enumerator will be placed at the end of the collection and subsequent calls to **Skip** or [Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-ienumsyncproviderconfiguiinfos-next) with a count of 1 will return **S_FALSE**.

## See also

[IEnumSyncProviderConfigUIInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderconfiguiinfos)