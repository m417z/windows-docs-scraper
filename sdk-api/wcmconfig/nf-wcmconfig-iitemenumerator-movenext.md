# IItemEnumerator::MoveNext

## Description

Moves the current position to the next item in the enumerator if available.

## Parameters

### `ItemValid` [out]

Returns **True** if a valid item is found in the position after the move.

## Return value

This method returns an HRESULT value.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates success. |

## Remarks

**Note** This method always returns **S_OK** on success, regardless of the state of the enumeration. If there are no more items, *ItemValid* is set to **False**, and this is how to determine if the end of the enumeration has been reached.

## See also

[IItemEnumerator](https://learn.microsoft.com/previous-versions/windows/desktop/api/wcmconfig/nn-wcmconfig-iitemenumerator)