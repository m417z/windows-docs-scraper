# WSManConnectShell function

## Description

Connects to an existing server session.

## Parameters

### `session` [in, out]

Specifies the session handle returned by a [WSManCreateSession](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreatesession) function. This parameter cannot be NULL.

### `flags`

Reserved for future use. Must be zero.

### `resourceUri` [in]

Defines the shell type to which the connection will be made. The shell type is defined by a unique URI, therefore the shell object returned by the call is dependent on the URI that is specified by this parameter. The *resourceUri* parameter cannot be NULL and it is a null-terminated string.

### `shellID` [in]

Specifies the shell identifier that is associated with the server shell session to which the client intends to connect.

### `options` [in, optional]

A pointer to a [WSMAN_OPTION_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_option_set) structure that specifies a set of options for the shell. This parameter is optional.

### `connectXml` [in, optional]

A pointer to a [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure that defines an open context for the connect shell operation. The content should be a valid XML string. This parameter can be NULL.

### `async` [in]

Defines an asynchronous structure that contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be NULL.

### `shell` [out]

Specifies a shell handle that uniquely identifies the shell object that was returned by *resourceURI*. The resource handle tracks the client endpoint for the shell and is used by other WinRM methods to interact with the shell object. The shell object should be deleted by calling the [WSManCloseShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseshell) method. This parameter cannot be NULL.

## Remarks

Connects to an existing server shell session identified by the *ShellId* parameter. This builds the necessary client side context, represented by the return parameter shell, that can be used to carry out subsequent operations such as running commands and sending and receiving output on the server shell session.
This **WSManConnectShell** function does not automatically construct the client side contexts for any commands that are currently associated with the server shell session.