# PSAM_INIT_NOTIFICATION_ROUTINE callback function

## Description

The **InitializeChangeNotify** function is implemented by a password filter DLL. This function initializes the DLL.

## Parameters

### `unnamedParam1`

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The password filter DLL is initialized. |
| **FALSE** | The password filter DLL is not initialized. |

## Remarks

**InitializeChangeNotify** is called by the [Local Security Authority](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) (LSA) to verify that the password notification DLL is loaded and initialized.

This function must use the __stdcall calling convention, and must be exported by the DLL.

This function is called only for password filters that are installed and registered on a system.

Any process exception that is not handled within this function may cause security-related failures system-wide. Structured exception handling should be used when appropriate.

| For information about | See |
| --- | --- |
| Programming issues when implementing a password filter DLL | [Password Filter Programming Considerations](https://learn.microsoft.com/windows/desktop/SecMgmt/password-filter-programming-considerations) |
| How to install and register your own password filter DLL | [Installing and Registering a Password Filter DLL](https://learn.microsoft.com/windows/desktop/SecMgmt/installing-and-registering-a-password-filter-dll) |
| The password filter DLL provided by Microsoft | [Strong Password Enforcement and Passfilt.dll](https://learn.microsoft.com/windows/desktop/SecMgmt/strong-password-enforcement-and-passfilt-dll) |

## See also

[PasswordChangeNotify](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_password_notification_routine)

[PasswordFilter](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nc-ntsecapi-psam_password_filter_routine)