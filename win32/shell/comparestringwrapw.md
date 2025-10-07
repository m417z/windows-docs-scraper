# CompareStringWrapW function

\[**CompareStringWrapW** is available for use in Windows XP. It will not be available in subsequent versions. You should use [**CompareStringW**](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringw) in its place.\]

Compares two Unicode character strings, using a specified locale.

> [!Note]
> **CompareStringWrapW** is a wrapper for the **CompareStringW** function. See the [**CompareString**](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringw) page for further usage notes.

## Parameters

*Locale* \[in\]

Type: **LCID**

A locale identifier used for the comparison. This parameter can be one of the following predefined locale identifiers or a locale identifier created by the [**MAKELCID**](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelcid) macro.

**LOCALE\_SYSTEM\_DEFAULT**

The system's default locale.

**LOCALE\_USER\_DEFAULT**

The current user's default locale.

*dwCmpFlags* \[in\]

Type: **DWORD**

The flags that indicate how the function compares the two strings. By default, these flags are not set. Set to zero to get the default behavior or to any combination of the following values.

**NORM\_IGNORECASE**

Ignore case.

**NORM\_IGNOREKANATYPE**

Do not differentiate between Hiragana and Katakana characters. Corresponding Hiragana and Katakana characters compare as equal.

**NORM\_IGNORENONSPACE**

Ignore nonspacing characters.

**NORM\_IGNORESYMBOLS**

Ignore symbols.

**NORM\_IGNOREWIDTH**

Do not differentiate between a single-byte character and the same character as a double-byte character.

**SORT\_STRINGSORT**

Treat punctuation the same as symbols.

*lpString1* \[in\]

Type: **LPCWSTR**

A pointer to the first Unicode string to be compared.

*cchCount1* \[in\]

Type: **int**

The number of characters in the string pointed to by the *lpString1* parameter. The count does not include the terminating null character. If this parameter is a negative value, the string is assumed to be null-terminated and the length is calculated automatically.

*lpString2* \[in\]

Type: **LPCWSTR**

A pointer to the second Unicode string to be compared.

*cchCount2* \[in\]

Type: **int**

The number of characters in the string pointed to by the *lpString2* parameter. The count does not include the terminating null character. If this parameter is a negative value, the string is assumed to be null-terminated and the length is calculated automatically.

## Return value

Type: **int**

If the function fails, the return value is zero. To get extended error information, call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). **GetLastError** may return one of the following error codes.

- ERROR\_INVALID\_FLAGS
- ERROR\_INVALID\_PARAMETER

If the function succeeds, the return value is one of the following values.

| Requirement | Value |
|---------------------|--------------------------------------------------------------------------------------------------------------------------------------|
| CSTR\_LESS\_THAN | The string pointed to by the *lpString1* parameter is less in lexical value than the string pointed to by the *lpString2* parameter. |
| CSTR\_EQUAL | The string pointed to by *lpString1* is equal in lexical value to the string pointed to by *lpString2*. |
| CSTR\_GREATER\_THAN | The string pointed to by *lpString1* is greater in lexical value than the string pointed to by *lpString2* |

## Remarks

**Security Warning:** Using this function incorrectly can compromise the security of your application. Strings that are not compared correctly can produce invalid input. Test strings to make sure they are valid before using them and provide error handlers. For more information, see [Security Considerations: International Features](https://learn.microsoft.com/windows/win32/intl/security-considerations--international-features)

The preferred method is to use [**CompareStringW**](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringw) in conjunction with the Microsoft Layer for Unicode (MSLU).

**CompareStringWrapW** must be called directly from Shlwapi.dll, using ordinal 45.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional, Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | None |
| DLL<br> | Shlwapi.dll (version 5.0 or later) |

## See also

[**CompareString**](https://learn.microsoft.com/windows/win32/api/stringapiset/nf-stringapiset-comparestringw)

