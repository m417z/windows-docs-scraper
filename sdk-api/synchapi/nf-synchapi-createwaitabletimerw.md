# CreateWaitableTimerW function

## Description

Creates or opens a waitable timer object.

To specify an access mask for the object, use the [CreateWaitableTimerEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerexw) function.

## Parameters

### `lpTimerAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure that specifies a security descriptor for the new timer object and determines whether child processes can inherit the returned handle.

If *lpTimerAttributes* is **NULL**, the timer object gets a default security descriptor and the handle cannot be inherited. The ACLs in the default security descriptor for a timer come from the primary or impersonation token of the creator.

### `bManualReset` [in]

If this parameter is **TRUE**, the timer is a manual-reset notification timer. Otherwise, the timer is a synchronization timer.

### `lpTimerName` [in, optional]

The name of the timer object. The name is limited to **MAX_PATH** characters. Name comparison is case sensitive.

If *lpTimerName* is **NULL**, the timer object is created without a name.

If *lpTimerName* matches the name of an existing event, semaphore, mutex, job, or file-mapping object, the function fails and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

## Return value

If the function succeeds, the return value is a handle to the timer object. If the named timer object exists before the function call, the function returns a handle to the existing object and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The handle returned by
**CreateWaitableTimer** is created with the **TIMER_ALL_ACCESS** access right; it can be used in any function that requires a handle to a timer object, provided that the caller has been granted access. If a timer is created from a service or thread that is impersonating a different user, you can either apply a security descriptor to the timer when you create it, or change the default security descriptor for the creating process by changing its default DACL. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

Any thread of the calling process can specify the timer object handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

Multiple processes can have handles to the same timer object, enabling use of the object for interprocess synchronization.

* A process created by the
  [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit a handle to a timer object if the *lpTimerAttributes* parameter of
  **CreateWaitableTimer** enables inheritance.
* A process can specify the timer object handle in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function. The resulting handle can be used by another process.
* A process can specify the name of a timer object in a call to the [OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw) or **CreateWaitableTimer** function.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The timer object is destroyed when its last handle has been closed.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

To associate a timer with a window, use the [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) function.

#### Examples

For an example that uses
**CreateWaitableTimer**, see
[Using Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/using-waitable-timer-objects).

## See also

[CancelWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-cancelwaitabletimer)

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[CreateWaitableTimerEx](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerexw)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/waitable-timer-objects)