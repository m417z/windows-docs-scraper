# WSMAN_SHELL_COMPLETION_FUNCTION callback function

## Description

The callback function that is called for shell operations, which result in a remote request.

## Parameters

### `operationContext` [in, optional]

Represents user-defined context passed to the WinRM (WinRM) Client Shell
application programming interface (API) .

### `flags`

Specifies one or more flags from the
[WSManCallbackFlags](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmancallbackflags) enumeration.

### `error` [in]

Defines the [WSMAN_ERROR](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_error) structure, which is
valid in the callback only.

### `shell` [in]

Specifies the shell handle associated with the user context. The shell handle must be closed by calling
the [WSManCloseShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseshell) method.

### `command` [in, optional]

Specifies the command handle associated with the user context. The command handle must be closed by calling
the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) API method.

### `operationHandle` [in, optional]

Defines the operation handle associated with the user context. The operation handle is valid only for
callbacks that are associated with
[WSManReceiveShellOutput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanreceiveshelloutput),
[WSManSendShellInput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansendshellinput), and
[WSManSignalShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmansignalshell) calls. This handle must be closed
by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation)
method.

### `data` [in, optional]

Defines the output data from the command or shell as a result of a
[WSManReceiveShellOutput](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanreceiveshelloutput) call. For more
information about the output data, see the
[WSMAN_RECEIVE_DATA_RESULT](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_receive_data_result) structure.