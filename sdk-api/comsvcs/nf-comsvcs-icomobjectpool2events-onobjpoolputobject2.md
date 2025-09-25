# IComObjectPool2Events::OnObjPoolPutObject2

## Description

Generated when an object is added to the pool.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `nReason` [in]

This parameter is reserved.

### `dwAvailable` [in]

The number of objects in the pool.

### `oid` [in]

The unique identifier for this object.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPool2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpool2events)