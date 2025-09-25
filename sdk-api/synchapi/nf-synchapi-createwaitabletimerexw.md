# CreateWaitableTimerExW function

## Description

Creates or opens a waitable timer object and returns a handle to the object.

## Parameters

### `lpTimerAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. If this parameter is **NULL**, the timer handle cannot be inherited by child processes.

If *lpTimerAttributes* is **NULL**, the timer object gets a default security descriptor and the handle cannot be inherited. The ACLs in the default security descriptor for a timer come from the primary or impersonation token of the creator.

### `lpTimerName` [in, optional]

The name of the timer object. The name is limited to **MAX_PATH** characters. Name comparison is case sensitive.

If *lpTimerName* is **NULL**, the timer object is created without a name.

If *lpTimerName* matches the name of an existing event, semaphore, mutex, job, or file-mapping object, the function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

### `dwFlags` [in]

This parameter can be 0 or the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_WAITABLE_TIMER_MANUAL_RESET**<br><br>0x00000001 | The timer must be manually reset. Otherwise, the system automatically resets the timer after releasing a single waiting thread. |
| **CREATE_WAITABLE_TIMER_HIGH_RESOLUTION**<br><br>0x00000002 | Creates a high resolution timer. Use this value for time-critical situations when short expiration delays on the order of a few milliseconds are unacceptable. This value is supported in Windows 10, version 1803, and later. |

### `dwDesiredAccess` [in]

The access mask for the timer object. For a list of access rights, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

## Return value

If the function succeeds, the return value is a handle to the timer object. If the named timer object exists before the function call, the function returns a handle to the existing object and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Any thread of the calling process can specify the timer object handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

Multiple processes can have handles to the same timer object, enabling use of the object for interprocess synchronization.

* A process created by the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit a handle to a timer object if the *lpTimerAttributes* parameter of **CreateWaitableTimerEx** enables inheritance.
* A process can specify the timer object handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function. The resulting handle can be used by another process.
* A process can specify the name of a timer object in a call to the [OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw) or **CreateWaitableTimerEx** function.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The timer object is destroyed when its last handle has been closed.

To associate a timer with a window, use the [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) function.

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/waitable-timer-objects)