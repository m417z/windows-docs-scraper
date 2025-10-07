# ConvertSystemTimeToCalDateTime function

Deprecated. Converts a specified [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime) structure to a [**CALDATETIME**](https://learn.microsoft.com/windows/win32/intl/caldatetime) structure.

## Parameters

*lpSysTime* \[in\]

Pointer to the [**SYSTEMTIME**](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-systemtime) structure to convert.

*calId* \[in\]

The system [calendar identifier](https://learn.microsoft.com/windows/win32/intl/calendar-identifiers) to use in the conversion.

*lpCalDateTime* \[out\]

Pointer to the equivalent [**CALDATETIME**](https://learn.microsoft.com/windows/win32/intl/caldatetime) structure.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

The earliest date supported by this function is January 1, 1601.

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

[Retrieving Time and Date Information](https://learn.microsoft.com/windows/win32/intl/time-and-date)

