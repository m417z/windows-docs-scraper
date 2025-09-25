# WlxLoggedOutSAS function

## Description

[The WlxLoggedOutSAS function is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **WlxLoggedOutSAS** function must be implemented by a replacement [GINA](https://learn.microsoft.com/windows/desktop/SecGloss/g-gly) DLL. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) calls this function when it receives a [secure attention sequence](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAS) event while no user is logged on.

**Note** GINA DLLs are ignored in Windows Vista.

## Parameters

### `pWlxContext` [in]

A pointer to the GINA context associated with this window station. The GINA returns this context value when Winlogon calls
[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize) for this station.

### `dwSasType` [in]

Specifies the type of SAS that occurred. Values from zero to WLX_SAS_TYPE_MAX_MSFT_VALUE are reserved to define standard Microsoft SAS types. GINA developers can define additional SAS types by using values greater than WLX_SAS_TYPE_MAX_MSFT_VALUE.

The following SAS types are predefined.

| Value | Meaning |
| --- | --- |
| **WLX_SAS_TYPE_CTRL_ALT_DEL** | Indicates that a user has typed the standard CTRL+ALT+DEL SAS. |
| **WLX_SAS_TYPE_SC_INSERT** | Indicates that a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) has been inserted into a compatible device. |
| **WLX_SAS_TYPE_SC_REMOVE** | Indicates that a smart card has been removed from a compatible device. |
| **WLX_SAS_TYPE_TIMEOUT** | Indicates that no user input was received within the specified time-out period. |

### `pAuthenticationId` [out]

Specifies the authentication identifier associated with the current [logon session](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly). You can get this value by calling [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) to obtain a [TOKEN_STATISTICS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_statistics) structure for the token returned by the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function.

### `pLogonSid` [in, out]

On input, this parameter points to a [security identifier](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SID) that is unique to the current logon session. [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) uses this SID to change the protection on the window station and application desktop so that the new logged-on user can access them.

On output, Winlogon provides a SID. You can also get the SID by using the [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function to retrieve a [TOKEN_GROUPS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-token_groups) structure for the token returned by the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function. To do this, search the array returned in the **TOKEN_GROUPS** structure for the group with the SE_GROUP_LOGON_ID attribute.

### `pdwOptions` [out]

A pointer to a **DWORD** that contains the set of logon options. The following option is defined.

| Value | Meaning |
| --- | --- |
| **WLX_LOGON_OPT_NO_PROFILE** | Indicates that Winlogon must not load a profile for the logged-on user. Either the GINA DLL will take care of this activity, or the user does not need a profile. |

### `phToken` [out]

A pointer to a handle variable. When the logon operation succeeds, set this handle to a token that represents the logged-on user. Use the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function to get this token, then, when the user logs off, Winlogon closes this handle and calls the
[WlxLogoff](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxlogoff) function.

If you need this handle after calling the [WlxLogoff](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxlogoff) function, make a duplicate of the handle before returning it to Winlogon.

### `pNprNotifyInfo` [out]

A pointer to an
[WLX_MPR_NOTIFY_INFO](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_mpr_notify_info) structure that contains domain, user name, and password information for the user. Winlogon will use this information to provide identification and authentication information to network providers.

The GINA is not required to return password information. Any **NULL** fields within the structure will be ignored by Winlogon. Use [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) to allocate each string; Winlogon will free them when they are no longer needed.

The GINA should provide domain, user, and password values for complete Session Directory functionality. If the password is not provided, Session Directory will require the user to input the password twice before the user is connected to the server.

For information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `pProfile` [out]

On return from a successful authentication, the *pProfile* parameter points to either a
[WLX_PROFILE_V1_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v1_0) or a
[WLX_PROFILE_V2_0](https://learn.microsoft.com/windows/desktop/api/winwlx/ns-winwlx-wlx_profile_v2_0) structure. The first **DWORD** in the structure indicates which structure it is. Winlogon uses this structure to load the profile of the logged-on user, and frees the memory associated with the structure when it no longer needs it.

## Return value

If the function fails, the function returns zero.

If the function succeeds, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **WLX_SAS_ACTION_LOGON** | Indicates a user has logged on. |
| **WLX_SAS_ACTION_NONE** | Indicates the logged attempt was unsuccessful or canceled. |
| **WLX_SAS_ACTION_SHUTDOWN** | Indicates the user requested that the system be shut down. |

## Remarks

Before calling **WlxLoggedOutSAS**, Winlogon sets the desktop state so that the current desktop is the Winlogon desktop and sets the workstation state so that the desktop is locked.

Do not activate the user shell program in **WlxLoggedOutSAS**. The user shell program should always be activated in
[WlxActivateUserShell](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxactivateusershell).

## See also

[WlxActivateUserShell](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxactivateusershell)

[WlxInitialize](https://learn.microsoft.com/windows/desktop/api/winwlx/nf-winwlx-wlxinitialize)