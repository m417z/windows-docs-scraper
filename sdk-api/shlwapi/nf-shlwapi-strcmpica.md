# StrCmpICA function

## Description

Compares two strings using C run-time (ASCII) collation rules. The comparison is not case-sensitive.

## Parameters

### `pszStr1` [in]

Type: **LPCTSTR**

A pointer to the first null-terminated string to be compared.

### `pszStr2` [in]

Type: **LPCTSTR**

A pointer to the second null-terminated string to be compared.

## Return value

Type: **int**

Returns zero if the strings are identical. Returns a positive value if the string pointed to by *lpStr1* is alphabetically greater than that pointed to by *lpStr2*. Returns a negative value if the string pointed to by *lpStr1* is alphabetically less than that pointed to by *lpStr2*

## Remarks

It is strongly recommended that you use [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) in place of this function. **StrCmpIC** was designed for comparing canonical strings. These strings are not localized and consist only of characters below ASCII value 128. Therefore, it will not function correctly with double-byte character set (DBCS) data.

Uppercase characters are converted to lowercase characters before comparing, and the return value is based on comparing the converted values. This function returns the difference in value of the first unequal characters it encounters, or zero if they are all equal. For example, if *lpStr1*="abczb" and *lpStr2*="abcdefg", **StrCmpIC** determines that "abczb" is greater than "abcdefg" and returns z - d.

For those versions of Windows that do not include **StrCmpIC** in Shlwapi.h, this function's individual ANSI or Unicode version must be called directly from Shlwapi.dll. **StrCmpICA** is ordinal 157 and **StrCmpICW** is ordinal 158.

> [!NOTE]
> The shlwapi.h header defines StrCmpIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)