# IEnumEventObject::Skip

## Description

Skips over the specified number of items in the enumeration sequence.

## Parameters

### `cSkipElem` [in]

The number of elements to be skipped.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The requested number of elements was skipped. |
| **S_FALSE** | The number of elements skipped was not the same as the number requested. |

## Remarks

**Skip** may return S_FALSE if *cSkipElem* is greater than the remaining number of elements. In this case, **Skip** moves to the last element in the enumeration sequence.

## See also

[IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject)