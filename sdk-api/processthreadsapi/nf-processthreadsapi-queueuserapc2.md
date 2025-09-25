# QueueUserAPC2 function

## Description

Adds a user-mode [asynchronous procedure call](https://learn.microsoft.com/windows/win32/sync/asynchronous-procedure-calls) (APC) object to the APC queue of the specified thread.

## Parameters

### `ApcRoutine`

A pointer to the application-supplied APC function to be called when the specified thread performs an alertable wait operation. For more information, see [APCProc](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-papcfunc).

For special user-mode APCs, an alertable wait is not required. See [Remarks](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc2#remarks) for more information about special user-mode APCs.

### `Thread`

A handle to the thread. The handle must have **THREAD_SET_CONTEXT** access permission. For more information, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `Data`

A single value that is passed to the APC function pointed to by the *ApcRoutine* parameter.

### `Flags`

A value from [QUEUE_USER_APC_FLAGS enumeration](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-queue_user_apc_flags) that modifies the behavior of the user-mode APC.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Regular user-mode APCs are only executed if the target thread is in an alertable state. See [QueueUserAPC function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc) for additional remarks on regular user-mode APCs.

Special user-mode APCs always execute, even if the target thread is not in an alertable state. For example, if the target thread is currently executing user-mode code, or if the target thread is currently performing an alertable wait, the target thread will be interrupted immediately for APC execution. If the target thread is executing a system call, or performing a non-alertable wait, the APC will be executed after the system call or non-alertable wait finishes (the wait is not interrupted).

Since the execution of the special user-mode APC is not synchronized with the target thread, particular care must be taken (beyond the normal requirements for multithreading and synchronization). For example, when acquiring any locks, the interrupted target thread may already own the lock or be in the process of acquiring or releasing the lock. In addition, because there are no facilities to block a thread from receiving special user-mode APCs, a special user-mode APC can be executed on a target thread that is already executing a special user-mode APC.

Currently, special user-mode APCs are only supported on native architectures, and not when running under WoW.

## See also