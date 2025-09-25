# PSAM_PASSWORD_FILTER_ROUTINE callback function

## Description

The **PasswordFilter** function is implemented by a [password filter](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) DLL. The value returned by this function determines whether the new password is accepted by the system. All of the password filters installed on a system must return **TRUE** for the password change to take effect.

## Parameters

### `AccountName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that represents the name of the user whose password changed.

### `FullName` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that represents the full name of the user whose password changed.

### `Password` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/subauth/ns-subauth-unicode_string) that represents the new plaintext password. When you have finished using the password, clear it from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information on protecting the password, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

### `SetOperation` [in]

**TRUE** if the password was set rather than changed.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | Return **TRUE** if the new password is valid with respect to the password policy implemented in the password filter DLL. When **TRUE** is returned, the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) continues to evaluate the password by calling any other password filters installed on the system. |
| **FALSE** | Return **FALSE** if the new password is not valid with respect to the password policy implemented in the password filter DLL. When **FALSE** is returned, the LSA returns the ERROR_ILL_FORMED_PASSWORD (1324) status code to the source of the password change request. |

## Remarks

Password change requests may be made when users specify a new password, accounts are created and when administrators override a password.

This function must use the __stdcall calling convention and must be exported by the DLL.

When the **PasswordFilter** routine is running, processing is blocked until the routine is finished. When appropriate, move any lengthy processing to a separate thread prior to returning from this routine.

This function is called only for [password filters](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that are installed and registered on a system.

Any process exception that is not handled within this function may cause security-related failures system-wide. Structured exception handling should be used when appropriate.

| For information about | See |
| --- | --- |
| Programming issues when implementing a password filter DLL | [Password Filter Programming Considerations](https://learn.microsoft.com/windows/desktop/SecMgmt/password-filter-programming-considerations) |
| How to install and register your own password filter DLL | [Installing and Registering a Password Filter DLL](https://learn.microsoft.com/windows/desktop/SecMgmt/installing-and-registering-a-password-filter-dll) |
| The password filter DLL provided by Microsoft | [Strong Password Enforcement and Passfilt.dll](https://learn.microsoft.com/windows/desktop/SecMgmt/strong-password-enforcement-and-passfilt-dll) |

## See also

[InitializeChangeNotify](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_init_notification_routine)

[PasswordChangeNotify](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_password_notification_routine)