# IManagedActivationEvents::CreateManagedStub

## Description

Creates a stub for a managed object within the current COM+ context.

## Parameters

### `pInfo` [in]

A pointer to [IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo) that describes the stub for a managed object.

### `fDist` [in]

Indicates whether the created stub is the distinguished stub. A distinguished stub is the stub that controls the lifetime of the current COM+ context.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IManagedActivationEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedactivationevents)