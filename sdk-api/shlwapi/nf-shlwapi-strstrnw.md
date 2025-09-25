# StrStrNW function

## Description

Finds the first occurrence of a substring within a string. The comparison is case-sensitive.

## Parameters

### `pszFirst` [in]

Type: **PWSTR**

A pointer to the null-terminated, Unicode string that is being searched.

### `pszSrch` [in]

Type: **PCWSTR**

A pointer to the null-terminated, Unicode substring that is being searched for.

### `cchMax`

Type: **UINT**

The maximum number of characters from the beginning of the searched string in which to search for the substring.

## Return value

Type: **PWSTR**

Returns the address of the first occurrence of the matching substring if successful, or **NULL** otherwise.