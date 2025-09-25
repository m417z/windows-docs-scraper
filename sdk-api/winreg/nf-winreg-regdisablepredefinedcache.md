# RegDisablePredefinedCache function

## Description

Disables handle caching of the predefined registry handle for **HKEY_CURRENT_USER** for the current process. This function does not work on a remote computer.

To disables handle caching of all predefined registry handles, use the [RegDisablePredefinedCacheEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablepredefinedcacheex) function.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

Any access of **HKEY_CURRENT_USER** after this function is called will result in operations being performed on **HKEY_USERS**\**SID_of_current_user**, or on **HKEY_USERS\.DEFAULT** if the current user's hive is not loaded. For more information on SIDs, see
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[Predefined Keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys)

[RegDisablePredefinedCacheEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdisablepredefinedcacheex)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)