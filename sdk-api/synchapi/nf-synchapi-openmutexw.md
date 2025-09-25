# OpenMutexW function

## Description

Opens an existing named mutex object.

## Parameters

### `dwDesiredAccess` [in]

The access to the mutex object. Only the **SYNCHRONIZE** access right is required to use a mutex; to change the mutex's security, specify **MUTEX_ALL_ACCESS**. The function fails if the security descriptor of the specified object does not permit the requested access for the calling process. For a list of access rights, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `bInheritHandle` [in]

If this value is **TRUE**, processes created by this process will inherit the handle. Otherwise, the processes do not inherit this handle.

### `lpName` [in]

The name of the mutex to be opened. Name comparisons are case sensitive.

This function can open objects in a private namespace. For more information, see [Object Namespaces](https://learn.microsoft.com/windows/desktop/Sync/object-namespaces).

**Terminal Services:** The name can have a "Global\" or "Local\" prefix to explicitly open an object in the global or session namespace. The remainder of the name can contain any character except the backslash character (\\). For more information, see
[Kernel Object Namespaces](https://learn.microsoft.com/windows/desktop/TermServ/kernel-object-namespaces).

**Note** Fast user switching is implemented using Terminal Services sessions. The first user to log on uses session 0, the next user to log on uses session 1, and so on. Kernel object names must follow the guidelines outlined for Terminal Services so that applications can support multiple users.

## Return value

If the function succeeds, the return value is a handle to the mutex object.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If a named mutex does not exist, the function fails and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_FILE_NOT_FOUND**.

## Remarks

The
**OpenMutex** function enables multiple processes to open handles of the same mutex object. The function succeeds only if some process has already created the mutex by using the
[CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) function. The calling process can use the returned handle in any function that requires a handle to a mutex object, such as the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), subject to the limitations of the access specified in the *dwDesiredAccess* parameter.

The handle can be duplicated by using the [DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle) function. Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the handle. The system closes the handle automatically when the process terminates. The mutex object is destroyed when its last handle has been closed.

If your multithreaded application must repeatedly create, open, and close a named mutex object, a race condition can occur. In this situation, it is better to use [CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) instead of **OpenMutex**, because **CreateMutex** opens a mutex if it exists and creates it if it does not.

#### Examples

For an example that uses
**OpenMutex**, see
[Using Named Objects](https://learn.microsoft.com/windows/desktop/Sync/using-named-objects).

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[DuplicateHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-duplicatehandle)

[Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/mutex-objects)

[Object Names](https://learn.microsoft.com/windows/desktop/Sync/object-names)

[ReleaseMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-releasemutex)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)