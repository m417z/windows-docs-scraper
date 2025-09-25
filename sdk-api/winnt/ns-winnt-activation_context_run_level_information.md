# ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION structure

## Description

The **ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION** structure is used by the [QueryActCtxW](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-queryactctxw) function.

## Members

### `ulFlags`

This parameter is reserved for future use. This parameter currently returns 0.

### `RunLevel`

A [ACTCTX_REQUESTED_RUN_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-actctx_requested_run_level) enumeration value that gives the requested run level of the activation context.

### `UiAccess`

This parameter returns zero if the **uiAccess** attribute in the application manifest is false. This parameter returns a non-zero value if the **uiAccess** attribute in the manifest is true. True means that UI accessibility applications require access higher privileges.