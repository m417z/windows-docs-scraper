# WNetConnectionDialog function

## Description

The
**WNetConnectionDialog** function starts a general browsing dialog box for connecting to network resources. The function requires a handle to the owner window for the dialog box.

## Parameters

### `hwnd` [in]

Handle to the owner window for the dialog box.

### `dwType` [in]

Resource type to allow connections to. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **RESOURCETYPE_DISK** | Connections to disk resources. |

## Return value

If the function succeeds, the return value is NO_ERROR. If the user cancels the dialog box, the function returns –1.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_INVALID_PASSWORD** | The specified password is invalid. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is insufficient memory to start the dialog box. |

## Remarks

If the user clicks **OK** in the dialog box, the requested network connection will have been made when the
**WNetConnectionDialog** function returns.

If the function attempts to make a connection and the network provider returns the message ERROR_INVALID_PASSWORD, the system prompts the user to enter a password. The system uses the new password in another attempt to make the connection.

## See also

[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)

[WNetDisconnectDialog](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetdisconnectdialog)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)