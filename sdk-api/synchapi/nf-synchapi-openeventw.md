# OpenEventW function

## Description

Opens an existing named event object.

## Parameters

### `dwDesiredAccess` [in]

The access to the event object. The function fails if the security descriptor of the specified object does not permit the requested access for the calling process. For a list of access rights, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `bInheritHandle` [in]

If this value is **TRUE**, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `lpName` [in]

The name of the event to be opened. Name comparisons are case sensitive.

This function can open objects in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

**Terminal Services:** The name can have a "Global\" or "Local\" prefix to explicitly open an object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

**Note** Fast user switching is implemented using Terminal Services sessions. The first user to log on uses session 0, the next user to log on uses session 1, and so on. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is a handle to the event object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**OpenEvent** function enables multiple processes to open handles of the same event object. The function succeeds only if some process has already created the event by using the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. The calling process can use the returned handle in any function that requires a handle to an event object, subject to the limitations of the access specified in the *dwDesiredAccess* parameter.

The handle can be duplicated by using the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The event object is destroyed when its last handle has been closed.

> [!NOTE]
> The synchapi.h header defines OpenEvent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent)

[ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent)

[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)