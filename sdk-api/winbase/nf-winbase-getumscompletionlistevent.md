# GetUmsCompletionListEvent function

## Description

Retrieves a handle to the event associated with the specified user-mode scheduling (UMS) completion list.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Parameters

### `UmsCompletionList` [in]

A pointer to a UMS completion list. The [CreateUmsCompletionList](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumscompletionlist) function provides this pointer.

### `UmsCompletionEvent` [in, out]

A pointer to a HANDLE variable. On output, the *UmsCompletionEvent* parameter is set to a handle to the event associated with the specified completion list.

## Return value

If the function succeeds, it returns a nonzero value.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system signals a UMS completion list event when the system queues items to an empty completion list. A completion list event handle can be used with any [wait function](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) that takes a handle to an event. When the event is signaled, an application typically calls [DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems) to retrieve the contents of the completion list.

The event handle remains valid until its completion list is deleted. Do not use the event handle to wait on a completion list that has been deleted or is in the process of being deleted.

When the handle is no longer needed, use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle.

## See also

[CreateUmsCompletionList](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumscompletionlist)

[DequeueUmsCompletionListItems](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-dequeueumscompletionlistitems)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)