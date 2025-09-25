# WNetAddConnectionA function

## Description

The
**WNetAddConnection** function enables the calling application to connect a local device to a network resource. A successful connection is persistent, meaning that the system automatically restores the connection during subsequent logon operations.

**Note** This function is provided only for compatibility with 16-bit versions of Windows. Other Windows-based applications should call the
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) or the
[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a) function.

## Parameters

### `lpRemoteName` [in]

A pointer to a constant **null**-terminated string that specifies the network resource to connect to.

### `lpPassword` [in]

A pointer to a constant **null**-terminated string that specifies the password to be used to make a connection. This parameter is usually the password associated with the current user.

If this parameter is **NULL**, the default password is used. If the string is empty, no password is used.

**Windows Me/98/95:** This parameter must be **NULL** or an empty string.

### `lpLocalName` [in]

A pointer to a constant **null**-terminated string that specifies the name of a local device to be redirected, such as "F:" or "LPT1". The string is treated in a case-insensitive manner. If the string is **NULL**, a connection to the network resource is made without redirecting the local device.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the network resource. |
| **ERROR_ALREADY_ASSIGNED** | The device specified in the *lpLocalName* parameter is already connected. |
| **ERROR_BAD_DEV_TYPE** | The device type and the resource type do not match. |
| **ERROR_BAD_DEVICE** | The value specified in the *lpLocalName* parameter is invalid. |
| **ERROR_BAD_NET_NAME** | The value specified in the *lpRemoteName* parameter is not valid or cannot be located. |
| **ERROR_BAD_PROFILE** | The user profile is in an incorrect format. |
| **ERROR_CANNOT_OPEN_PROFILE** | The system is unable to open the user profile to process persistent connections. |
| **ERROR_DEVICE_ALREADY_REMEMBERED** | An entry for the device specified in the *lpLocalName* parameter is already in the user profile. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_INVALID_PASSWORD** | The specified password is invalid. |
| **ERROR_NO_NET_OR_BAD_PATH** | The operation cannot be performed because a network component is not started or because a specified name cannot be used. |
| **ERROR_NO_NETWORK** | The network is unavailable. |

## Remarks

On Windows Server 2003 and Windows XP, the WNet functions create and delete network drive letters in the MS-DOS device namespace associated with a logon session because MS-DOS devices are identified by AuthenticationID (a
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. The call to the **GetLogicalDrives** function does not return network drive letters created by WNet function calls under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

On Windows Server 2003 and Windows XP, if a service that runs as LocalSystem calls the **WNetAddConnection** function, then the mapped drive is visible to all user logon sessions.

> [!NOTE]
> The winnetwk.h header defines WNetAddConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)

[WNetCancelConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnectiona)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)