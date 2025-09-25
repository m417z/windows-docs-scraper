# IComObjectConstructionEvents::OnObjectConstruct

## Description

Generated when a constructed object is created.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidObject` [in]

The CLSID for the objects in the pool.

### `sConstructString` [in]

The object construction string.

### `oid` [in]

The unique constructed object identifier.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectConstructionEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectconstructionevents)