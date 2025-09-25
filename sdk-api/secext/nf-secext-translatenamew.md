# TranslateNameW function

## Description

Converts a directory service object name from one format to another.

## Parameters

### `lpAccountName` [in]

The name to be translated.

### `AccountNameFormat` [in]

The format of the name to be translated. This parameter is a value from the
[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format) enumeration type.

### `DesiredNameFormat` [in]

The format of the converted name. This parameter is a value from the
[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format) enumeration type. It cannot be NameUnknown.

### `lpTranslatedName` [out]

A pointer to a buffer that receives the converted name.

### `nSize` [in, out]

On input, the variable indicates the size of the *lpTranslatedName* buffer, in **TCHARs**. On output, the variable returns the size of the returned string, in **TCHARs**, including the terminating **null** character.

If *lpTranslated* is **NULL** and *nSize* is 0, the function succeeds and *nSize* receives the required buffer size.

If the *lpTranslatedName* buffer is too small to hold the converted name, the function fails and *nSize* receives the required buffer size.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**TranslateName** fails if it cannot bind to Active Directory on a domain controller.

> [!NOTE]
> The secext.h header defines TranslateName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Computer Names](https://learn.microsoft.com/windows/desktop/SysInfo/computer-names)

[DsCrackNames](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dscracknamesa)

[EXTENDED_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/secext/ne-secext-extended_name_format)

[System Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)