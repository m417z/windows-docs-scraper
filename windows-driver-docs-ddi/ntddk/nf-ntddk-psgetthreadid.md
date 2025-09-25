## Description

This routine returns the unique identifier (ID) of a given thread.

## Parameters

### `Thread` [in]

A pointer to an executive thread object structure (ETHREAD).

## Return value

Returns a HANDLE that is the unique ID of the caller-supplied thread.

## Remarks

A driver might call PsGetThreadId for several reasons:

* Thread Identification: The thread ID returned by PsGetThreadId is unique system-wide, not just within a single process.

* Debugging and Logging: Thread IDs are often used in debugging and logging to trace the execution of the program.

Thread ID is not unique for a boot session. After a thread has terminated its ID may be reused.

## See also