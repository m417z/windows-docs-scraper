# SysReAllocString function

## Description

Reallocates a previously allocated string to be the size of a second string and copies the second string into the reallocated memory.

## Parameters

### `pbstr` [in, out]

The previously allocated string.

### `psz` [in, optional]

The string to copy.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The string is reallocated successfully. |
| **FALSE** | Insufficient memory exists. |

## Remarks

The address passed in psz cannot be part of the string passed in pbstr, or unexpected results may occur.

If pbstr is NULL, there will be an access violation and the program will crash. It is your responsibility to protect this function against NULL pointers.

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)