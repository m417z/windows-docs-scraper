# WSManCreateShell function

## Description

Creates a shell object. The returned shell handle identifies an object that defines the context in which commands can be run. The context is defined by the environment variables, the input and output streams, and the working directory. The context can directly affect the behavior of a command. A shell context is created on the remote computer specified by the connection parameter and authenticated by using the credentials parameter.

## Parameters

### `session` [in, out]

Specifies the session handle returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) call. This parameter cannot be **NULL**.

### `flags`

Reserved for future use. Must be zero.

### `resourceUri` [in]

Defines the shell type to create. The shell type is defined by a unique URI. The actual shell object returned by the call is dependent on the URI specified. This parameter cannot be **NULL**. To create a Windows cmd.exe shell, use the **WSMAN_CMDSHELL_URI** resource URI.

### `startupInfo` [in, optional]

A pointer to a [WSMAN_SHELL_STARTUP_INFO](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_startup_info_v10) structure that specifies the input and output streams, working directory, idle time-out, and options for the shell.

If this parameter is **NULL**, the default values will be used.

### `options` [in, optional]

A pointer to a [WSMAN_OPTION_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_option_set) structure that specifies a set of options for the shell.

### `createXml` [in, optional]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that defines an open context for the shell. The content should be a valid XML string. This parameter can be **NULL**.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL** and should be closed by calling the [WSManCloseShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseshell) method.

### `shell` [out]

Defines a shell handle that uniquely identifies the shell object. The resource handle is used to track the client endpoint for the shell and is used by other WinRM methods to interact with the shell object. The shell object should be deleted by calling the [WSManCloseShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseshell) method. This parameter cannot be **NULL**.