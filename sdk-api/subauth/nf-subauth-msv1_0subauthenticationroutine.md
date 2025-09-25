# Msv1_0SubAuthenticationRoutine function

## Description

The **Msv1_0SubAuthenticationRoutine** function performs client/server-specific authentication.

The [security principal's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) credentials and information from the [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) database are passed to this function for authentication.

This function is implemented by custom subauthentication package DLLs for use with the MSV1_0 authentication package.

The **Msv1_0SubAuthenticationRoutine** function is called only for a
[noninteractive authentication](https://learn.microsoft.com/windows/desktop/SecAuthN/noninteractive-authentication), only on the authenticating server where the account resides, and only if a subauthentication DLL is registered under the correct key in the registry.

**Note** The Kerberos authentication package does not call this routine.

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
| **MSV1_0_PASSTHRU** | Pass-through authentication. The user is not connecting to this machine. |
| **MSV1_0_GUEST_LOGON** | This is a retry of the logon using the GUEST user account. |

### `UserAll` [in]

A pointer to a
[USER_ALL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-user_all_information) structure that contains the description of the user as returned from the SAM database.

### `WhichFields` [out]

Returns the members of the [USER_ALL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-user_all_information) structure that need to be written back to the SAM database. These members will be written only if **Msv1_0SubAuthenticationRoutine** returns success to the caller. Only the following value is valid.

| Value | Meaning |
| --- | --- |
| **USER_ALL_PARAMETERS** | Write the data contained in the **Parameters** member of the *UserAll* structure back to the SAM database.<br><br>If the size of the **Parameters** member's UNICODE_STRING buffer is changed, **Msv1_0SubAuthenticationRoutine** must delete the buffer by using the [MIDL_user_free](https://learn.microsoft.com/windows/desktop/Midl/midl-user-free-1) function and reallocate it by using the [MIDL_user_allocate](https://msdn.microsoft.com/) function. |

### `UserFlags` [out]

Values to be returned from the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function's *ProfileBuffer* parameter, when it contains a
[MSV1_0_LM20_LOGON_PROFILE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon_profile) structure. The following values are currently defined for the **UserFlags** member of the structure.

| Value | Meaning |
| --- | --- |
| **LOGON_GUEST** | This is a guest logon. |
| **LOGON_NOENCRYPTION** | The caller did not specify encrypted credentials. |

**Note** By convention, subauthentication packages return bits in only the high order byte of *UserFlags*; however, this convention is not enforced.

### `Authoritative` [out]

A pointer to a Boolean value that indicates whether the status returned is an authoritative status that should be returned to the original caller. If the returned value is **FALSE**, the logon request can be tried again on another domain controller. This parameter should return valid information regardless of the return value of the function call.

### `LogoffTime` [out]

A pointer to a value that receives the time at which the user should log off the system. This time is used to control the logon lifetime and is specified as a GMT-relative system time.

### `KickoffTime` [out]

A pointer to a value that receives the time at which the user should be logged off the system. This time is used to control the logon lifetime and is specified as a GMT-relative system time. If the user is not to be logged off, specify a large positive value, such as:

```cpp
KickoffTime->HighPart = 0x7FFFFFFF;
KickoffTime->LowPart = 0xFFFFFFFF;

```

## Return value

This function must return one of the following values.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | There was no error. |
| **STATUS_ACCOUNT_DISABLED** | The account is disabled. |
| **STATUS_ACCOUNT_EXPIRED** | The account has expired. |
| **STATUS_ACCOUNT_LOCKED_OUT** | The account is locked out. |
| **STATUS_INVALID_INFO_CLASS** | *LogonLevel* is not valid. |
| **STATUS_INVALID_LOGON_HOURS** | The user is not authorized to log on at this time. |
| **STATUS_INVALID_WORKSTATION** | The user is not authorized to log on to the specified workstation. |
| **STATUS_NO_SUCH_USER** | The specified user has no account. |
| **STATUS_PASSWORD_EXPIRED** | The password is expired. |
| **STATUS_PASSWORD_MUST_CHANGE** | The account is marked to indicate that the password must be changed on the next logon. |
| **STATUS_WRONG_PASSWORD** | The password was not valid. |

## Remarks

This function is called by the MSV1_0 authentication package if part of the *AuthenticationInformation* parameter indicates that subauthentication is to be done and if a subauthentication DLL that exports the **Msv1_0SubAuthenticationRoutine** function is correctly registered on the workstation.

The MSV1_0 authentication package does not support subauthentication for interactive logons, which require the
[MSV1_0_INTERACTIVE_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_interactive_logon) structure. Network logons, which require the
[MSV1_0_LM20_LOGON](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-msv1_0_lm20_logon) structure, can use subauthentication.

The **Msv1_0SubAuthenticationRoutine** function is called after the correct domain controller has been located and all information about the security principal to be authenticated has been retrieved from the SAM database. When subauthentication is used, authentication is the responsibility of the subauthentication DLL and must be done by the **Msv1_0SubAuthenticationRoutine** function exported by that DLL.