# ISyncKnowledge2::GetKnowledgeCookie

## Description

Gets a lightweight, read-only representation of this knowledge object that can be used for fast comparisons.

## Parameters

### `ppKnowledgeCookie` [out]

A lightweight, read-only representation of this knowledge object that can be used for fast comparisons.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

A knowledge cookie can be used for fast comparisons with other knowledge objects by using [ISyncKnowledge2::CompareToKnowledgeCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge2-comparetoknowledgecookie) when the performance of the comparison operation is especially important.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)