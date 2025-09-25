# OpenWaitableTimerW function

## Description

Opens an existing named waitable timer object.

## Parameters

### `dwDesiredAccess` [in]

The access to the timer object. The function fails if the security descriptor of the specified object does
not permit the requested access for the calling process. For a list of access rights, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `bInheritHandle` [in]

If this value is **TRUE**, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `lpTimerName` [in]

The name of the timer object. The name is limited to **MAX_PATH** characters. Name comparison is case sensitive.

This function can open objects in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

**Terminal Services:** The name can have a "Global\" or "Local\" prefix to explicitly open an object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

**Note** Fast user switching is implemented using Terminal Services sessions. The first user to log on uses session 0, the next user to log on uses session 1, and so on. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is a handle to the timer object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**OpenWaitableTimer** function enables multiple processes to open handles to the same timer object. The function succeeds only if some process has already created the timer using the
[CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw) function. The calling process can use the returned handle in any function that requires the handle to a timer object, such as the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), subject to the limitations of the access specified in the *dwDesiredAccess* parameter.

The returned handle can be duplicated by using the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The timer object is destroyed when its last handle has been closed.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CancelWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-cancelwaitabletimer)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/waitable-timer-objects)