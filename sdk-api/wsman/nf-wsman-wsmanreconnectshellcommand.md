# WSManReconnectShellCommand function

## Description

Reconnects a previously disconnected command.

## Parameters

### `commandHandle` [in, out]

Specifies the handle returned by a [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) call or a [WSManConnectShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanconnectshellcommand) call. This parameter cannot be NULL.

### `flags`

Reserved for future use. Must be set to zero.

### `async` [in]

Defines an asynchronous structure which will contain an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be NULL.