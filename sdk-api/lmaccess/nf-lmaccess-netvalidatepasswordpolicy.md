# NetValidatePasswordPolicy function

## Description

The **NetValidatePasswordPolicy** function allows an application to check password compliance against an application-provided account database and verify that passwords meet the complexity, aging, minimum length, and history reuse requirements of a password policy.

## Parameters

### `ServerName` [in]

A pointer to a constant Unicode string specifying the name of the remote server on which the function is to execute. This string must
begin with \\ followed by the remote server name. If this parameter is **NULL**, the local computer is used.

### `Qualifier` [in]

Reserved for future use. This parameter must be **NULL**.

### `ValidationType` [in]

The type of password validation to perform. This parameter must be one of the following enumerated constant values.

```cpp
typedef enum _NET_VALIDATE_PASSWORD_TYPE {

    NetValidateAuthentication = 1,
    NetValidatePasswordChange,
    NetValidatePasswordReset,

} NET_VALIDATE_PASSWORD_TYPE, *PNET_VALIDATE_PASSWORD_TYPE;

```

These values have the following meanings.

| Value | Meaning |
| --- | --- |
| **NetValidateAuthentication** | The application is requesting password validation during authentication. The *InputArg* parameter points to a [NET_VALIDATE_AUTHENTICATION_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_authentication_input_arg) structure. This type of validation enforces password expiration and account lockout policy. |
| **NetValidatePasswordChange** | The application is requesting password validation during a password change operation. The *InputArg* parameter points to a [NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg) structure. |
| **NetValidatePasswordReset** | The application is requesting password validation during a password reset operation. The *InputArg* parameter points to a [NET_VALIDATE_PASSWORD_RESET_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_reset_input_arg) structure. You can also reset the "lockout state" of a user account by specifying this structure. |

### `InputArg` [in]

A pointer to a structure that depends on the type of password validation to perform. The type of structure depends on the value of the *ValidationType* parameter. For more information, see the description of the *ValidationType* parameter.

### `OutputArg` [out]

If the **NetValidatePasswordPolicy** function succeeds (the return value is **Nerr_Success**), then the function
allocates a buffer that contains the results of
the operation. The *OutputArg* parameter contains a pointer to a [NET_VALIDATE_OUTPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_output_arg) structure. The application must examine **ValidationStatus** member in the **NET_VALIDATE_OUTPUT_ARG** structure pointed to by the *OutputArg* parameter to
determine the results of the password policy validation check. The **NET_VALIDATE_OUTPUT_ARG** structure contains a [NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields) structure with changes to persistent password-related information, and the results of the password validation. The application must
plan to persist all persisted the fields in the **NET_VALIDATE_PERSISTED_FIELDS** structure aside from the **ValidationStatus** member as information along with the user object information and provide the required fields from
the persisted information when calling this function in the future on the same user object.

If the **NetValidatePasswordPolicy** function fails (the return value is nonzero), then *OutputArg* parameter is set to a **NULL** pointer and password policy
could not be examined.

For more information, see the Return Values and Remarks sections.

## Return value

If the function succeeds, and the password is authenticated, changed, or reset, the return value is NERR_Success and the function allocates an *OutputArg* parameter.

If the function fails, the *OutputArg* parameter is **NULL** and the return value is a system error code that can be one of the following error codes. For a list of all possible error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *InputArg* or *OutputArg* parameters are **NULL**. This error is also returned if the *Qualifier* parameter is not **NULL** or if the *ValidationType* parameter is not one of the allowed values. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to complete the operation. |

## Remarks

The **NetValidatePasswordPolicy** function is designed to allow applications to validate passwords for users that are in an account database provided by the application. This function can also be used to verify that passwords meet the complexity, aging, minimum length, and history reuse requirements of a password policy. This function also provides the means for an application to implement an account-lockout mechanism.

The **NetValidatePasswordPolicy** function does not validate passwords in Active Directory accounts and cannot be used for this purpose.
The only policy that this function checks a password against in Active Directory accounts is the password complexity (the password strength).

A typical scenario for the use of the **NetValidatePasswordPolicy** function would be enforcing the choice of strong passwords by users for web applications and applications that allow password-protected documents. Another use of this function could be checking password complexity in a situation in which a password is attached to a functional operation rather than to a user account; for example, passwords that are used with Secure Multipurpose Internet Mail Extensions (S/MIME) certificate-based public keys.

If the **NetValidatePasswordPolicy** function is called on a domain controller that is running Active Directory, access is allowed or denied based on the ACL for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Domain object is used to perform the access check for the **NetValidatePasswordPolicy** function.

To call **NetValidatePasswordPolicy** in a security context that is not the default, first call the [LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera) function, specifying LOGON32_LOGON_NEW_CREDENTIALS in the *dwLogonType* parameter, and then call **NetValidatePasswordPolicy** under impersonation. For more information about impersonation, see [Client Impersonation](https://learn.microsoft.com/windows/desktop/SecAuthZ/client-impersonation).

If the return code of the **NetValidatePasswordPolicy** function is **Nerr_Success** then the function
allocates a buffer pointed to by the *OutputArg* parameter that contains a [NET_VALIDATE_OUTPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_output_arg) structure with the results of
the operation. The application must examine **ValidationStatus** member in the **NET_VALIDATE_OUTPUT_ARG** structure to
determine the results of the password policy validation check. For more information, see **NET_VALIDATE_OUTPUT_ARG**.

Note that it is the application's responsibility to save all the data in the **ChangedPersistedFields** member of the **NET_VALIDATE_OUTPUT_ARG** structure as well as any User object information. The next time the application calls **NetValidatePasswordPolicy** on the same instance of the User object, the application must provide the required fields from the persistent information.

When you call **NetValidatePasswordPolicy** and specify [NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg) or [NET_VALIDATE_PASSWORD_RESET_INPUT_ARG](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_password_reset_input_arg) in *InputArg* parameter, the call also validates the password by passing it through the password filter DLL that the computer is configured to use. For more information about password filters, see [Using Password Filters](https://learn.microsoft.com/windows/desktop/SecMgmt/using-password-filters).

If the return value from the **NetValidatePasswordPolicy** function is nonzero then *OutputArg* parameter is set to **NULL** and password policy
could not be examined.

The [NetValidatePasswordPolicyFree](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicyfree) function should be called after calling **NetValidatePasswordPolicy** to free the memory allocated for the *OutputArg* parameter that is returned by the call to the **NetValidatePasswordPolicy** function.

## See also

[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera)

[NET_VALIDATE_AUTHENTICATION_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_authentication_input_arg)

**NET_VALIDATE_OUTPUT_ARG**

[NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_change_input_arg)

[NET_VALIDATE_PASSWORD_RESET_INPUT_ARG](https://learn.microsoft.com/windows/win32/api/lmaccess/ns-lmaccess-net_validate_password_reset_input_arg)

[NET_VALIDATE_PERSISTED_FIELDS](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-net_validate_persisted_fields)

[NetValidatePasswordPolicyFree](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netvalidatepasswordpolicyfree)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)