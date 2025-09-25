# GetNextUmsListItem function

## Description

Returns the next user-mode scheduling (UMS) thread context in a list of thread contexts.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsContext` [in, out]

A pointer to a UMS context in a list of thread contexts. This list is retrieved by the [DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems) function.

## Return value

If the function succeeds, it returns a pointer to the next thread context in the list.

If there is no thread context after the context specified by the *UmsContext* parameter, the function returns NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems)