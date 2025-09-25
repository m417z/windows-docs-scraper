# ISyncKnowledge2::CompareToKnowledgeCookie

## Description

Performs a fast comparison between the specified knowledge cookie and this knowledge object.

## Parameters

### `pKnowledgeCookie` [in]

The knowledge cookie to compare against this object.

### `pResult` [out]

The result of the comparison.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

This method can be used when the performance of the knowledge comparison operation is especially important.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[KNOWLEDGE_COOKIE_COMPARISON_RESULT Enumeration](https://learn.microsoft.com/windows/win32/api/winsync/ne-winsync-knowledge_cookie_comparison_result)