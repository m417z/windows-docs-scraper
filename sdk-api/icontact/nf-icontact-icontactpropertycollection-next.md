# IContactPropertyCollection::Next

## Description

Moves to the next property.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Move is successful. |
| **S_FALSE** | Could not move, positioned at the end of the collection. |

## Remarks

**Note** After S_FALSE, further calls to interface's query methods will fail.