# IComObjectPoolEvents2::OnObjPoolCreatePool

## Description

Generated when a new pool is created.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `dwMin` [in]

The pool's minimum object value.

### `dwMax` [in]

The pool's maximum object value.

### `dwTimeout` [in]

The pool's time-out value.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPoolEvents2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents2)