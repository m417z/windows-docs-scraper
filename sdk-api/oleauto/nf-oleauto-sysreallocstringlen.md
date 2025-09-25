# SysReAllocStringLen function

## Description

Creates a new BSTR containing a specified number of characters from an old BSTR, and frees the old BSTR.

## Parameters

### `pbstr` [in, out]

The previously allocated string.

### `psz` [in, optional]

The string from which to copy *len* characters, or NULL to keep the string uninitialized.

### `len` [in]

The number of characters to copy. A null character is placed afterward, allocating a total of *len* plus one characters.

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The string is reallocated successfully. |
| **FALSE** | Insufficient memory exists. |

## Remarks

Allocates a new string, copies *len* characters from the passed string into it, and then appends a null character. Frees the BSTR referenced currently by *pbstr*, and resets *pbstr* to point to the new BSTR. If *psz* is null, a string of length *len* is allocated but not initialized.

The *psz* string can contain embedded null characters and does not need to end with a null.

If this function is passed a NULL pointer, there will be an access violation and the program will crash. It is your responsibility to protect this function against NULL pointers.

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)