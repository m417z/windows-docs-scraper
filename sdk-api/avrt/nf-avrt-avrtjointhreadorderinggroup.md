# AvRtJoinThreadOrderingGroup function

## Description

Joins client threads to a thread ordering group.

## Parameters

### `Context` [out]

A pointer to a context handle.

### `ThreadOrderingGuid` [in]

A pointer to the unique identifier for the thread ordering group.

### `Before` [in]

The thread order. If this parameter is **TRUE**, the thread is a predecessor thread that is scheduled to run before the parent thread. If this parameter is **FALSE**, the thread is a successor thread that is scheduled to run after the parent thread.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The thread encloses the code to be executed during each period within a loop that is controlled by the [AvRtWaitOnThreadOrderingGroup](https://learn.microsoft.com/windows/desktop/api/avrt/nf-avrt-avrtwaitonthreadorderinggroup) function.

A thread can create more than one thread ordering group and join more than one thread ordering group. However, a thread cannot join the same thread ordering group more than one time.

The number of threads that can join a group is limited only by available system resources.

## See also

[Thread Ordering Service](https://learn.microsoft.com/windows/desktop/ProcThread/thread-ordering-service)