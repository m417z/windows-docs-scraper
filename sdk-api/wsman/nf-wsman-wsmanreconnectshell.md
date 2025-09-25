# WSManReconnectShell function

## Description

Reconnects a previously disconnected shell session. To reconnect the shell session's associated commands, use [WSManReconnectShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanreconnectshellcommand).

## Parameters

### `shell` [in, out]

Specifies the handle returned by a call to the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) function. This parameter cannot be **NULL**.

### `flags`

This parameter is reserved for future use and must be set to zero.

### `async` [in]

Defines an asynchronous structure to contain an optional user context and a mandatory callback function. For more information, see [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async). This parameter cannot be **NULL**.