# StrCmpCA function

## Description

Compares strings using C run-time (ASCII) collation rules. The comparison is case-sensitive.

## Parameters

### `pszStr1` [out]

Type: **LPCSTR**

A pointer to the first null-terminated string to be compared.

### `pszStr2` [out]

Type: **LPCSTR**

A pointer to the second null-terminated string to be compared.

## Return value

Type: **int**

Returns zero if the strings are identical. Returns a positive value if the string pointed to by *lpStr1* is alphabetically greater than that pointed to by *lpStr2*. Returns a negative value if the string pointed to by *lpStr1* is alphabetically less than that pointed to by *lpStr2*.

## Remarks

It is strongly recommended that you use the [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) function in place of this function. **StrCmpC** was designed for comparing canonical strings. These strings are not localized and consist only of characters below ASCII value 128. Therefore, it will not function correctly with a double-byte character set (DBCS) or other multiple-character data.

This function locates the first unequal characters and returns a positive number if the character from the first string is greater than the character from the second, a negative number if it is less, or zero if they are equal. For example, if *lpStr1*="abczb" and *lpStr2*="abcdefg", **StrCmpC** determines that the first unequal character is at position four ("z" in *lpStr1* and "d" in *lpStr2*) and returns a positive value since the ASCII code for "z" is greater than the ASCII code for "d".

For those versions of Windows that do not include **StrCmpC** in Shlwapi.h, this function's individual ANSI or Unicode version must be called directly from Shlwapi.dll. **StrCmpCA** is ordinal 155 and **StrCmpCW** is ordinal 156.

> [!NOTE]
> The shlwapi.h header defines StrCmpC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw)