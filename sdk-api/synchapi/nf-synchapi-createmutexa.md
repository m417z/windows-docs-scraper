# CreateMutexA function

## Description

Creates or opens a named or unnamed mutex object.

To specify an access mask for the object, use the [CreateMutexEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexexa) function.

## Parameters

### `lpMutexAttributes` [in, optional]

A pointer to a
[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure. If this parameter is **NULL**, the handle cannot be inherited by child processes.

The **lpSecurityDescriptor** member of the structure specifies a security descriptor for the new mutex. If *lpMutexAttributes* is **NULL**, the mutex gets a default security descriptor. The ACLs in the default security descriptor for a mutex come from the primary or impersonation token of the creator. For more information, see [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `bInitialOwner` [in]

If this value is **TRUE** and the caller created the mutex, the calling thread obtains initial ownership of the mutex object. Otherwise, the calling thread does not obtain ownership of the mutex. To determine if the caller created the mutex, see the Return Values section.

### `lpName` [in, optional]

The name of the mutex object. The name is limited to **MAX_PATH** characters. Name comparison is case sensitive.

If *lpName* matches the name of an existing named mutex object, this function requests the **MUTEX_ALL_ACCESS** access right. In this case, the *bInitialOwner* parameter is ignored because it has already been set by the creating process. If the *lpMutexAttributes* parameter is not **NULL**, it determines whether the handle can be inherited, but its security-descriptor member is ignored.

If *lpName* is **NULL**, the mutex object is created without a name.

If *lpName* matches the name of an existing event, semaphore, waitable timer, job, or file-mapping object, the function fails and the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_INVALID_HANDLE**. This occurs because these objects share the same namespace.

The name can have a "Global\" or "Local\" prefix to explicitly create the object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces). Fast user switching is implemented using Terminal Services sessions. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

The object can be created in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

## Return value

If the function succeeds, the return value is a handle to the newly created mutex object.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the mutex is a named mutex and the object existed before this function call, the return value is a handle to the existing object, and the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function returns **ERROR_ALREADY_EXISTS**.

## Remarks

The handle returned by
**CreateMutex** has the **MUTEX_ALL_ACCESS** access right; it can be used in any function that requires a handle to a mutex object, provided that the caller has been granted access. If a mutex is created from a service or a thread that is impersonating a different user, you can either apply a security descriptor to the mutex when you create it, or change the default security descriptor for the creating process by changing its default DACL. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

If you are using a named mutex to limit your application to a single instance, a malicious user can create this mutex before you do and prevent your application from starting. To prevent this situation, create a randomly named mutex and store the name so that it can only be obtained by an authorized user. Alternatively, you can use a file for this purpose. To limit your application to one instance per user, create a locked file in the user's profile directory.

Any thread of the calling process can specify the mutex-object handle in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions). The single-object wait functions return when the state of the specified object is signaled. The multiple-object wait functions can be instructed to return either when any one or when all of the specified objects are signaled. When a wait function returns, the waiting thread is released to continue its execution.

The state of a mutex object is signaled when it is not owned by any thread. The creating thread can use the *bInitialOwner* flag to request immediate ownership of the mutex. Otherwise, a thread must use one of the wait functions to request ownership. When the mutex's state is signaled, one waiting thread is granted ownership, the mutex's state changes to nonsignaled, and the wait function returns. Only one thread can own a mutex at any given time. The owning thread uses the
[ReleaseMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-releasemutex) function to release its ownership.

The thread that owns a mutex can specify the same mutex in repeated wait function calls without blocking its execution. Typically, you would not wait repeatedly for the same mutex, but this mechanism prevents a thread from deadlocking itself while waiting for a mutex that it already owns. However, to release its ownership, the thread must call
[ReleaseMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-releasemutex) once for each time that the mutex satisfied a wait.

Two or more processes can call
**CreateMutex** to create the same named mutex. The first process actually creates the mutex, and subsequent processes with sufficient access rights simply open a handle to the existing mutex. This enables multiple processes to get handles of the same mutex, while relieving the user of the responsibility of ensuring that the creating process is started first. When using this technique, you should set the *bInitialOwner* flag to **FALSE**; otherwise, it can be difficult to be certain which process has initial ownership.

Multiple processes can have handles of the same mutex object, enabling use of the object for interprocess synchronization. The following object-sharing mechanisms are available:

* A child process created by the
  [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function can inherit a handle to a mutex object if the *lpMutexAttributes* parameter of
  **CreateMutex** enabled inheritance. This mechanism works for both named and unnamed mutexes.
* A process can specify the handle to a mutex object in a call to the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function to create a duplicate handle that can be used by another process. This mechanism works for both named and unnamed mutexes.
* A process can specify a named mutex in a call to [OpenMutex](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openmutexw) or **CreateMutex** to retrieve a handle to the mutex object.

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The mutex object is destroyed when its last handle has been closed.

#### Examples

See [Using Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/using-mutex-objects) for an example of **CreateMutex**.

> [!NOTE]
> The synchapi.h header defines CreateMutex as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateMutexEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexexa)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/mutex-objects)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[OpenMutex](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openmutexw)

[ReleaseMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-releasemutex)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)