# ISendMethodEvents::SendMethodCall

## Description

Generated when a method is called through a component interface.

## Parameters

### `pIdentity` [in]

A pointer to the interface used to call the method.

### `riid` [in]

The ID of the interface used to call the method.

### `dwMeth` [in]

The method called.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[ISendMethodEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-isendmethodevents)