# StrChrNIW function

## Description

Searches a string for the first occurrence of a specified character. The comparison is not case-sensitive.

## Parameters

### `pszStart` [in]

Type: **PCWSTR**

A pointer to the string to be searched.

### `wMatch`

Type: **WCHAR**

The character to be used for comparison.

### `cchMax`

Type: **UINT**

The maximum number of characters to search.

## Return value

Type: **PWSTR**

Returns the address of the first occurrence of the character in the string if successful, or **NULL** otherwise.

## Remarks

**StrChrNIW** searches for *wMatch* from *pszStart* to *pszStart* + *cchMax*, or until a **NULL** character is encountered.

To help ensure optimal performance, *pszStart* should be word-aligned.

## See also

[StrChr](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strchra)

[StrChrI](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strchria)