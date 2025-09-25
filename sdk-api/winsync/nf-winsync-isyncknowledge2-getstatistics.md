# ISyncKnowledge2::GetStatistics

## Description

Gets the specified statistic data that is contained in this object.

## Parameters

### `which` [in]

Specifies which statistic to retrieve.

### `pValue` [out]

The specified statistic data.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *which* is not a member of the **SYNC_STATISTICS** enumeration. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[SYNC_STATISTICS Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-sync_statistics)