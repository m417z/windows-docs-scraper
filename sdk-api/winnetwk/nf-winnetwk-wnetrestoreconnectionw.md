# WNetRestoreConnectionW function

## Description

[**WNetRestoreConnectionW** is not available for use as of Windows Vista.]

The **WNetRestoreConnectionW** function restores the connection to a network resource. The function prompts the user, if necessary, for a name and password.

## Parameters

### `hWnd` [in]

Handle to the parent window that the function uses to display the user interface (UI) that prompts the user for a name and password when making the network connection. If this parameter is **NULL**, there is no owner window.

### `lpDevice` [in]

Pointer to a **null**-terminated Unicode string that specifies the local name of the drive to connect to, such as "Z:". If this parameter is **NULL**, the function reconnects all persistent drives stored in the registry for the current user.

#### - fUseUI

If true, display a username/password prompt to the caller; otherwise, do not display it. The default value is true.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the network resource. |
| **ERROR_ALREADY_ASSIGNED** | The local device specified by *lpDevice* is already connected to a network resource. |
| **ERROR_BAD_DEV_TYPE** | The type of local device and the type of network resource do not match. |
| **ERROR_BAD_DEVICE** | The value specified by *lpDevice* is invalid. |
| **ERROR_BAD_PROFILE** | The user profile is in an incorrect format. |
| **ERROR_BUSY** | The router or provider is busy, possibly initializing. The caller should retry. |
| **ERROR_CANCELLED** | The attempt to make the connection was canceled by the user through a dialog box from one of the network resource providers, or by a called resource. |
| **ERROR_CANNOT_OPEN_PROFILE** | The system is unable to open the user profile to process persistent connections. |
| **ERROR_DEVICE_ALREADY_REMEMBERED** | An entry for the device is already in the user profile. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function to obtain a description of the error. |
| **ERROR_INVALID_PASSWORD** | The specified password is invalid. |
| **ERROR_NO_NET_OR_BAD_PATH** | The operation cannot be performed because a network component is not started or because a specified name cannot be used. |
| **ERROR_NO_NETWORK** | The network is unavailable. |

## Remarks

The **WNetRestoreConnectionW** function is not supported on Windows Vista and later.

To call this function, first call the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load Mpr.dll. Then call the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to retrieve the address of the **WNetRestoreConnectionW** function.

**WNetRestoreConnectionW** is used by Winlogon to restore all persistent drive mappings during the interactive logon process. The function is also called by the Microsoft Windows Shell to reconnect individual drives at the user's request. This can occur, for example, when a drive fails to reconnect at logon and the user double-clicks the drive under the My Computer virtual folder.

## See also

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)