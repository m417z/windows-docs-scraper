# IComResourceEvents::OnResourceCreate

## Description

Generated when a new resource is created and allocated.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ObjectID` [in]

The just-in-time activated object.

### `pszType` [in]

A description of the resource.

### `resId` [in]

The unique identifier of the resource.

### `enlisted` [in]

Indicates whether the resource is enlisted in a transaction.

## Return value

The user verifies the return values from this method.

## See also

[IComResourceEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomresourceevents)