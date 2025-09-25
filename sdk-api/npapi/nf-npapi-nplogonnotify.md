# NPLogonNotify function

## Description

> [!NOTE]
> This API has been deprecated and will be removed in a future release.

MPR calls this function to notify the credential manager that a logon event has occurred, allowing the credential manager to return a logon script. The **NPLogonNotify** function is implemented by a credential manager DLL (see Remarks).

## Parameters

### `lpLogonId` [in]

Pointer to the identifier of the [session](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) that just logged on.

### `lpAuthentInfoType` [in]

Pointer to a string that identifies the type of structure pointed to by *lpAuthentInfo*.

When Microsoft is the primary authenticator, one of the following strings is specified for interactive and service controller logons.

``` syntax
MSV1_0:Interactive
Kerberos:Interactive

```

### `lpAuthentInfo` [in]

Pointer to a structure that contains the credentials used to successfully log the user on through the primary authenticator.

When Microsoft is the primary authenticator (that is, when *lpAuthentifoType* is "MSV1_0:Interactive" or "Kerberos:Interactive"), the structure used is
[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) or
[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon).

### `lpPreviousAuthentInfoType` [in]

Pointer to a string that identifies the type of structure pointed to by *lpPreviousAuthentInfo*. If the pointer is **NULL**, there was no previous information. The values that are expected here are the same as those in *lpAuthentInfoType*.

When Microsoft is the primary authenticator, the following string is specified for interactive and service controller logons.

```cpp
MSV1_0:Interactive

```

### `lpPreviousAuthentInfo` [in]

Pointer to a structure that contains the credentials used before the authentication information change. Prior information is provided if the user was forced to change the password (or other authentication information) before logging on. If the user was not forced to change authentication information, this pointer is **NULL**. The values that are expected here are the same as those in *lpAuthentInfo*.

When Microsoft is the primary authenticator, the structure used is
[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) or
[KERB_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_interactive_logon).

### `lpStationName` [in]

Pointer to a string that specifies the name of the station that the user has logged on to. The station name may be used to determine whether additional (provider-specific) information can be obtained.

When Microsoft is the primary authenticator, one of the following strings will be specified.

| Value | Meaning |
| --- | --- |
| **WinSta_0** | Indicates that this is an interactive logon through the window station. In this case, *StationHandle* is an **HWND** to the parent dialog box. |
| **SvcCtl** | Indicates that this is a logon initiated by the Service controller. *StationHandle* is not used in this case. |

### `StationHandle` [in]

A 32-bit value whose meaning is dependent upon the name (and consequently, the type) of the station specified in *lpStationName*.

| Value | Meaning |
| --- | --- |
| **WinSta_0** | A handle to the owner dialog box (hwndOwner) currently displayed on the screen. |
| **SvcCtl** | Random data. Do not use. |

### `lpLogonScript` [out]

Pointer to a location where a pointer to a **null**-terminated string may be returned.

After the function completes, this value may point to a **null**-terminated string that contains the name of a program to execute plus any parameters the program requires.
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) should be used to allocate the memory for the returned string. This memory will be freed by MPR when it is no longer needed.

## Return value

If the function succeeds, the function returns WN_SUCCESS.

If the function fails, it returns an error code, which can be one of the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_SUPPORTED** | [NPLogonNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nplogonnotify) is not supported by the credential manager. |
| **WN_NO_NETWORK** | The network is not present. |
| **WN_FUNCTION_BUSY** | The credential manager is still initializing and is not ready to be called. |

## Remarks

The **NPLogonNotify** function is implemented by credential managers to receive notifications when authentication information changes.

Each credential manager is allowed to return a single command-line string that can be used to execute a logon script (the implementation should not call [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) or load a user profile directly). The buffer of this string is allocated by the credential manager. MPR is responsible for freeing it. The string returned in *lpLogonScript* should contain all the information necessary to run the script as a command line passed to
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

If the string requires the command processor to process the string, as in the case of commands or batch files, then the string should be prefixed with **cmd /C**.

Logon scripts will be run in the user context when the user profile is available. However, environment variables that are set will not be global and will not be available to the initial shell (for example, Program Manager) or any other program run on behalf of the user.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon)

[NPGetCaps](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npgetcaps)

[NPPasswordChangeNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nppasswordchangenotify)