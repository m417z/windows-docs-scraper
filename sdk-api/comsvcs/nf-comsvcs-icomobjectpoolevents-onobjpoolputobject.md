# IComObjectPoolEvents::OnObjPoolPutObject

## Description

Generated when a new object is added to the pool.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `nReason` [in]

This parameter is always 0.

### `dwAvailable` [in]

The number of objects in the pool.

### `oid` [in]

The unique identifier for this object.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPoolEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents)