# IManagedObjectInfo::SetWrapperStrength

## Description

Sets whether the managed object holds a strong or a weak reference to the COM+ context.

## Parameters

### `bStrong` [in]

Indicates whether the managed object holds a strong or a weak reference to the COM+ context. A strong reference keeps the object alive and prevents it from being destroyed during garbage collection.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IManagedObjectInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imanagedobjectinfo)