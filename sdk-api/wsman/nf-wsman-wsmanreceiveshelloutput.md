# WSManReceiveShellOutput function

## Description

Retrieves output from a running command or from the shell.

## Parameters

### `shell` [in, out]

Specifies the shell handle returned by a [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `command` [in, optional]

Specifies the command handle returned by a [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) call.

### `flags`

Reserved for future use. Must be set to zero.

### `desiredStreamSet` [in, optional]

Specifies the requested output from a particular stream or a list of streams.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL** and should be closed by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation) method.

### `receiveOperation` [out]

Defines the operation handle for the receive operation. This handle is returned from a successful call of the function and can be used to asynchronously cancel the receive operation. This handle should be closed by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation) method. This parameter cannot be **NULL**.