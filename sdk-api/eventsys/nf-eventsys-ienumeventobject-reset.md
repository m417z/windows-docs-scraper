# IEnumEventObject::Reset

## Description

Resets the enumeration sequence to the beginning.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The enumeration sequence was reset. |
| **S_FALSE** | The enumeration sequence was reset, but there are no items in the enumerator. |

## Remarks

You can use the S_FALSE return value as an optimization to detect an empty enumeration.

A call to this method, resetting the sequence, does not guarantee that the same set of objects will be enumerated after the reset, because the collection may have changed.

## See also

[IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject)