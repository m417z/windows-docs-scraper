# RegDisablePredefinedCacheEx function

## Description

Disables handle caching for all predefined registry handles for the current process.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

This function does not work on a remote computer.

Services that change impersonation should call this function before using any of the predefined handles.

For example, any access of **HKEY_CURRENT_USER** after this function is called results in open and close operations being performed on **HKEY_USERS**\**SID_of_current_user**, or on **HKEY_USERS\.DEFAULT** if the current user's hive is not loaded. For more information on SIDs, see
[Security Identifiers](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers).

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[Predefined Keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)