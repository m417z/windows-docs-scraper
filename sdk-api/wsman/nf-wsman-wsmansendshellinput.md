# WSManSendShellInput function

## Description

Pipes the input stream to a running command or to the shell.

## Parameters

### `shell` [in]

Specifies the shell handle returned by a [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) call. This parameter cannot be **NULL**.

### `command` [in, optional]

Specifies the command handle returned by a [WSManRunShellCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanrunshellcommand) call. This handle should be closed by calling the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) method.

### `flags`

Reserved for future use. Must be set to zero.

### `streamId` [in]

Specifies the input stream ID. This parameter cannot be **NULL**.

### `streamData` [in]

Uses the [WSMAN_DATA](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_data) structure to specify the stream data to be sent to the command or shell. This structure should be allocated by the calling client and must remain allocated until **WSManSendShellInput** completes. If the end of the stream has been reached, the *endOfStream* parameter should be set to **TRUE**.

### `endOfStream`

Set to **TRUE**, if the end of the stream has been reached. Otherwise, this parameter is set to **FALSE**.

### `async` [in]

Defines an asynchronous structure. The asynchronous structure contains an optional user context and a mandatory callback function. See the [WSMAN_SHELL_ASYNC](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_shell_async) structure for more information. This parameter cannot be **NULL** and should be closed by calling the [WSManCloseCommand](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmanclosecommand) method.

### `sendOperation` [out]

Defines the operation handle for the send operation. This handle is returned from a successful call of the function and can be used to asynchronously cancel the send operation. This handle should be closed by calling the [WSManCloseOperation](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancloseoperation) method. This parameter cannot be **NULL**.