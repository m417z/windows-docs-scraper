# QueryFullProcessImageNameA function

## Description

Retrieves the full name of the executable image for the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must be created with the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `dwFlags` [in]

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The name should use the Win32 path format. |
| **PROCESS_NAME_NATIVE**<br><br>0x00000001 | The name should use the native system path format. |

### `lpExeName` [out]

The path to the executable image. If the function succeeds, this string is null-terminated.

### `lpdwSize` [in, out]

On input, specifies the size of the *lpExeName* buffer, in characters. On success, receives the number of characters written to the buffer, not including the null-terminating character.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later.

> [!NOTE]
> The winbase.h header defines QueryFullProcessImageName as an alias which automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetModuleFileNameEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getmodulefilenameexa)

[GetProcessImageFileName](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getprocessimagefilenamea)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)