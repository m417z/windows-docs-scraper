# AdjustCalendarDate function

Deprecated. Adjusts a date by a specified number of years, months, weeks, or days.

## Parameters

*lpCalDateTime* \[in, out\]

Pointer to a [**CALDATETIME**](https://learn.microsoft.com/windows/win32/intl/caldatetime) structure that contains the date and calendar information to adjust.

*calUnit* \[in\]

The [**CALDATETIME\_DATEUNIT**](https://learn.microsoft.com/windows/win32/intl/caldatetime-dateunit) enumeration value indicating the date unit, for example, DayUnit.

*amount* \[out\]

The amount by which to adjust the specified date.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_DATE\_OUT\_OF\_RANGE. The specified date was out of range.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function does not have an associated header file or library file. The application can call [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) with the DLL name (Kernel32.dll) to obtain a module handle. It can then call [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) with the module handle and the name of this function to get the function address.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Kernel32.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/win32/intl/nls--name-based-apis-sample)

