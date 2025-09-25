# StrCmpNICW function

## Description

Compares a specified number of characters from the beginning of two strings using C run-time (ASCII) collation rules. The comparison is not case-sensitive.

## Parameters

### `pszStr1` [in]

Type: **LPCTSTR**

A pointer to the first null-terminated string to be compared.

### `pszStr2` [in]

Type: **LPCTSTR**

A pointer to the second null-terminated string to be compared.

### `nChar`

Type: **int**

The number of characters from the beginning of each string to be compared.

## Return value

Type: **int**

Returns zero if the substrings are identical. Returns a positive value if the string taken from that pointed to by *pszStr1* is alphabetically greater the string taken from that pointed to by *pszStr2*. Returns a negative value if the string taken from that pointed to by *pszStr1* is alphabetically less than the string taken from that pointed to by *pszStr2*.

## Remarks

Note that **StrCmpNIC** was designed for comparing canonical strings. These strings are not localized and consist only of characters below ASCII value 128. Therefore, it will not function correctly with a double-byte character set (DBCS) or other multiple-character data.

This function locates the first unequal characters and returns a positive number if the character from the first string is greater than the character from the second, a negative number if it is less, or zero if they are equal. For example, suppose that *pszStr1*="abczb", *pszStr2*="abcdefg", and you are comparing the first four characters from each. **StrCmpNIC** determines that the first unequal character is at position four ("z" in *pszStr1* and "d" in *pszStr2*) and returns a positive value since the ASCII code for "z" is greater than the ASCII code for "d".

For those versions of Windows that do not include **StrCmpNIC** in Shlwapi.h, this function's individual ANSI or Unicode version must be called directly from Shlwapi.dll. **StrCmpNICA** is ordinal 153 and **StrCmpNICW** is ordinal 154.

> [!NOTE]
> The shlwapi.h header defines StrCmpNIC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)

[StrCmpIC](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpica)

[StrCmpNI](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpnia)