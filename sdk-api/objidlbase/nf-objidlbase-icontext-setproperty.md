# IContext::SetProperty

## Description

Adds the specified context property to the object context.

## Parameters

### `rpolicyId` [in]

A GUID that uniquely identifies this context property.

### `flags` [in]

This parameter is reserved and must be zero.

### `pUnk` [in]

A pointer to the context property to be added.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IContext](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icontext)