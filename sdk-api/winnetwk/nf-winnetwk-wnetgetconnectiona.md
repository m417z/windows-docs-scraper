# WNetGetConnectionA function

## Description

The
**WNetGetConnection** function retrieves the name of the network resource associated with a local device.

## Parameters

### `lpLocalName` [in]

Pointer to a constant null-terminated string that specifies the name of the local device to get the network name for.

### `lpRemoteName` [out]

Pointer to a null-terminated string that receives the remote name used to make the connection.

### `lpnLength` [in, out]

Pointer to a variable that specifies the size of the buffer pointed to by the *lpRemoteName* parameter, in characters. If the function fails because the buffer is not large enough, this parameter returns the required buffer size.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_DEVICE** | The string pointed to by the *lpLocalName* parameter is invalid. |
| **ERROR_NOT_CONNECTED** | The device specified by *lpLocalName* is not a redirected device. For more information, see the following Remarks section. |
| **ERROR_MORE_DATA** | The buffer is too small. The *lpnLength* parameter points to a variable that contains the required buffer size. More entries are available with subsequent calls. |
| **ERROR_CONNECTION_UNAVAIL** | The device is not currently connected, but it is a persistent connection. For more information, see the following Remarks section. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_NO_NET_OR_BAD_PATH** | None of the providers recognize the local name as having a connection. However, the network is not available for at least one provider to whom the connection may belong. |

## Remarks

If the network connection was made using the Microsoft LAN Manager network, and the calling application is running in a different logon session than the application that made the connection, a call to the
**WNetGetConnection** function for the associated local device will fail. The function fails with ERROR_NOT_CONNECTED or ERROR_CONNECTION_UNAVAIL. This is because a connection made using Microsoft LAN Manager is visible only to applications running in the same logon session as the application that made the connection. (To prevent the call to
**WNetGetConnection** from failing it is not sufficient for the application to be running in the user account that created the connection.)

**Windows Server 2003 and Windows XP:** This function queries the MS-DOS device namespaces associated with a logon session because MS-DOS devices are identified by AuthenticationID. (An AuthenticationID is the
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. **GetLogicalDrives** does not return network drive letters created by a WNet function under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

#### Examples

For a code sample that illustrates how to use the
**WNetGetConnection** function to retrieve the name of the network resource associated with a local device, see
[Retrieving the Connection Name](https://learn.microsoft.com/windows/desktop/WNet/retrieving-the-connection-name).

> [!NOTE]
> The winnetwk.h header defines WNetGetConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)

[WNetGetUser](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetusera)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)