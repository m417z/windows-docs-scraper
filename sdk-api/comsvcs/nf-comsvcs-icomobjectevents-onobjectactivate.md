# IComObjectEvents::OnObjectActivate

## Description

Generated when an object gets an instance of a new JIT-activated object.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `CtxtID` [in]

The GUID of the current context.

### `ObjectID` [in]

The JIT-activated object.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectevents)