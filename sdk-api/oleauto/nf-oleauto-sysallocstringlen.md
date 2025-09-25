# SysAllocStringLen function

## Description

Allocates a new string, copies the specified number of characters from the passed string, and appends a null-terminating character.

## Parameters

### `strIn` [in]

The input string.

### `ui` [in]

The number of characters to copy. A null character is placed afterwards, allocating a total of *ui* plus one characters.

## Return value

A copy of the string, or **NULL** if there is insufficient memory to complete the operation.

## Remarks

The string can contain embedded null characters and does not need to end with a **NULL**. Free the returned string later with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring). If *strIn* is not **NULL**, then the memory allocated to *strIn* must be at least *ui* characters long.

**Note** This function does not convert a **char *** string into a Unicode **BSTR**.

## See also

[String Manipulation Functions](https://learn.microsoft.com/previous-versions/windows/desktop/automat/string-manipulation-functions)