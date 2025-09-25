# ISyncKnowledge::Clone

## Description

Creates a new instance of this object, and copies the data from this object to the new object.

## Parameters

### `ppClonedKnowledge` [out]

Returns the newly created knowledge object.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_OUTOFMEMORY** |  |

## Remarks

The cloned knowledge object can be used independently of the original.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)