# IContactCollection::Next

## Description

Moves to the next contact.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Move is successful. |
| **S_FALSE** | Could not move, positioned at the end of the collection. |

## Remarks

After S_FALSE is returned, calls to GetCurrent will fail.