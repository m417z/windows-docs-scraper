# IComObjectEvents::OnDisableCommit

## Description

Generated when the client calls [DisableCommit](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iobjectcontext-disablecommit) on a context.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `CtxtID` [in]

The GUID of the current context.

## Return value

The user verifies the return values from this method.

## See also

[IComObjectEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomobjectevents)