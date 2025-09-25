# ISyncKnowledge2::ProjectOntoColumnSet

## Description

Returns the knowledge for the specified set of change units for all the items that are contained in this object.

## Parameters

### `ppColumns` [in]

The set of change unit IDs to look up.

### `count` [in]

The number of change unit IDs that are contained in *ppColumns*.

### `ppiKnowledgeOut` [out]

A knowledge object that contains only the change units that are specified by *ppColumns* for all items contained in this object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *count* is zero. |
| **E_POINTER** | Invalid pointer. |
| **SYNC_E_ID_FORMAT_MISMATCH** | The format of the change unit IDs that is contained in *ppColumns* is not of the format that the format schema of the provider specified. |

## Remarks

**ProjectOntoColumnSet** differs from [ISyncKnowledge::ProjectOntoChangeUnit](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge-projectontochangeunit). **ProjectOntoColumnSet** returns a knowledge object that contains information about the specified set of change units for all the items that are contained in the knowledge object. **ProjectOntoChangeUnit** returns a knowledge object that contains information about a single change unit that is contained in a single item.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)