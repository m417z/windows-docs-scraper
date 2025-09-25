# ResUtilExpandEnvironmentStrings function

## Description

Expands strings containing unexpanded references to environment variables. The **PRESUTIL_EXPAND_ENVIRONMENT_STRINGS** type defines a pointer to this function.

## Parameters

### `pszSrc` [in]

Pointer to a null-terminated Unicode string containing unexpanded references to environment variables (an [expandable string](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/e-gly)).

## Return value

If the operation succeeds, the function returns a pointer to the expanded string (REG_EXPAND_SZ). The function allocates the necessary memory with [LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc). To prevent memory leaks, be sure to release the memory with [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

If the operation fails, the function returns **NULL**.
For more information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[ResUtilFindExpandSzProperty](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilfindexpandszproperty)

[ResUtilGetEnvironmentWithNetName](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetenvironmentwithnetname)

[ResUtilGetExpandSzValue](https://learn.microsoft.com/windows/win32/api/resapi/nf-resapi-resutilgetexpandszvalue)