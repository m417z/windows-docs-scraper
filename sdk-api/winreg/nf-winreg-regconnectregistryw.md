# RegConnectRegistryW function

## Description

Establishes a connection to a predefined registry key on another computer.

## Parameters

### `lpMachineName` [in, optional]

The name of the remote computer. The string has the following form:

\\*computername*

The caller must have access to the remote computer or the function fails.

If this parameter is **NULL**, the local computer name is used.

### `hKey` [in]

A predefined registry handle. This parameter can be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys) on the remote computer.

**HKEY_LOCAL_MACHINE**
**HKEY_PERFORMANCE_DATA**
**HKEY_USERS**

### `phkResult` [out]

A pointer to a variable that receives a key handle identifying the predefined handle on the remote computer.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

**RegConnectRegistry** requires the Remote Registry service to be running on the remote computer. By default, this service is configured to be started manually. To configure the Remote Registry service to start automatically, run Services.msc and change the Startup Type of the service to Automatic.

**Windows Server 2003 and Windows XP/2000:** The Remote Registry service is configured to start automatically by default.

When a handle returned by
**RegConnectRegistry** is no longer needed, it should be closed by calling
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey).

If the computer is joined to a workgroup and the "Force network logons using local accounts to authenticate as Guest" policy is enabled, the function fails. Note that this policy is enabled by default if the computer is joined to a workgroup.

If the current user does not have proper access to the remote computer, the call to **RegConnectRegistry** fails. To connect to a remote registry, call [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) with LOGON32_LOGON_NEW_CREDENTIALS and [ImpersonateLoggedOnUser](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-impersonateloggedonuser) before calling **RegConnectRegistry**.

**Windows 2000:** One possible workaround is to establish a session to an administrative share such as IPC$ using a different set of credentials. To specify credentials other than those of the current user, use the [WNetAddConnection2](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetaddconnection2a) function to connect to the share. When you have finished accessing the registry, cancel the connection.

**Windows XP Home Edition:** You cannot use this function to connect to a remote computer running Windows XP Home Edition. This function does work with the name of the local computer even if it is running Windows XP Home Edition because this bypasses the authentication layer.

> [!NOTE]
> The winreg.h header defines RegConnectRegistry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)

[Registry Overview](https://learn.microsoft.com/windows/desktop/SysInfo/registry)