# PSAM_PASSWORD_NOTIFICATION_ROUTINE callback function

## Description

The **PasswordChangeNotify** function is implemented by a [password filter](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) DLL. It notifies the DLL that a password was changed.

## Parameters

### `UserName` [in]

The account name of the user whose password changed.

If the values of this parameter and the *NewPassword* parameter are **NULL**, this function should return **STATUS_SUCCESS**.

### `RelativeId` [in]

The [relative identifier](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) (RID) of the user specified in *UserName*.

### `NewPassword` [in]

A new plaintext password for the user specified in *UserName*. When you have finished using the password, clear the information by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

If the values of this parameter and the *UserName* parameter are **NULL**, this function should return **STATUS_SUCCESS**.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates the password of the user was changed, or that the values of both the *UserName* and *NewPassword* parameters are **NULL**. |

## Remarks

The **PasswordChangeNotify** function is called after the [PasswordFilter](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_password_filter_routine) function has been called successfully and the new password has been stored.

This function must use the __stdcall calling convention and must be exported by the DLL.

When the **PasswordChangeNotify** routine is running, processing is blocked until the routine is finished. When appropriate, move any lengthy processing to a separate thread prior to returning from this routine.

This function is called only for [password filters](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) that are installed and registered on the system.

Any process exception that is not handled within this function may cause security-related failures system-wide. Structured exception handling should be used when appropriate.

| For information about | See |
| --- | --- |
| Programming issues when implementing a password filter DLL | [Password Filter Programming Considerations](https://learn.microsoft.com/windows/desktop/SecMgmt/password-filter-programming-considerations) |
| How to install and register your own password filter DLL | [Installing and Registering a Password Filter DLL](https://learn.microsoft.com/windows/desktop/SecMgmt/installing-and-registering-a-password-filter-dll) |
| The password filter DLL provided by Microsoft | [Strong Password Enforcement and Passfilt.dll](https://learn.microsoft.com/windows/desktop/SecMgmt/strong-password-enforcement-and-passfilt-dll) |

## See also

[InitializeChangeNotify](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_init_notification_routine)

[PasswordFilter](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_password_filter_routine)