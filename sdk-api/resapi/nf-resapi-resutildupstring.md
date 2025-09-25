# ResUtilDupString function

## Description

Duplicates a null-terminated Unicode string.

## Parameters

### `pszInString` [in]

Pointer to the string to duplicate.

## Return value

If the operation succeeds, the function returns a pointer to a buffer containing the duplicate string.

If the operation fails,
the function returns **NULL**. For more information, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

With the **ResUtilDupString** utility function, after using the returned string, callers should deallocate the buffer by calling the function [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

## See also

[LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree)