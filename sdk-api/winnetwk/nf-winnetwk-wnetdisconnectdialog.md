# WNetDisconnectDialog function

## Description

The
**WNetDisconnectDialog** function starts a general browsing dialog box for disconnecting from network resources. The function requires a handle to the owner window for the dialog box.

## Parameters

### `hwnd` [in]

Handle to the owner window for the dialog box.

### `dwType` [in]

Resource type to disconnect from. This parameter can have the following value.

| Value | Meaning |
| --- | --- |
| **RESOURCETYPE_DISK** | Disconnects from disk resources. |

## Return value

If the function succeeds, the return value is NO_ERROR. If the user cancels the dialog box, the return value is –1.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is insufficient memory to start the dialog box. |

## Remarks

The
**WNetDisconnectDialog** function returns immediately and creates a dialog box for disconnecting networked drives. This dialog box runs asynchronously on a worker thread.

If the worker thread is terminated, the owner window and its associated dialog box are also terminated. If this occurs, the user might not be able to interact with the dialog box, because it will not appear on the user's screen or will appear briefly.

## See also

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)

[WNetConnectionDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog)

[WNetConnectionDialog1](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetconnectiondialog1a)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)