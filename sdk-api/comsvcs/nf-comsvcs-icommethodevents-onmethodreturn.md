# IComMethodEvents::OnMethodReturn

## Description

Generated when an object's method returns.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `oid` [in]

The just-in-time (JIT) activated object.

### `guidCid` [in]

The CLSID for the object being called.

### `guidRid` [in]

The identifier of the method.

### `iMeth` [in]

The v-table index of the method.

### `hresult` [in]

The result of the method call.

## Return value

The user verifies the return values from this method.

## See also

[IComMethodEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icommethodevents)