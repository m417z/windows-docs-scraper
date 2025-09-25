# StrCmpLogicalW function

## Description

Compares two Unicode strings. Digits in the strings are considered as numerical content rather than text. This test is not case-sensitive.

## Parameters

### `psz1` [in]

Type: **PCWSTR**

A pointer to the first null-terminated string to be compared.

### `psz2` [in]

Type: **PCWSTR**

A pointer to the second null-terminated string to be compared.

## Return value

Type: **int**

* Returns zero if the strings are identical.
* Returns 1 if the string pointed to by *psz1* has a greater value than that pointed to by *psz2*.
* Returns -1 if the string pointed to by *psz1* has a lesser value than that pointed to by *psz2*.

## Remarks

This function's ordering schema differs somewhat from [StrCmpI](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-strcmpiw), which also compares strings without regard to case sensitivity. Considering digits by their numerical value—as **StrCmpLogicalW** does—strings are ordered as follows:

```
2string
3string
20string
st2ring
st3ring
st20ring
string2
string3
string20
```

**StrCmpI** considers digits in the string only as text so that those same strings are ordered as follows:

```
20string
2string
3string
st20ring
st2ring
st3ring
string2
string20
string3
```

**Note** Behavior of this function, and therefore the results it returns, can change from release to release. It should not be used for canonical sorting applications.