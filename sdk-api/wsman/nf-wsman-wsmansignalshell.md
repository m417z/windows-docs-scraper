# WSManSignalShell function

## Description

Sends a control code to an existing command or to the shell itself.

## Parameters

### `shell` [in]

Specifies the handle returned by a [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `command` [in, optional]

Specifies the command handle returned by a [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) call. If this value is **NULL**, the signal code is sent to the shell.

### `flags`

Reserved for future use. Must be set to zero.

### `code` [in]

Specifies the signal code to send to the command or shell.
The following codes are common.

#### WSMAN_SIGNAL_SHELL_CODE_TERMINATE

The shell or Command Prompt window was closed.

#### WSMAN_SIGNAL_SHELL_CODE_CTRL_C

The signal for CTRL+C was received, and the process was halted.

#### WSMAN_SIGNAL_SHELL_CODE_CTRL_BREAK

The signal for CTRL+BREAK was received, and the process was halted.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL** and should be closed by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation) method.

### `signalOperation` [out]

Defines the operation handle for the signal operation. This handle is returned from a successful call of the function and can be used to asynchronously cancel the signal operation. This handle should be closed by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation) method. This parameter cannot be **NULL**.