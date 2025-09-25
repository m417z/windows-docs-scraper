# IComObjectPoolEvents2::OnObjPoolTimeout

## Description

Generated when the request for a pooled object times out.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `guidActivity` [in]

The identifier of the activity in which the object is created.

### `dwTimeout` [in]

The pool's time-out value.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPoolEvents2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents2)