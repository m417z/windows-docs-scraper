# IComInstanceEvents::OnObjectCreate

## Description

Generated when an object is created by a client.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidActivity` [in]

The identifier of the activity in which the object is created.

### `clsid` [in]

The CLSID of the object being created.

### `tsid` [in]

The transaction stream identifier, which is unique for correlation to objects.

### `CtxtID` [in]

The context identifier for this object.

### `ObjectID` [in]

The initial just-in-time (JIT) activated object.

## Return value

The user verifies the return values from this method.

## See also

[IComInstanceEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icominstanceevents)