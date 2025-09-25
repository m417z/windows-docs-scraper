# GetComputerObjectNameA function

## Description

Retrieves the local computer's name in a specified format.

## Parameters

### `NameFormat` [in]

The format for the name. This parameter is a value from the
[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format) enumeration type. It cannot be NameUnknown.

### `lpNameBuffer` [out]

A pointer to a buffer that receives the name in the specified format.

If this parameter is **NULL**, either the function succeeds and the *lpnSize* parameter receives the required size, or the function fails with ERROR_INSUFFICIENT_BUFFER and *lpnSize* receives the required size. The behavior depends on the value of *NameFormat* and the version of the operating system.

### `nSize` [in, out]

On input, specifies the size of the *lpNameBuffer* buffer, in **TCHARs**. On success, receives the size of the name copied to the buffer. If the *lpNameBuffer* buffer is too small to hold the name, the function fails and *lpnSize* receives the required buffer size.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format)

[GetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getcomputernameexa)

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)

## Remarks

> [!NOTE]
> The secext.h header defines GetComputerObjectName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).