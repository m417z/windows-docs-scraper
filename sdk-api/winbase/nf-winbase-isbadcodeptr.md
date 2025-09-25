# IsBadCodePtr function

## Description

Determines whether the calling process has read access to the memory at the specified address.

**Important** This function is obsolete and should not be used. Despite its name, it does not guarantee that the pointer is valid or that the memory pointed to is safe to use. For more information, see Remarks on this page.

## Parameters

### `lpfn` [in]

A pointer to a memory address.

## Return value

If the calling process has read access to the specified memory, the return value is zero.

If the calling process does not have read access to the specified memory, the return value is nonzero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the application is compiled as a debugging version, and the process does not have read access to the specified memory location, the function causes an assertion and breaks into the debugger. Leaving the debugger, the function continues as usual, and returns a nonzero value. This behavior is by design, as a debugging aid.

## Remarks

In a preemptive multitasking environment, it is possible for some other thread to change the process's access to the memory being tested. Even when the function indicates that the process has read access to the specified memory, you should use structured exception handling when attempting to access the memory. Use of structured exception handling enables the system to notify the process if an access violation exception occurs, giving the process an opportunity to handle the exception.

## See also

[IsBadReadPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadreadptr)

[IsBadStringPtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadstringptra)

[IsBadWritePtr](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-isbadwriteptr)