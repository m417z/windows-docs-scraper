# IRpcOptions::Set

## Description

Sets the value of an RPC binding option property.

## Parameters

### `pPrx` [in]

A pointer to the proxy whose property is being set.

### `dwProperty` [in]

An identifier of the property to be set, which must be COMBND_RPCTIMEOUT.

### `dwValue` [in]

The new value of the property.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

See [IRpcOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcoptions) for a table of the possible values of the COMBND_RPCTIMEOUT property.

## See also

[IRpcOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcoptions)