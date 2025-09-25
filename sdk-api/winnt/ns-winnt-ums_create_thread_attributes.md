# UMS_CREATE_THREAD_ATTRIBUTES structure

## Description

Specifies attributes for a user-mode scheduling (UMS) worker thread.

This structure is used with the [UpdateProcThreadAttribute](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-updateprocthreadattribute) function.

## Members

### `UmsVersion`

The UMS version for which the application was built. This parameter must be **UMS_VERSION**.

### `UmsContext`

A pointer to a UMS thread context for the worker thread to be created. This pointer is provided by the [CreateUmsThreadContext](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumsthreadcontext) function.

### `UmsCompletionList`

A pointer to a UMS completion list. This pointer is provided by the [CreateUmsCompletionList](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createumscompletionlist) function. The newly created worker thread is queued to the specified completion list.