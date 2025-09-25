# IEnumEventObject::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `cReqElem` [in]

The number of elements being requested. If there are fewer than the requested number of elements left in the sequence, this method obtains the remaining elements.

### `ppInterface` [out]

The address to a pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the first object obtained. This parameter cannot be **NULL**.

### `cRetElem` [out]

The number of elements actually obtained. This parameter cannot be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_POINTER, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | All elements requested were obtained. |
| **S_FALSE** | Not all elements requested were obtained. The number of elements obtained was written to *pcRetElem*. |

## See also

[IEnumEventObject](https://learn.microsoft.com/windows/desktop/api/eventsys/nn-eventsys-ienumeventobject)