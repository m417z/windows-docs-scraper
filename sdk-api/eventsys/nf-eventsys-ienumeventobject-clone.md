# IEnumEventObject::Clone

## Description

Creates an enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppInterface` [out]

Address of a pointer to the [IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject) interface on the enumeration object. This parameter cannot be **NULL**. If the method is unsuccessful, the value of this output variable is undefined.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

When the pointer to the [IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject) is returned, it is positioned at the first object in the collection not at the place of the enumeration object being cloned.

## See also

[IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject)