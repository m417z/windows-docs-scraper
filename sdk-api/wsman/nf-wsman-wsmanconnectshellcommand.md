# WSManConnectShellCommand function

## Description

Connects to an existing command running in a shell.

## Parameters

### `shell` [in, out]

Specifies the shell handle returned by the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be zero.

### `commandID` [in]

A null-terminated string that identifies a specific command, currently running in the server session, that the client intends to connect to.

### `options` [in, optional]

Defines a set of options for the command. These options are passed to the service to modify or refine the command execution. This parameter can be **NULL**. For more information about the options, see [WSMAN_OPTION_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_option_set).

### `connectXml` [in, optional]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that defines an open context for the connect shell operation. The content must be a valid XML string. This parameter can be **NULL**.

### `async` [in]

Defines an asynchronous structure to contain an optional user context and a mandatory callback function. For more information, see [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async). This parameter cannot be **NULL**.

### `command` [out]

This handle is returned on a successful call and is used to send and receive data and to signal the command. When you have finished using this handle, close it by calling the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) method. This parameter cannot be **NULL**.