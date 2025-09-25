# Msv1_0SubAuthenticationRoutineEx function

## Description

Performs [Remote Access Service](https://learn.microsoft.com/windows/desktop/RRAS/portal) authentication when subauthentication is requested by calling the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function.

The [security principal's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials and information from the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) database are passed to this function for authentication.

This function is implemented by custom subauthentication package DLLs for use with the MSV1_0 authentication package.

This function is called only for a
[noninteractive authentication](https://learn.microsoft.com/windows/desktop/SecAuthN/noninteractive-authentication), only on the authenticating server where the account resides, and only if a subauthentication DLL is registered under the correct key in the registry.

## Parameters

### `LogonLevel` [in]

Specifies the level of information given in the *LogonInformation* parameter. This parameter is normally set to NetlogonInteractiveInformation.

### `LogonInformation` [in]

A pointer to a
[NETLOGON_LOGON_IDENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-netlogon_logon_identity_info) structure. Members of this structure contain information about the user who is logging on. The **LogonDomainName** member of this structure is ignored.

### `Flags` [in]

Optional. Contains flags that describe the circumstances of the logon. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MSV1_0_PASSTHRU** | Pass-through authentication. The user is not connecting to this computer. |
| **MSV1_0_GUEST_LOGON** | This is a retry of the logon using the GUEST user account. |

### `UserAll` [in]

A pointer to a
[USER_ALL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-user_all_information) structure that contains the description of the user as returned from the SAM database.

### `UserHandle` [in]

A handle to the user account.

### `ValidationInfo` [in, out]

A pointer to a MSV1_0_VALIDATION_INFO structure.

### `ActionsPerformed` [out]

The list of actions performed.

## Return value

This function must return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | There was no error. |
| **STATUS_ACCOUNT_DISABLED** | The account is disabled. |
| **STATUS_ACCOUNT_EXPIRED** | The account has expired. |
| **STATUS_ACCOUNT_LOCKED_OUT** | The account is locked out. |
| **STATUS_INVALID_INFO_CLASS** | *LogonLevel* is not valid. |
| **STATUS_INVALID_WORKSTATION** | The user is not authorized to log on to the specified workstation. |
| **STATUS_NO_SUCH_USER** | The specified user has no account. |
| **STATUS_PASSWORD_EXPIRED** | The password is expired. |
| **STATUS_PASSWORD_MUST_CHANGE** | The account is marked to indicate that the password must be changed on the next logon. |
| **STATUS_WRONG_PASSWORD** | The password was not valid. |