# FsRtlDissectDbcs function

## Description

Given an ANSI or double-byte character set (DBCS) pathname string, the **FsRtlDissectDbcs** routine returns two strings: one containing the first file name found in the string, the other containing the remaining unparsed portion of the pathname string.

## Parameters

### `Path` [in]

The pathname string to be parsed.

### `FirstName` [out]

A pointer to the first file name in the pathname string.

### `RemainingName` [out]

A pointer to the remaining unparsed portion of the pathname string.

## Remarks

In the input string, backslashes are read as name separators. The first name in the string is assumed to consist of all characters from the beginning of the string to the character preceding the first backslash, inclusive. There is just one exception to this rule: if the first character in the input string is a backslash, this character is ignored and does not appear in the output string. The remaining portion of the string consists of all characters following the backslash that follows the first name found in the string.

**FsRtlDissectDbcs** does not check for the presence of illegal characters in the input string.

The following table shows sample input and output values for **FsRtlDissectDbcs**:

| Path | FirstName | RemainingName |
| --- | --- | --- |
| empty | empty | empty |
| A | A | empty |
| A\B\C\D\E | A | B\C\D\E |
| *A? | *A? | empty |
| \A | A | empty |
| A[,] | A[,] | empty |
| A\\B+;\C | A | \B+;\C |

Note that upon returning, the **Buffer** members of the output parameters will point into the **Buffer** member of **Path**. Therefore, the caller should not allocate storage for the **Buffer** members of the two output parameters, as shown in the following example:

```
.
.
.
/*
The FsRtlDissectDbcs routine will set the members
of the following two structures appropriately:
*/
UNICODE_STRING CurrentComponent;
UNICODE_STRING RemainingComponent;

/*
Do not allocate storage for the Buffer members of CurrentComponent
and RemainingComponent in that they will point into the previously
allocated storage of FullPathName's Buffer member:
*/
FsRtlDissectDbcs (FullPathName, &CurrentComponent, &RemainingComponent);
.
.
.
```

For information about other string-handling routines, see [Run-Time Library (RTL) Routines](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#run-time-library-rtl-routines).

## See also

[ANSI_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-string)