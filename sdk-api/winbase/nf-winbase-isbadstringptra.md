# IsBadStringPtrA function

## Description

Verifies that the calling process has read access to the specified range of memory.

**Important** This function is obsolete and should not be used. Despite its name, it does not guarantee that the pointer is valid or that the memory pointed to is safe to use. For more information, see Remarks on this page.

## Parameters

### `lpsz` [in]

A pointer to a null-terminated string, either Unicode or ASCII.

### `ucchMax` [in]

The maximum size of the string, in **TCHARs**. The function checks for read access in all characters up to the string's terminating null character or up to the number of characters specified by this parameter, whichever is smaller. If this parameter is zero, the return value is zero.

## Return value

If the calling process has read access to all characters up to the string's terminating null character or up to the number of characters specified by *ucchMax*, the return value is zero.

If the calling process does not have read access to all characters up to the string's terminating null character or up to the number of characters specified by *ucchMax*, the return value is nonzero.

If the application is compiled as a debugging version, and the process does not have read access to the entire memory range specified, the function causes an assertion and breaks into the debugger. Leaving the debugger, the function continues as usual, and returns a nonzero value This behavior is by design, as a debugging aid.

## Remarks

This function is typically used when working with pointers returned from third-party libraries, where you cannot determine the memory management behavior in the third-party DLL.

Threads in a process are expected to cooperate in such a way that one will not free memory that the other needs. Use of this function does not negate the need to do this. If this is not done, the application may fail in an unpredictable manner.

Dereferencing potentially invalid pointers can disable stack expansion in other threads. A thread exhausting its stack, when stack expansion has been disabled, results in the immediate termination of the parent process, with no pop-up error window or diagnostic information.

If the calling process has read access to some, but not all, of the specified memory range, the return value is nonzero.

In a preemptive multitasking environment, it is possible for some other thread to change the process's access to the memory being tested. Even when the function indicates that the process has read access to the specified memory, you should use
[structured exception handling](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling) when attempting to access the memory. Use of structured exception handling enables the system to notify the process if an access violation exception occurs, giving the process an opportunity to handle the exception.

> [!NOTE]
> The winbase.h header defines IsBadStringPtr as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IsBadCodePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadcodeptr)

[IsBadReadPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadreadptr)

[IsBadWritePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadwriteptr)