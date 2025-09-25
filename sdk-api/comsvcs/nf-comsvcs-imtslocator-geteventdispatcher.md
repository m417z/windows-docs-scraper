# IMTSLocator::GetEventDispatcher

## Description

Retrieves a pointer to the event dispatcher for the current process.

## Parameters

### `pUnk` [out]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the event dispatcher for the current process.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## See also

[IMTSLocator](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtslocator)