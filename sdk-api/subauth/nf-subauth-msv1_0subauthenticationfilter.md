# Msv1_0SubAuthenticationFilter function

## Description

The **Msv1_0SubAuthenticationFilter** function performs user logon authentication that is specific to domain controllers.

The function receives the user's logon data and all information found for the user in the domain controller's [Security Accounts Manager](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (SAM) database.

This function is implemented by custom subauthentication package DLLs for use with the Kerberos and MSV1_0 authentication packages.

## Parameters

### `LogonLevel` [in]

Specifies the level of information given in *LogonInformation*. This parameter is normally set to NetlogonInteractiveInformation.

### `LogonInformation` [in]

A pointer to a
[NETLOGON_LOGON_IDENTITY_INFO](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-netlogon_logon_identity_info) structure. Members of this structure contain information about the user who is logging on. The **LogonDomainName** member is ignored.

### `Flags` [in]

Optional. Contains flags that describe the circumstances of the logon. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MSV1_0_PASSTHRU** | Pass-through authentication. The user is not connecting to this machine. |
| **MSV1_0_GUEST_LOGON** | This is a retry of the logon using the Guest account. |

### `UserAll` [in]

A pointer to a
[USER_ALL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-user_all_information) structure that contains the description of the user as returned from the SAM database.

### `WhichFields` [out]

Returns the members of the [USER_ALL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-user_all_information) structure that need to be written back to the SAM database. These members will be written only if **Msv1_0SubAuthenticationFilter** returns success. Only the following value is valid.

| Value | Meaning |
| --- | --- |
| **USER_ALL_PARAMETERS** | Write the data contained in the **Parameters** member of the *UserAll* structure back to the SAM database.<br><br>If the size of the **Parameters** member's [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) buffer is changed, **Msv1_0SubAuthenticationFilter** must delete the buffer by using the [MIDL_user_free](https://learn.microsoft.com/windows/desktop/Midl/midl-user-free-1) function and reallocate it by using the [MIDL_user_allocate](https://msdn.microsoft.com/) function. |

### `UserFlags` [out]

Values to be returned from the
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) function in that function's *ProfileBuffer* parameter. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LOGON_GUEST** | This was a guest logon. |
| **LOGON_NOENCRYPTION** | The caller did not specify encrypted credentials. |

**Note** By convention, subauthentication packages return bits only in the high order byte of the *UserFlags* parameter.

### `Authoritative` [out]

A pointer to a Boolean value that indicates whether the status returned is an authoritative status that should be returned to the original caller. If the value returned is **FALSE**, the logon request can be tried again on another domain controller. This parameter should return valid information regardless of the return value of the function call. This parameter is not used with the Kerberos authentication package.

### `LogoffTime` [out]

A pointer to a value that receives the time at which the user should log off the system. This time is used to control the logon lifetime and is specified as a GMT-relative Windows system time.

### `KickoffTime` [out]

A pointer to a value that receives the time at which the user should be logged off the system. This time is used to control the logon lifetime and is specified as a GMT-relative system time. If the user is not to be automatically logged off, specify a large positive value, as follows:

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
| **STATUS_PASSWORD_MUST_CHANGE** | The password must change on next logon. |
| **STATUS_WRONG_PASSWORD** | The password was not valid. |

When the **Msv1_0SubAuthenticationFilter** function is used with the Kerberos authentication package, if the function call returns STATUS_SUCCESS and one of the two parameters *LogoffTime* or *KickoffTime* has a nonzero value, this value is used as the ticket lifetime. If, on the other hand, the values of both parameters are nonzero, the smaller of these two values is used.

If the value that is used for the ticket lifetime (the sooner of *LogoffTime* and *KickoffTime*) is greater than the default ticket lifetime, then that value will be used as the maximum renewal time for the ticket. Conversely, if the larger of the two values (the later of *LogoffTime* and *KickoffTime*) is less than the default ticket lifetime, this value will be used as the ticket lifetime. For more information, see
[Microsoft Kerberos](https://learn.microsoft.com/windows/desktop/SecAuthN/microsoft-kerberos).

When used with the Kerberos authentication package, if this function returns an error, the [Key Distribution Center](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KDC) will return the Kerberos error KDC_ERR_POLICY, with the status value as the extended error code.

## Remarks

Implementations of this function should not execute any operations that cause [Lightweight Directory Access Protocol](https://learn.microsoft.com/previous-versions/windows/desktop/ldap/lightweight-directory-access-protocol-ldap-api) (LDAP) traffic. For example, do not connect to and query the [Active Directory](https://learn.microsoft.com/windows/desktop/AD/active-directory-domain-services) database.

After the MSV1_0 or Kerberos authentication package has validated a logon, the **Msv1_0SubAuthenticationFilter** function can perform additional validation to determine whether a user can log on to a network account. This function is called if the subauthentication package DLL is properly registered as 'Auth0' in the domain controller's registry. The registry path is different depending on whether the function is in a MSV1_0 or Kerberos Subauthentication package DLL.

This filter routine may return STATUS_SUCCESS, which indicates that the logon should proceed, or a failure code, which indicates that the additional validation failed.