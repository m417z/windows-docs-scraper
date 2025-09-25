# IEnumFeedClockVector::Skip

## Description

Skips the specified number of clock vector elements.

## Parameters

### `cSyncVersions` [in]

The number of elements to skip.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The enumerator reaches the end of its list before it can skip *cSyncVersions* elements. In this case, the enumerator skips as many elements as possible. |
| **E_INVALIDARG** |  |

## See also

[IEnumFeedClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumfeedclockvector)