# IContext::GetProperty

## Description

Retrieves the specified context property from the context.

## Parameters

### `rGuid` [in]

The GUID that uniquely identifies the context property to be retrieved.

### `pFlags` [out]

The address of the variable that receives the flags associated with the property.

### `ppUnk` [out]

The address of the variable that receives the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer of the requested context property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icontext)