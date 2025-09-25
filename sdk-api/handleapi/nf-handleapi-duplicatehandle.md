# DuplicateHandle function

## Description

Duplicates an object handle.

## Parameters

### `hSourceProcessHandle` [in]

A handle to the process with the handle to be duplicated.

The handle must have the PROCESS_DUP_HANDLE access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `hSourceHandle` [in]

The handle to be duplicated. This is an open object handle that is valid in the context of the source process. For a list of objects whose handles can be duplicated, see the following Remarks section.

If *hSourceHandle* is a pseudo handle returned by [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) or [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread), *hSourceProcessHandle* should be a handle to the process calling **DuplicateHandle**.

### `hTargetProcessHandle` [in]

A handle to the process that is to receive the duplicated handle. The handle must have the PROCESS_DUP_HANDLE access right.

This parameter is optional and can be specified as NULL if the **DUPLICATE_CLOSE_SOURCE** flag is set in _Options_.

### `lpTargetHandle` [out]

A pointer to a variable that receives the duplicate handle. This handle value is valid in the context of the target process.

If *hSourceHandle* is a pseudo handle returned by [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) or [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread), **DuplicateHandle** converts it to a real handle to a process or thread, respectively.

If *lpTargetHandle* is **NULL**, the function duplicates the handle, but does not return the duplicate handle value to the caller. This behavior exists only for backward compatibility with previous versions of this function. You should not use this feature, as you will lose system resources until the target process terminates.

This parameter is ignored if _hTargetProcessHandle_ is **NULL**.

### `dwDesiredAccess` [in]

The access requested for the new handle. For the flags that can be specified for each object type, see the following Remarks section.

This parameter is ignored if the *dwOptions* parameter specifies the DUPLICATE_SAME_ACCESS flag. Otherwise, the flags that can be specified depend on the type of object whose handle is to be duplicated.

This parameter is ignored if _hTargetProcessHandle_ is **NULL**.

### `bInheritHandle` [in]

A variable that indicates whether the handle is inheritable. If **TRUE**, the duplicate handle can be inherited by new processes created by the target process. If **FALSE**, the new handle cannot be inherited.

This parameter is ignored if _hTargetProcessHandle_ is **NULL**.

### `dwOptions` [in]

Optional actions. This parameter can be zero, or any combination of the following values.

| Value | Meaning |
| --- | --- |
| **DUPLICATE_CLOSE_SOURCE**<br><br>0x00000001 | Closes the source handle. This occurs regardless of any error status returned. |
| **DUPLICATE_SAME_ACCESS**<br><br>0x00000002 | Ignores the *dwDesiredAccess* parameter. The duplicate handle has the same access as the source handle. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The duplicate handle refers to the same object as the original handle. Therefore, any changes to the object are reflected through both handles. For example, if you duplicate a file handle, the current file position is always the same for both handles. For file handles to have different file positions, use the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function to create file handles that share access to the same file.

**DuplicateHandle** can be called by either the source process or the target process (or a process that is both the source and target process). For example, a process can use
**DuplicateHandle** to create a noninheritable duplicate of an inheritable handle, or a handle with different access than the original handle.

The source process uses the
[GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) function to get a handle to itself. This handle is a pseudo handle, but **DuplicateHandle** converts it to a real process handle. To get the target process handle, it may be necessary to use some form of interprocess communication (for example, a named pipe or shared memory) to communicate the process identifier to the source process. The source process can use this identifier in the
[OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function to obtain a handle to the target process.

If the process that calls
**DuplicateHandle** is not also the target process, the source process must use interprocess communication to pass the value of the duplicate handle to the target process.

**DuplicateHandle** can be used to duplicate a handle between a 32-bit process and a 64-bit process. The resulting handle is appropriately sized to work in the target process. For more information, see [Process Interoperability](https://learn.microsoft.com/windows/desktop/WinProg64/process-interoperability).

**DuplicateHandle** can duplicate handles to the following types of objects.

| Object | Description |
| --- | --- |
| Access token | The handle is returned by the [CreateRestrictedToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-createrestrictedtoken), [DuplicateToken](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetoken), [DuplicateTokenEx](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-duplicatetokenex), [OpenProcessToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocesstoken), or [OpenThreadToken](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openthreadtoken) function. |
| Change notification | The handle is returned by the [FindFirstChangeNotification](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstchangenotificationa) function. |
| Communications device | The handle is returned by the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. |
| Console input | The handle is returned by the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function when CONIN$ is specified, or by the [GetStdHandle](https://learn.microsoft.com/windows/console/getstdhandle) function when STD_INPUT_HANDLE is specified. Console handles can be duplicated for use only in the same process. |
| Console screen buffer | The handle is returned by the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function when CONOUT$ is specified, or by the [GetStdHandle](https://learn.microsoft.com/windows/console/getstdhandle) function when STD_OUTPUT_HANDLE is specified. Console handles can be duplicated for use only in the same process. |
| Desktop | The handle is returned by the [GetThreadDesktop](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getthreaddesktop) function. |
| Event | The handle is returned by the [CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or [OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function. |
| File | The handle is returned by the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. |
| File mapping | The handle is returned by the [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) function. |
| Job | The handle is returned by the [CreateJobObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createjobobjecta) function. |
| Mailslot | The handle is returned by the [CreateMailslot](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createmailslota) function. |
| Mutex | The handle is returned by the [CreateMutex](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createmutexa) or [OpenMutex](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openmutexw) function. |
| Pipe | A named pipe handle is returned by the [CreateNamedPipe](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createnamedpipea) or [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function. An anonymous pipe handle is returned by the [CreatePipe](https://learn.microsoft.com/windows/desktop/api/namedpipeapi/nf-namedpipeapi-createpipe) function. |
| Process | The handle is returned by the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess), or [OpenProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-openprocess) function. |
| Registry key | The handle is returned by the [RegCreateKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeya), [RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa), [RegOpenKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeya), or [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function. Note that registry key handles returned by the [RegConnectRegistry](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regconnectregistrya) function cannot be used in a call to **DuplicateHandle**. |
| Semaphore | The handle is returned by the [CreateSemaphore](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createsemaphorea) or [OpenSemaphore](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-opensemaphorew) function. |
| Thread | The handle is returned by the [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa), [CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread), [CreateRemoteThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createremotethread), or [GetCurrentThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) function |
| Timer | The handle is returned by the [CreateWaitableTimerW](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw) or [OpenWaitableTimerW](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw) function. |
| Transaction | The handle is returned by the [CreateTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransaction) function. |
| Window station | The handle is returned by the [GetProcessWindowStation](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getprocesswindowstation) function. |

You should not use
**DuplicateHandle** to duplicate handles to the following objects:

* I/O completion ports. No error is returned, but the duplicate handle cannot be used.
* Sockets. No error is returned, but the duplicate handle may not be recognized by Winsock at the target process. Also, using **DuplicateHandle** interferes with internal reference counting on the underlying object. To duplicate a socket handle, use the [WSADuplicateSocket](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsaduplicatesocketa) function.
* Pseudo-handles other than the ones returned by the [GetCurrentProcess](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) or [GetCurrentThread](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentthread) functions.

The *dwDesiredAccess* parameter specifies the new handle's access rights. All objects support the [standard access rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights). Objects may also support additional access rights depending on the object type. For more information, see the following topics:

* [Desktop Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights)
* [File Security and Access Rights](https://learn.microsoft.com/windows/desktop/FileIO/file-security-and-access-rights)
* [File-Mapping Security and Access Rights](https://learn.microsoft.com/windows/desktop/Memory/file-mapping-security-and-access-rights)
* [Job Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/job-object-security-and-access-rights)
* [Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights)
* [Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights)
* [Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights)
* [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights)
* [Window-Station Security and Access Rights](https://learn.microsoft.com/windows/desktop/winstation/window-station-security-and-access-rights)

In some cases, the new handle can have more access rights than the original handle. However, in other cases,
**DuplicateHandle** cannot create a handle with more access rights than the original. For example, a file handle created with the GENERIC_READ access right cannot be duplicated so that it has both the GENERIC_READ and GENERIC_WRITE access right.

Normally the target process closes a duplicated handle when that process is finished using the handle. To close a duplicated handle from the source process, call **DuplicateHandle** with the following parameters:

* Set *hSourceProcessHandle* to the target process from the **DuplicateHandle** call that created the handle.
* Set *hSourceHandle* to the duplicated handle to close.
* Set *hTargetProcessHandle* to **NULL**.
* Set *dwOptions* to DUPLICATE_CLOSE_SOURCE.

#### Examples

The following example creates a mutex, duplicates a handle to the mutex, and passes it to another thread. Duplicating the handle ensures that the reference count is increased so that the mutex object will not be destroyed until both threads have closed the handle.

```cpp
#include <windows.h>

DWORD CALLBACK ThreadProc(PVOID pvParam);

int main()
{
    HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
    HANDLE hMutexDup, hThread;
    DWORD dwThreadId;

    DuplicateHandle(GetCurrentProcess(),
                    hMutex,
                    GetCurrentProcess(),
                    &hMutexDup,
                    0,
                    FALSE,
                    DUPLICATE_SAME_ACCESS);

    hThread = CreateThread(NULL, 0, ThreadProc,
        (LPVOID) hMutexDup, 0, &dwThreadId);

    // Perform work here, closing the handle when finished with the
    // mutex. If the reference count is zero, the object is destroyed.
    CloseHandle(hMutex);

    // Wait for the worker thread to terminate and clean up.
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    return 0;
}

DWORD CALLBACK ThreadProc(PVOID pvParam)
{
    HANDLE hMutex = (HANDLE)pvParam;

    // Perform work here, closing the handle when finished with the
    // mutex. If the reference count is zero, the object is destroyed.
    CloseHandle(hMutex);
    return 0;
}

```

## See also

[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle)

[Handle Inheritance](https://learn.microsoft.com/windows/desktop/SysInfo/handle-inheritance)

[Handle and
Object Functions](https://learn.microsoft.com/windows/desktop/SysInfo/handle-and-object-functions)