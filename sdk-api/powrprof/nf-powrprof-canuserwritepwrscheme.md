# CanUserWritePwrScheme function

## Description

[**CanUserWritePwrScheme** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Applications written for Windows Vista and later should use [PowerSettingAccessCheck](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-powersettingaccesscheck) instead.]

Determines whether the current user has sufficient privilege to write a power scheme.

## Return value

If the current user has sufficient privilege to write a power scheme, the function returns **TRUE**.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). Possible error values include the following.

| Error | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The current user does not have sufficient privilege to write a power scheme. |

## Remarks

This function is useful if your application is impersonating a user.

For more information on using PowrProf.h, see [Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes).

## See also

[Power Management Functions](https://learn.microsoft.com/windows/desktop/Power/power-management-functions)

[Power Schemes](https://learn.microsoft.com/windows/desktop/Power/power-schemes)

[WritePwrScheme](https://learn.microsoft.com/windows/desktop/api/powrprof/nf-powrprof-writepwrscheme)