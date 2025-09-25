# IComResourceEvents::OnResourceRecycle

## Description

Generated when an object is finished with a resource.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `ObjectID` [in]

The just-in-time activated object.

### `pszType` [in]

A description of the resource.

### `resId` [in]

The unique identifier of the resource.

## Return value

The user verifies the return values from this method.

## See also

[IComResourceEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomresourceevents)