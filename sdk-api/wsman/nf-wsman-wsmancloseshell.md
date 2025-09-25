# WSManCloseShell function

## Description

Deletes a shell object and frees the resources associated with the shell.

## Parameters

### `shellHandle` [in, out, optional]

Specifies the shell handle to close. This handle is returned by a [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be set to zero.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL**.