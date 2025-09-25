# ISyncKnowledge2::GetIdParameters

## Description

Gets the ID format schema of the provider.

## Parameters

### `pIdParameters` [out]

The ID format schema of the provider.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwSize* member of *pIdParameters* is not equal to `sizeof(ID_PARAMETERS)`. |
| **E_POINTER** | Invalid pointer. |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)