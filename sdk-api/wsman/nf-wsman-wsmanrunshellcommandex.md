# WSManRunShellCommandEx function

## Description

Provides the same functionality as the [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) function, with the addition of a command ID option. If the server supports the protocol, it will create the command instance using the ID specified by the client. If a command with the specified ID already exists, the server will fail to create the command instance. This new functionality is only available when the client application passes the **WSMAN_FLAG_REQUESTED_API_VERSION_1_1** flag as part of the call to the [WSManInitialize](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmaninitialize) function.

## Parameters

### `shell` [in, out]

Specifies the shell handle returned by the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be 0.

### `commandId` [in]

The client specified command Id.

### `commandLine` [in]

Defines a required null-terminated string that represents the command to be executed. Typically, the command is specified without any arguments, which are specified separately. However, a user can specify the command line and all of the arguments by using this parameter. If arguments are specified for the commandLine parameter, the args parameter should be **NULL**.

### `args` [in, optional]

A pointer to a [WSMAN_COMMAND_ARG_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_command_arg_set) structure that defines an array of argument values, which are passed to the command on creation. If no arguments are required, this parameter should be **NULL**.

### `options` [in, optional]

Defines a set of options for the command. These options are passed to the service to modify or refine the command execution. This parameter can be **NULL**. For more information about the options, see [WSMAN_OPTION_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_option_set).

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL** and should be closed by calling the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) method.

### `command` [out]

Defines the command object associated with a command within a shell. This handle is returned on a successful call and is used to send and receive data and to signal the command. This handle should be closed by calling the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) method. This parameter cannot be **NULL**.