# WNetAddConnection3W function

## Description

The
**WNetAddConnection3** function makes a connection to a network resource. The function can redirect a local device to the network resource.

The
**WNetAddConnection3** function is similar to the
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) function. The main difference is that
**WNetAddConnection3** has an additional parameter, a handle to a window that the provider of network resources can use as an owner window for dialog boxes. The
**WNetAddConnection2** function and the
**WNetAddConnection3** function supersede the
[WNetAddConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnectiona) function.

## Parameters

### `hwndOwner` [in]

A handle to a window that the provider of network resources can use as an owner window for dialog boxes. Use this parameter if you set the CONNECT_INTERACTIVE value in the *dwFlags* parameter.

The *hwndOwner* parameter can be **NULL**. If it is, a call to
**WNetAddConnection3** is equivalent to calling the
[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) function.

### `lpNetResource` [in]

A pointer to a [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure that specifies details of the proposed connection, such as information about the network resource, the local device, and the network resource provider.

You must specify the following members of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure.

| Member | Meaning |
| --- | --- |
| **dwType** | The type of network resource to connect to. <br><br>If the **lpLocalName** member points to a nonempty string, this member can be equal to RESOURCETYPE_DISK or RESOURCETYPE_PRINT.<br><br>If **lpLocalName** is **NULL**, or if it points to an empty string, **dwType** can be equal to RESOURCETYPE_DISK, RESOURCETYPE_PRINT, or RESOURCETYPE_ANY.<br><br>Although this member is required, its information may be ignored by the network service provider. |
| **lpLocalName** | A pointer to a **null**-terminated string that specifies the name of a local device to redirect, such as "F:" or "LPT1". The string is treated in a case-insensitive manner.<br><br>If the string is empty or if **lpLocalName** is **NULL**, the function makes a connection to the network resource without redirecting a local device. |
| **lpRemoteName** | A pointer to a **null**-terminated string that specifies the network resource to connect to. The string can be up to MAX_PATH characters in length, and must follow the network provider's naming conventions. |
| **lpProvider** | A pointer to a **null**-terminated string that specifies the network provider to connect to.<br><br>If **lpProvider** is **NULL**, or if it points to an empty string, the operating system attempts to determine the correct provider by parsing the string pointed to by the **lpRemoteName** member.<br><br>If this member is not **NULL**, the operating system attempts to make a connection only to the named network provider.<br><br>You should set this member only if you know which network provider you want to use. Otherwise, let the operating system determine which network provider the network name maps to. |

The
**WNetAddConnection3** function ignores the other members of the
[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure.

### `lpPassword` [in]

A pointer to a **null**-terminated string that specifies a password to be used in making the network connection.

If *lpPassword* is **NULL**, the function uses the current default password associated with the user specified by the *lpUserName* parameter.

If *lpPassword* points to an empty string, the function does not use a password.

If the connection fails because of an invalid password and the CONNECT_INTERACTIVE value is set in the *dwFlags* parameter, the function displays a dialog box asking the user to type the password.

**Windows Me/98/95:** This parameter must be **NULL** or an empty string.

### `lpUserName` [in]

A pointer to a **null**-terminated string that specifies a user name for making the connection.

If *lpUserName* is **NULL**, the function uses the default user name. (The user context for the process provides the default user name.)

The *lpUserName* parameter is specified when users want to connect to a network resource for which they have been assigned a user name or account other than the default user name or account.

The user-name string represents a
[security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). It may be specific to a network provider.

**Windows Me/98/95:** This parameter must be **NULL** or an empty string.

### `dwFlags` [in]

A set of connection options. The following values are currently defined.

| Value | Meaning |
| --- | --- |
| **CONNECT_INTERACTIVE** | If this flag is set, the operating system may interact with the user for authentication purposes. |
| **CONNECT_PROMPT** | This flag instructs the system not to use any default settings for user names or passwords without offering the user the opportunity to supply an alternative. This flag is ignored unless CONNECT_INTERACTIVE is also set. |
| **CONNECT_REDIRECT** | This flag forces the redirection of a local device when making the connection. <br><br>If the **lpLocalName** member of [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) specifies a local device to redirect, this flag has no effect, because the operating system still attempts to redirect the specified device. When the operating system automatically chooses a local device, the **dwType** member must not be equal to RESOURCETYPE_ANY.<br><br>If this flag is not set, a local device is automatically chosen for redirection only if the network requires a local device to be redirected.<br><br>**Windows Server 2003 and Windows XP:** When the system automatically assigns network drive letters, letters are assigned beginning with Z:, then Y:, and ending with C:. This reduces collision between per-logon drive letters (such as network drive letters) and global drive letters (such as disk drives). Note that earlier versions of Windows assigned drive letters beginning with C: and ending with Z:. |
| **CONNECT_UPDATE_PROFILE** | The network resource connection should be remembered.<br><br>If this bit flag is set, the operating system automatically attempts to restore the connection when the user logs on.<br><br>The operating system remembers only successful connections that redirect local devices. It does not remember connections that are unsuccessful or deviceless connections. (A deviceless connection occurs when the **lpLocalName** member is **NULL** or when it points to an empty string.)<br><br>If this bit flag is clear, the operating system does not automatically restore the connection at logon. |
| **CONNECT_COMMANDLINE** | If this flag is set, the operating system prompts the user for authentication using the command line instead of a graphical user interface (GUI). This flag is ignored unless CONNECT_INTERACTIVE is also set.<br><br>**Windows 2000/NT and Windows Me/98/95:** This value is not supported. |
| **CONNECT_CMD_SAVECRED** | If this flag is set, and the operating system prompts for a credential, the credential should be saved by the credential manager. If the credential manager is disabled for the caller's logon session, or if the network provider does not support saving credentials, this flag is ignored. This flag is also ignored unless you set the CONNECT_COMMANDLINE flag.<br><br>**Windows 2000/NT and Windows Me/98/95:** This value is not supported. |

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), such as one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have access to the network resource. |
| **ERROR_ALREADY_ASSIGNED** | The local device specified by the **lpLocalName** member is already connected to a network resource. |
| **ERROR_BAD_DEV_TYPE** | The type of local device and the type of network resource do not match. |
| **ERROR_BAD_DEVICE** | The value specified by **lpLocalName** is invalid. |
| **ERROR_BAD_NET_NAME** | The value specified by the **lpRemoteName** member is not acceptable to any network resource provider, either because the resource name is invalid, or because the named resource cannot be located. |
| **ERROR_BAD_PROFILE** | The user profile is in an incorrect format. |
| **ERROR_BAD_PROVIDER** | The value specified by the **lpProvider** member does not match any provider. |
| **ERROR_BUSY** | The router or provider is busy, possibly initializing. The caller should retry. |
| **ERROR_CANCELLED** | The attempt to make the connection was canceled by the user through a dialog box from one of the network resource providers, or by a called resource. |
| **ERROR_CANNOT_OPEN_PROFILE** | The system is unable to open the user profile to process persistent connections. |
| **ERROR_DEVICE_ALREADY_REMEMBERED** | An entry for the device specified by the **lpLocalName** member is already in the user profile. |
| **ERROR_EXTENDED_ERROR** | A network-specific error occurred. Call the [WNetGetLastError](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetlasterrora) function to obtain a description of the error. |
| **ERROR_INVALID_PASSWORD** | The specified password is invalid and the CONNECT_INTERACTIVE flag is not set. |
| **ERROR_NO_NET_OR_BAD_PATH** | The operation cannot be performed because a network component is not started or because a specified name cannot be used. |
| **ERROR_NO_NETWORK** | The network is unavailable. |

## Remarks

The
[WNetUseConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetuseconnectiona) function is similar to the
**WNetAddConnection3** function. The main difference is that
**WNetUseConnection** can automatically select an unused local device to redirect to the network resource.

On Windows Server 2003 and Windows XP, the WNet functions create and delete network drive letters in the MS-DOS device namespace associated with a logon session because MS-DOS devices are identified by AuthenticationID (a
[locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly), or LUID, associated with a logon session.) This can affect applications that call one of the WNet functions to create a network drive letter under one user logon, but query for existing network drive letters under a different user logon. An example of this situation could be when a user's second logon is created within a logon session, for example, by calling the
[CreateProcessAsUser](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessasusera) function, and the second logon runs an application that calls the
[GetLogicalDrives](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getlogicaldrives) function. The call to the **GetLogicalDrives** function does not return network drive letters created by WNet function calls under the first logon. Note that in the preceding example the first logon session still exists, and the example could apply to any logon session, including a Terminal Services session. For more information, see
[Defining an MS-DOS Device Name](https://learn.microsoft.com/windows/desktop/FileIO/defining-an-ms-dos-device-name).

On Windows Server 2003 and Windows XP, if a service that runs as LocalSystem calls the **WNetAddConnection3** function, then the mapped drive is visible to all user logon sessions.

For Microsoft network providers, the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter can contain an IPv4 address in dotted-decimal notation. An example for a share might be the following:

`\\192.168.1.1\share`

For Microsoft network providers on Windows Vista and later, the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter can contain an IPv6 address. However, the IPv6 literal format must be used so that the IPv6 address is parsed correctly. An IPv6 literal address is of the form:

ipv6-address with the ':' characters replaced by '-' characters followed by the ".ipv6-literal.net" string.

For example, for the following IPv6 address:

`2001:4898:9:3:c069:aa97:fe76:2449`

an example for a share might be the following:

`\\2001-4898-9-3-c069-aa97-fe76-2449.ipv6-literal.net\share`

Other network providers may support the **lpRemoteName** member of the [NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew) structure pointed to by the *lpNetResource* parameter that contains an IPv4 or IPv6 address, but this is up to specific network provider.

**Windows 7 and Windows Server 2008 R2:** If the **WNetAddConnection3** function is called with explicit user credentials specified in the *pUsername* and *lpPassword* to establish a connection with a network resource on a specific server and then called again with either of these parameters as **NULL** (to use the default user name or default password) to the same server, the call with fail. The error returned will be **ERROR_BAD_USERNAME** or **ERROR_INVALID_PASSWORD**.

> [!NOTE]
> The winnetwk.h header defines WNetAddConnection3 as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[NETRESOURCE](https://learn.microsoft.com/windows/win32/api/winnetwk/ns-winnetwk-netresourcew)

[WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a)

[WNetCancelConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetcancelconnection2a)

[WNetGetConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetconnectiona)

[WNetUseConnection](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetuseconnectiona)

[Windows
Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows
Networking Functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions)