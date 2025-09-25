# IManagedActivationEvents::DestroyManagedStub

## Description

Destroys a stub that was created by [CreateManagedStub](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-imanagedactivationevents-createmanagedstub).

## Parameters

### `pInfo` [in]

A pointer to [IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo) that describes the stub for a managed object.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IManagedActivationEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedactivationevents)