# DeleteUmsCompletionList function

## Description

Deletes the specified user-mode scheduling (UMS) completion list. The list must be empty.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsCompletionList` [in]

A pointer to the UMS completion list to be deleted. The [CreateUmsCompletionList](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumscompletionlist) function provides this pointer.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the completion list is shared, the caller is responsible for ensuring that no active UMS thread holds a reference to the list before deleting it.