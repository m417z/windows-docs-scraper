# CreateEventExW function

## Description

Creates or opens a named or unnamed event object and returns a handle to the object.

## Parameters

### `lpEventAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. If
*lpEventAttributes* is **NULL**, the event handle cannot be inherited by child processes.

The **lpSecurityDescriptor** member of the structure specifies a
[security descriptor](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptors) for the new
event. If *lpEventAttributes* is **NULL**, the event gets a default security descriptor.
The ACLs in the default security descriptor for an event come from the primary or impersonation token of the creator.

### `lpName` [in, optional]

The name of the event object. The name is limited to
**MAX_PATH** characters. Name comparison is case sensitive.

If *lpName* is **NULL**, the event object is created without a name.

If *lpName* matches the name of another kind of object in the same namespace (such as an existing semaphore, mutex, waitable timer, job, or
file-mapping object), the function fails and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns
**ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session
namespace. The remainder of the name can contain any character except the backslash character (\\). For more
information, see [Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined
for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

### `dwFlags` [in]

This parameter can be 0 or one of the following values.

| Value | Meaning |
| --- | --- |
| **CREATE_EVENT_INITIAL_SET**<br><br>0x00000002 | The initial state of the event object is signaled; otherwise, it is nonsignaled. |
| **CREATE_EVENT_MANUAL_RESET**<br><br>0x00000001 | The event must be manually reset using the [ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent) function. Any number of waiting threads, or threads that subsequently begin wait operations for the specified event object, can be released while the object's state is signaled.<br><br>If this flag is not specified, the system automatically resets the event after releasing a single waiting thread. |

### `dwDesiredAccess` [in]

The access mask for the event object. For a list of access rights, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

## Return value

If the function succeeds, the return value is a handle to the event object. If the named event object existed
before the function call, the function returns a handle to the existing object and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns
**ERROR_ALREADY_EXISTS**.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Any thread of the calling process can specify the event-object handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). The single-object wait functions return
when the state of the specified object is signaled. The multiple-object wait functions can be instructed to
return either when any one or when all of the specified objects are signaled. When a wait function returns, the
waiting thread is released to continue its execution.

The initial state of the event object is specified by the *dwFlags* parameter. Use
the [SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent) function to set the state of an event object to
signaled. Use the [ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent) function to reset
the state of an event object to nonsignaled.

When the state of a manual-reset event object is signaled, it remains signaled until it is explicitly reset to
nonsignaled by the [ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent) function. Any number of
waiting threads, or threads that subsequently begin wait operations for the specified event object, can be
released while the object's state is signaled.

Multiple processes can have handles of the same event object, enabling use of the object for interprocess
synchronization. The following object-sharing mechanisms are available:

* A child process created by the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function
  can inherit a handle to an event object if the *lpEventAttributes* parameter of
  **CreateEvent** enabled inheritance.
* A process can specify the event-object handle in a call to the
  [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function to create a duplicate
  handle that can be used by another process.
* A process can specify the name of an event object in a call to the
  [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) or **CreateEvent** function.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The
system closes the handle automatically when the process terminates. The event object is destroyed when its last
handle has been closed.

> [!NOTE]
> The synchapi.h header defines CreateEventEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)