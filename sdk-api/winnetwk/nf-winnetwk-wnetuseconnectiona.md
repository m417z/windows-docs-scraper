# WNetUseConnectionA function

## Description

The
**WNetUseConnection** function makes a connection to a network resource. The function can redirect a local device to a network resource.

The
**WNetUseConnection** function is similar to the
[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a) function. The main difference is that
**WNetUseConnection** can automatically select an unused local device to redirect to the network resource.

## Parameters

### `hwndOwner` [in]

Handle to a window that the provider of network resources can use as an owner window for dialog boxes. Use this parameter if you set the CONNECT_INTERACTIVE value in the *dwFlags* parameter.

### `lpNetResource` [in]

Pointer to a [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure that specifies details of the proposed connection. The structure contains information about the network resource, the local device, and the network resource provider.

You must specify the following members of the
**NETRESOURCE** structure.

| Member | Meaning |
| --- | --- |
| **dwType** | Specifies the type of resource to connect to. <br><br>It is most efficient to specify a resource type in this member, such as RESOURCETYPE_DISK or RESOURCETYPE_PRINT. However, if the **lpLocalName** member is **NULL**, or if it points to an empty string and CONNECT_REDIRECT is not set, **dwType** can be RESOURCETYPE_ANY.<br><br>This method works only if the function does not automatically choose a device to redirect to the network resource.<br><br>Although this member is required, its information may be ignored by the network service provider. |
| **lpLocalName** | Pointer to a **null**-terminated string that specifies the name of a local device to be redirected, such as "F:" or "LPT1". The string is treated in a case-insensitive manner. <br><br>If the string is empty, or if **lpLocalName** is **NULL**, a connection to the network occurs without redirection.<br><br>If the CONNECT_REDIRECT value is set in the *dwFlags* parameter, or if the network requires a redirected local device, the function chooses a local device to redirect and returns the name of the device in the *lpAccessName* parameter. |
| **lpRemoteName** | Pointer to a **null**-terminated string that specifies the network resource to connect to. The string can be up to MAX_PATH characters in length, and it must follow the network provider's naming conventions. |
| **lpProvider** | Pointer to a **null**-terminated string that specifies the network provider to connect to. If **lpProvider** is **NULL**, or if it points to an empty string, the operating system attempts to determine the correct provider by parsing the string pointed to by the **lpRemoteName** member. <br><br>If this member is not **NULL**, the operating system attempts to make a connection only to the named network provider.<br><br>You should set this member only if you know the network provider you want to use. Otherwise, let the operating system determine which provider the network name maps to. |

The
**WNetUseConnection** function ignores the other members of the
[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) structure. For more information, see the descriptions following for the *dwFlags* parameter.

### `lpPassword` [in]

Pointer to a constant **null**-terminated string that specifies a password to be used in making the network connection.

If *lpPassword* is **NULL**, the function uses the current default password associated with the user specified by *lpUserID*.

If *lpPassword* points to an empty string, the function does not use a password.

If the connection fails because of an invalid password and the CONNECT_INTERACTIVE value is set in the *dwFlags* parameter, the function displays a dialog box asking the user to type the password.

### `lpUserId` [in]

Pointer to a constant **null**-terminated string that specifies a user name for making the connection.

If *lpUserID* is **NULL**, the function uses the default user name. (The user context for the process provides the default user name.)

The *lpUserID* parameter is specified when users want to connect to a network resource for which they have been assigned a user name or account other than the default user name or account.

The user-name string represents a
[security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). It may be specific to a network provider.

### `dwFlags` [in]

Set of bit flags describing the connection. This parameter can be any combination of the following values.

| Value | Meaning |
| --- | --- |
| **CONNECT_INTERACTIVE** | If this flag is set, the operating system may interact with the user for authentication purposes. |
| **CONNECT_PROMPT** | This flag instructs the system not to use any default settings for user names or passwords without offering the user the opportunity to supply an alternative. This flag is ignored unless CONNECT_INTERACTIVE is also set. |
| **CONNECT_REDIRECT** | This flag forces the redirection of a local device when making the connection. <br><br>If the **lpLocalName** member of [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcea) specifies a local device to redirect, this flag has no effect, because the operating system still attempts to redirect the specified device. When the operating system automatically chooses a local device, the **dwType** member must not be equal to RESOURCETYPE_ANY.<br><br>If this flag is not set, a local device is automatically chosen for redirection only if the network requires a local device to be redirected.<br><br>**Windows XP:** When the system automatically assigns network drive letters, letters are assigned beginning with Z:, then Y:, and ending with C:. This reduces collision between per-logon drive letters (such as network drive letters) and global drive letters (such as disk drives). Note that previous releases assigned drive letters beginning with C: and ending with Z:. |
| **CONNECT_UPDATE_PROFILE** | This flag instructs the operating system to store the network resource connection. <br><br>If this bit flag is set, the operating system automatically attempts to restore the connection when the user logs on. The system remembers only successful connections that redirect local devices. It does not remember connections that are unsuccessful or deviceless connections. (A deviceless connection occurs when **lpLocalName** is **NULL** or when it points to an empty string.)<br><br>If this bit flag is clear, the operating system does not automatically restore the connection at logon. |
| **CONNECT_COMMANDLINE** | If this flag is set, the operating system prompts the user for authentication using the command line instead of a graphical user interface (GUI). This flag is ignored unless CONNECT_INTERACTIVE is also set.<br><br>**Windows 2000/NT and Windows Me/98/95:** This value is not supported. |
| **CONNECT_CMD_SAVECRED** | If this flag is set, and the operating system prompts for a credential, the credential should be saved by the credential manager. If the credential manager is disabled for the caller's logon session, or if the network provider does not support saving credentials, this flag is ignored. This flag is also ignored unless you set the CONNECT_COMMANDLINE flag.<br><br>**Windows 2000/NT and Windows Me/98/95:** This value is not supported. |

### `lpAccessName` [out]

Pointer to a buffer that receives system requests on the connection. This parameter can be **NULL**.

If this parameter is specified, and the **lpLocalName** member of the
**NETRESOURCE** structure specifies a local device, this buffer receives the local device name. If **lpLocalName** does not specify a device and the network requires a local device redirection, or if the CONNECT_REDIRECT value is set, this buffer receives the name of the redirected local device.

Otherwise, the name copied into the buffer is that of a remote resource. If specified, this buffer must be at least as large as the string pointed to by the **lpRemoteName** member.

### `lpBufferSize` [in, out]

Pointer to a variable that specifies the size of the *lpAccessName* buffer, in characters. If the call fails because the buffer is not large enough, the function returns the required buffer size in this location. For more information, see the descriptions of the *lpAccessName* parameter and the ERROR_MORE_DATA error code in the Return Values section.

### `lpResult` [out]

Pointer to a variable that receives additional information about the connection. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **CONNECT_LOCALDRIVE** | If this flag is set, the connection was made using a local device redirection. If the *lpAccessName* parameter points to a buffer, the local device name is copied to the buffer. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the network resource. |
| **ERROR_ALREADY_ASSIGNED** | The local device specified by the **lpLocalName** member is already connected to a network resource. |
| **ERROR_BAD_DEVICE** | The value specified by **lpLocalName** is invalid. |
| **ERROR_BAD_NET_NAME** | The value specified by the **lpRemoteName** member is not acceptable to any network resource provider because the resource name is invalid, or because the named resource cannot be located. |
| **ERROR_BAD_PROVIDER** | The value specified by the **lpProvider** member does not match any provider. |
| **ERROR_CANCELLED** | The attempt to make the connection was canceled by the user through a dialog box from one of the network resource providers, or by a called resource. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. To obtain a description of the error, call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function. |
| **ERROR_INVALID_ADDRESS** | The caller passed in a pointer to a buffer that could not be accessed. |
| **ERROR_INVALID_PARAMETER** | This error is a result of one of the following conditions: <br><br>1. The **lpRemoteName** member is **NULL**. In addition, *lpAccessName* is not **NULL**, but *lpBufferSize* is either **NULL** or points to zero. 2. The **dwType** member is neither RESOURCETYPE_DISK nor RESOURCETYPE_PRINT. In addition, either CONNECT_REDIRECT is set in *dwFlags* and **lpLocalName** is **NULL**, or the connection is to a network that requires the redirecting of a local device. |
| **ERROR_INVALID_PASSWORD** | The specified password is invalid and the CONNECT_INTERACTIVE flag is not set. |
| **ERROR_MORE_DATA** | The *lpAccessName* buffer is too small. <br><br>If a local device is redirected, the buffer needs to be large enough to contain the local device name. Otherwise, the buffer needs to be large enough to contain either the string pointed to by **lpRemoteName**, or the name of the connectable resource whose alias is pointed to by **lpRemoteName**. If this error is returned, then no connection has been made. |
| **ERROR_NO_MORE_ITEMS** | The operating system cannot automatically choose a local redirection because all the valid local devices are in use. |
| **ERROR_NO_NET_OR_BAD_PATH** | The operation could not be completed, either because a network component is not started, or because the specified resource name is not recognized. |
| **ERROR_NO_NETWORK** | The network is unavailable. |

## Remarks

**Windows Server 2003 and Windows XP:** The WNet functions create and delete network drive letters in the MS-DOS device namespace associated with a logon session because MS-DOS devices are identified by AuthenticationID. (An AuthenticationID is the
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. **GetLogicalDrives** does not return network drive letters created by a WNet function under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

> [!NOTE]
> The winnetwk.h header defines WNetUseConnection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetAddConnection3](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection3a)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)

[WnetCancelConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnectiona)