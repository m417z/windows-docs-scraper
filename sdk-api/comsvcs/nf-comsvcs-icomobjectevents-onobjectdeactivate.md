# IComObjectEvents::OnObjectDeactivate

## Description

Generated when the JIT-activated object is freed by [SetComplete](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setcomplete) or [SetAbort](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-setabort).

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