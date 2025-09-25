# IsBadWritePtr function

## Description

Verifies that the calling process has write access to the specified range of memory.

**Important** This function is obsolete and should not be used. Despite its name, it does not guarantee that the pointer is valid or that the memory pointed to is safe to use. For more information, see Remarks on this page.

## Parameters

### `lp` [in]

A pointer to the first byte of the memory block.

### `ucb` [in]

The size of the memory block, in bytes. If this parameter is zero, the return value is zero.

## Return value

If the calling process has write access to all bytes in the specified memory range, the return value is zero.

If the calling process does not have write access to all bytes in the specified memory range, the return value is nonzero.

If the application is run under a debugger and the process does not have write access to all bytes in the specified memory range, the function causes a first chance STATUS_ACCESS_VIOLATION exception. The debugger can be configured to break for this condition. After resuming process execution in the debugger, the function continues as usual and returns a nonzero value This behavior is by design and serves as a debugging aid.

## Remarks

This function is typically used when working with pointers returned from third-party libraries, where you cannot determine the memory management behavior in the third-party DLL.

Threads in a process are expected to cooperate in such a way that one will not free memory that the other needs. Use of this function does not negate the need to do this. If this is not done, the application may fail in an unpredictable manner.

Dereferencing potentially invalid pointers can disable stack expansion in other threads. A thread exhausting its stack, when stack expansion has been disabled, results in the immediate termination of the parent process, with no pop-up error window or diagnostic information.

If the calling process has write access to some, but not all, of the bytes in the specified memory range, the return value is nonzero.

In a preemptive multitasking environment, it is possible for some other thread to change the process's access to the memory being tested. Even when the function indicates that the process has write access to the specified memory, you should use structured exception handling when attempting to access the memory. Use of structured exception handling enables the system to notify the process if an access violation exception occurs, giving the process an opportunity to handle the exception.

**IsBadWritePtr** is not multithread safe. To use it properly on a pointer shared by multiple threads, call it inside a critical region of code that allows only one thread to access the memory being checked. Use operating system–level objects such as critical sections or mutexes or the interlocked functions to create the critical region of code.

## See also

[IsBadCodePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadcodeptr)

[IsBadReadPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadreadptr)

[IsBadStringPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadstringptra)