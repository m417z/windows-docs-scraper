# ISyncKnowledge::SetLocalTickCount

## Description

Sets the tick count for the replica that owns this knowledge.

## Parameters

### `ullTickCount` [in]

The current tick count for the replica that owns this knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_UNEXPECTED** |  |

## Remarks

The tick count must be current before the knowledge is sent to another replica. Typically, a provider calls this method immediately before it sends its knowledge; however, the method can be called at any time.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)