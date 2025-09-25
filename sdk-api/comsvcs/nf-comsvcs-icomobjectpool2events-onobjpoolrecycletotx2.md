# IComObjectPool2Events::OnObjPoolRecycleToTx2

## Description

Generated when a transactional object is returned to the pool.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidActivity` [in]

The activity ID for which the object is created.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `guidTx` [in]

The transaction identifier.

### `objid` [in]

The unique identifier for this object.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPool2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpool2events)