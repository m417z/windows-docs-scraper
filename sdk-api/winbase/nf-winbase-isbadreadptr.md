# IsBadReadPtr function

## Description

Verifies that the calling process has read access to the specified range of memory.

**Important** This function is obsolete and should not be used. Despite its name, it does not guarantee that the pointer is valid or that the memory pointed to is safe to use. For more information, see Remarks on this page.

## Parameters

### `lp` [in]

A pointer to the first byte of the memory block.

### `ucb` [in]

The size of the memory block, in bytes. If this parameter is zero, the return value is zero.

## Return value

If the calling process has read access to all bytes in the specified memory range, the return value is zero.

If the calling process does not have read access to all bytes in the specified memory range, the return value is nonzero.

If the application is compiled as a debugging version, and the process does not have read access to all bytes in the specified memory range, the function causes an assertion and breaks into the debugger. Leaving the debugger, the function continues as usual, and returns a nonzero value. This behavior is by design, as a debugging aid.

## Remarks

This function is typically used when working with pointers returned from third-party libraries, where you cannot determine the memory management behavior in the third-party DLL.

Threads in a process are expected to cooperate in such a way that one will not free memory that the other needs. Use of this function does not negate the need to do this. If this is not done, the application may fail in an unpredictable manner.

Dereferencing potentially invalid pointers can disable stack expansion in other threads. A thread exhausting its stack, when stack expansion has been disabled, results in the immediate termination of the parent process, with no pop-up error window or diagnostic information.

If the calling process has read access to some, but not all, of the bytes in the specified memory range, the return value is nonzero.

In a preemptive multitasking environment, it is possible for some other thread to change the process's access to the memory being tested. Even when the function indicates that the process has read access to the specified memory, you should use structured exception handling when attempting to access the memory. Use of structured exception handling enables the system to notify the process if an access violation exception occurs, giving the process an opportunity to handle the exception.

## See also

[IsBadCodePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadcodeptr)

[IsBadStringPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadstringptra)

[IsBadWritePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadwriteptr)