# IntlStrEqWorkerW function

## Description

Compares a specified number of characters from the beginning of two localized strings.

## Parameters

### `fCaseSens` [in]

Type: **BOOL**

A value that is set to **TRUE** for a case-sensitive comparison, or to **FALSE** for a case-insensitive comparison.

### `lpString1` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string.

### `lpString2` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string.

### `nChar` [in]

Type: **int**

The number of characters to be compared, starting from the beginning of the strings.

## Return value

Type: **BOOL**

Returns **TRUE** if the first *nChar* characters are identical, or **FALSE** otherwise.

## Remarks

This function retrieves the thread locale and uses [CompareString](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-comparestringw) to determine whether the first *nChar* characters are identical.