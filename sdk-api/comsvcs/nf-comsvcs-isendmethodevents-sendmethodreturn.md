# ISendMethodEvents::SendMethodReturn

## Description

Generated when a method called through a component interface returns control to the caller.

## Parameters

### `pIdentity` [in]

A pointer to the interface used to call the method.

### `riid` [in]

The ID of the interface used to call the method.

### `dwMeth` [in]

The method called.

### `hrCall` [in]

The result returned by the method call.

### `hrServer` [in]

The result returned by the DCOM call to the server on which the component lives.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ISendMethodEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isendmethodevents)