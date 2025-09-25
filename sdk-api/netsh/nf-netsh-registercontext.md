# RegisterContext function

## Description

The
**RegisterContext** function registers a helper context with NetShell. The
**RegisterContext** function should be called from the
[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn) entry point (the start function) passed to the
[RegisterHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registerhelper) function in the **pfnStart** member of the
[NS_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_context_attributes) structure passed in its *pChildAttributes* parameter.

## Parameters

### `pChildContext` [in]

Attributes of the context to register.

## Remarks

For top-level helpers, the
**RegisterContext** parameter passed during the course of its initialization function is a pointer to the
**RegisterContext** function. The pointer should be cast to type **NS_REGISTER_CONTEXT** before use.

## See also

[NS_CONTEXT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_context_attributes)

[NS_HELPER_START_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_start_fn)

[RegisterHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registerhelper)