# IManagedObjectInfo::SetInPool

## Description

Sets whether the managed object belongs to the COM+ object pool.

## Parameters

### `bInPool` [in]

Indicates whether the managed object belongs to the COM+ object pool.

### `pPooledObj` [in]

A reference to [IManagedPooledObj](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedpooledobj) that describes how this managed object is used in the COM+ object pool.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo)