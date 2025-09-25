# RegisterHelper function

## Description

The
**RegisterHelper** function is called from within a helper's exposed
[InitHelperDll](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_dll_init_fn) function, and registers the helper with the NetShell context.

## Parameters

### `pguidParentContext` [in]

A pointer to GUID of another helper under which the helper should be installed. If null, the helper is installed as a top-level helper.

### `pfnRegisterSubContext` [in]

Attributes of the helper.

## See also

[InitHelperDll](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_dll_init_fn)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)