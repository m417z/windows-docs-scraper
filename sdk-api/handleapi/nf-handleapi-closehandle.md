# CloseHandle function

## Description

Closes an open object handle.

## Parameters

### `hObject` [in]

A valid handle to an open object.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the application is running under a debugger, the function will throw an exception if it receives either a handle value that is not valid or a pseudo-handle value. This can happen if you close a handle twice, or if you call
**CloseHandle** on a handle returned by the
[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea) function instead of calling the [FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose) function.

## Remarks

The
**CloseHandle** function closes handles to the following objects:

* Access token
* Communications device
* Console input
* Console screen buffer
* Event
* File
* File mapping
* I/O completion port
* Job
* Mailslot
* Memory resource notification
* Mutex
* Named pipe
* Pipe
* Process
* Semaphore
* Thread
* Transaction
* Waitable timer

The documentation for the functions that create these objects indicates that **CloseHandle** should be used when you are finished with the object, and what happens to pending operations on the object after the handle is closed. In general, **CloseHandle** invalidates the specified object handle, decrements the object's handle count, and performs object retention checks. After the last handle to an object is closed, the object is removed from the system. For a summary of the creator functions for these objects, see [Kernel Objects](https://learn.microsoft.com/windows/desktop/SysInfo/kernel-objects).

Generally, an application should call **CloseHandle** once for each handle it opens. It is usually not necessary to call **CloseHandle** if a function that uses a handle fails with ERROR_INVALID_HANDLE, because this error usually indicates that the handle is already invalidated. However, some functions use ERROR_INVALID_HANDLE to indicate that the object itself is no longer valid. For example, a function that attempts to use a handle to a file on a network might fail with ERROR_INVALID_HANDLE if the network connection is severed, because the file object is no longer available. In this case, the application should close the handle.

If a handle is transacted, all handles bound to a transaction should be closed before the transaction is committed. If a transacted handle was opened by calling [CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda) with the FILE_FLAG_DELETE_ON_CLOSE flag, the file is not deleted until the application closes the handle and calls [CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction). For more information about transacted objects, see [Working With Transactions](https://learn.microsoft.com/windows/desktop/Ktm/programming-model).

Closing a thread handle does not terminate the associated thread or remove the thread object. Closing a process handle does not terminate the associated process or remove the process object. To remove a thread object, you must terminate the thread, then close all handles to the thread. For more information, see [Terminating a Thread](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-thread). To remove a process object, you must terminate the process, then close all handles to the process. For more information, see [Terminating a Process](https://learn.microsoft.com/windows/desktop/ProcThread/terminating-a-process).

Closing a handle to a file mapping can succeed even when there are file views that are still open. For more information, see [Closing a File Mapping Object](https://learn.microsoft.com/windows/desktop/Memory/closing-a-file-mapping-object).

Do not use the **CloseHandle** function to close a socket. Instead, use the [closesocket](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-closesocket) function, which releases all resources associated with the socket including the handle to the socket object. For more information, see [Socket Closure](https://learn.microsoft.com/windows/desktop/WinSock/graceful-shutdown-linger-options-and-socket-closure-2).

Do not use the **CloseHandle** function to close a handle to an open registry key. Instead, use the [RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey) function. **CloseHandle** does not close the handle to the registry key, but does not return an error to indicate this failure.

#### Examples

```cpp
dwPriorityClass = 0;
hProcess = OpenProcess( PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID );
if( hProcess == NULL )
	printError( TEXT("OpenProcess") );
else
{
	dwPriorityClass = GetPriorityClass( hProcess );
	if( !dwPriorityClass )
	printError( TEXT("GetPriorityClass") );
	CloseHandle( hProcess );
}
```

To see this example in context, see
[Taking a Snapshot and Viewing Processes](https://learn.microsoft.com/windows/desktop/ToolHelp/taking-a-snapshot-and-viewing-processes).

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[CreateFileTransacted](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiletransacteda)

[DeleteFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-deletefilea)

[FindClose](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findclose)

[FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea)

[Handle and
Object Functions](https://learn.microsoft.com/windows/desktop/SysInfo/handle-and-object-functions)

[Kernel Objects](https://learn.microsoft.com/windows/desktop/SysInfo/kernel-objects)

[Object Interface](https://learn.microsoft.com/windows/desktop/SysInfo/object-interface)