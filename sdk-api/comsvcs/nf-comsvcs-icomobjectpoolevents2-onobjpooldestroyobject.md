# IComObjectPoolEvents2::OnObjPoolDestroyObject

## Description

Generated when an object is permanently removed from the pool.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `dwObjsCreated` [in]

The number of objects in the pool.

### `oid` [in]

The unique pooled object identifier.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectPoolEvents2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectpoolevents2)