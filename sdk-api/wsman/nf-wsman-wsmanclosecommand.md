# WSManCloseCommand function

## Description

Deletes a command and frees the resources that are associated with it.

## Parameters

### `commandHandle` [in, out, optional]

Specifies the command handle to be closed. This handle is returned by a [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) call.

### `flags`

Reserved for future use.
Must be set to zero.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL**.