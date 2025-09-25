# StrCmpW function

## Description

Compares two strings to determine if they are the same. The comparison is case-sensitive.

## Parameters

### `psz1` [in]

Type: **PCTSTR**

A pointer to the first null-terminated string to be compared.

### `psz2` [in]

Type: **PCTSTR**

A pointer to the second null-terminated string to be compared.

## Return value

Type: **int**

Returns zero if the strings are identical. Returns a positive value if the string pointed to by *psz1* is greater than that pointed to by *psz2*. Returns a negative value if the string pointed to by *psz1* is less than that pointed to by *psz2*.