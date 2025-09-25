# IComMethod2Events::OnMethodException2

## Description

Generated when an object's method generates an exception.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `oid` [in]

The just-in-time (JIT) activated object.

### `guidCid` [in]

The CLSID for the object being called.

### `guidRid` [in]

The identifier of the method being called.

### `dwThread` [in]

The identifier of the thread executing the call.

### `iMeth` [in]

The v-table index of the method.

## Return value

The user verifies the return values from this method.

## See also

[IComMethod2Events](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icommethod2events)