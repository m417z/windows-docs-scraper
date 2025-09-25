# WNetCancelConnectionW function

## Description

The
**WNetCancelConnection** function cancels an existing network connection.

The
**WNetCancelConnection** function is provided for compatibility with 16-bit versions of Windows. Other Windows-based applications should call the
[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a) function.

## Parameters

### `lpName` [in]

Pointer to a constant null-terminated string that specifies the name of either the redirected local device or the remote network resource to disconnect from.

When this parameter specifies a redirected local device, the function cancels only the specified device redirection. If the parameter specifies a remote network resource, only the connections to remote networks without devices are canceled.

### `fForce` [in]

Specifies whether or not the disconnection should occur if there are open files or jobs on the connection. If this parameter is **FALSE**, the function fails if there are open files or jobs.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PROFILE** | The user profile is in an incorrect format. |
| **ERROR_CANNOT_OPEN_PROFILE** | The system is unable to open the user profile to process persistent connections. |
| **ERROR_DEVICE_IN_USE** | The device is in use by an active process and cannot be disconnected. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_NOT_CONNECTED** | The name specified by the *lpName* parameter is not a redirected device, or the system is not currently connected to the device specified by the parameter. |
| **ERROR_OPEN_FILES** | There are open files, and the *fForce* parameter is **FALSE**. |

## Remarks

**Windows Server 2003 and Windows XP:** The WNet functions create and delete network drive letters in the MS-DOS device namespace associated with a logon session because MS-DOS devices are identified by AuthenticationID. (An AuthenticationID is the
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. **GetLogicalDrives** does not return network drive letters created by a WNet function under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

> [!NOTE]
> The winnetwk.h header defines WNetCancelConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona)

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)