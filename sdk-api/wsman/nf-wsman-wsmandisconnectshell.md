# WSManDisconnectShell function

## Description

Disconnects the network connection of an active shell and its associated commands.

## Parameters

### `shell` [in, out]

Specifies the handle returned by a call to the
[WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) function. This parameter cannot
be **NULL**.

### `flags`

Can be a **WSMAN_FLAG_SERVER_BUFFERING_MODE_DROP** flag or a
**WSMAN_FLAG_SERVER_BUFFERING_MODE_BLOCK** flag.

### `disconnectInfo` [in]

A pointer to a
[WSMAN_SHELL_DISCONNECT_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_disconnect_info) structure
that specifies an idle time-out that the server session may enforce. If this parameter is
**NULL**, the server session idle time-out will not be changed.

### `async` [in]

Defines an asynchronous structure to contain an optional user context and a mandatory callback function.
For more information, see [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async). This
parameter cannot be **NULL**.

## Remarks

This function suspends network connection to an actively connected server session. Any operations performed on
the shell instance, like [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand),
[WSManSendShellInput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansendshellinput), or
[WSManSignalShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansignalshell), are bound to complete before
disconnection. This ensures that any data sent through
**WSManSendShellInput** is received by the server
session before the shell disconnects. The client can optionally modify the server buffering mode by using flags.
The following behavior is observed:

* **WSMAN_FLAG_SERVER_BUFFERING_MODE_DROP**–When buffers are full,
  the server drops earlier data in response stream buffers to ensure the corresponding command operation
  continues to run.
* **WSMAN_FLAG_SERVER_BUFFERING_MODE_BLOCK**–When response stream
  buffers are full, the server blocks command execution. If no flag is specified, the server continues to use
  either the configured mode or the mode specified when the shell was created. In case of a network failure, if
  the client is unable to contact the session to disconnect the shell, the following error is returned:

  **ERROR_WINRS_SHELL_DISCONNECT_OPERATION_NOT_GRACEFUL**

  The client session still goes into a disconnected state, but it is not guaranteed that any prior operations
  have completed before the session is disconnected.