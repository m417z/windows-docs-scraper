# TlsGetValue function

## Description

Retrieves the value in the calling thread's thread local storage (TLS) slot for the specified TLS index. Each thread of a process has its own slot for each TLS index.

## Parameters

### `dwTlsIndex` [in]

The TLS index that was allocated by the [TlsAlloc](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function.

## Return value

If the function succeeds, the return value is the value stored in the calling thread's TLS slot associated with the specified index. If *dwTlsIndex* is a valid index allocated by a successful call to [TlsAlloc](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc), this function always succeeds.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

The data stored in a TLS slot can have a value of 0 because it still has its initial value or because the thread called the [TlsSetValue](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) function with 0. Therefore, if the return value is 0, you must check whether [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_SUCCESS** before determining that the function has failed. If **GetLastError** returns **ERROR_SUCCESS**, then the function has succeeded and the data stored in the TLS slot is 0. Otherwise, the function has failed.

Functions that return indications of failure call [SetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setlasterror) when they fail. They generally do not call **SetLastError** when they succeed. The **TlsGetValue** function is an exception to this general rule. The **TlsGetValue** function calls **SetLastError** to clear a thread's last error when it succeeds. That allows checking for the error-free retrieval of zero values.

## Remarks

**Windows 8.1**, **Windows Server 2012 R2**, and **Windows 10, version 1507**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and Windows 10, version 1507. When a Windows Store app calls this function, it is replaced with an inline call to **FlsGetValue**. Refer to [FlsGetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flsgetvalue) for function documentation.

**Windows 10, version 1511** and **Windows 10, version 1607**: This function is fully supported for Universal Windows Platform (UWP) apps, and is no longer replaced with an inline call to **FlsGetValue**.

TLS indexes are typically allocated by the [TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function during process or DLL initialization. After a TLS index is allocated, each thread of the process can use it to access its own TLS slot for that index. A thread specifies a TLS index in a call to [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) to store a value in its slot. The thread specifies the same index in a subsequent call to **TlsGetValue** to retrieve the stored value.

**TlsGetValue** was implemented with speed as the primary goal. The function performs minimal parameter validation and error checking. In particular, it succeeds if *dwTlsIndex* is in the range 0 through (**TLS_MINIMUM_AVAILABLE**– 1). It is up to the programmer to ensure that the index is valid and that the thread calls [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) before calling **TlsGetValue**.

**TlsGetValue** always sets a thread's last error. In some cases, an application (such as those with custom heaps that support malloc) may need to call **GetLastError** before calling **TlsGetValue** to save the thread's last error (followed by **SetLastError** to restore the saved error). Unfortunately, this can incur a non-trivial performance cost on certain CPUs.

**Windows 11 24H2 and later:** Use the [**TlsGetValue2**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue2) function, which is identical to **TlsGetValue** except that it doesn't set the thread's last error. Applications calling **TlsGetValue2** should avoid using 0 as a valid value because **GetLastError** cannot be called to check if **TlsGetValue2** failed.

#### Examples

For an example, see [Using Thread Local Storage](https://learn.microsoft.com/windows/desktop/ProcThread/using-thread-local-storage) or [Using Thread Local Storage in a Dynamic-Link Library](https://learn.microsoft.com/windows/desktop/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

## See also

[**TlsGetValue2**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue2)

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage)

[TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)

[TlsFree](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree)

[TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)