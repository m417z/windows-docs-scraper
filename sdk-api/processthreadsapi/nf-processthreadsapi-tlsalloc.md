# TlsAlloc function

## Description

Allocates a thread local storage (TLS) index. Any thread of the process can subsequently use this index to store and retrieve values that are local to the thread, because each thread receives its own slot for the index.

## Return value

If the function succeeds, the return value is a TLS index. The slots for the index are initialized to zero.

If the function fails, the return value is **TLS_OUT_OF_INDEXES**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later. When a Windows Phone Store app calls this function, it is replaced with an inline call to **FlsAlloc**. Refer to [FlsAlloc](https://learn.microsoft.com/windows/win32/api/fibersapi/nf-fibersapi-flsalloc) for function documentation.

**Windows 8.1**, **Windows Server 2012 R2**, and **Windows 10, version 1507**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and Windows 10, version 1507. When a Windows Store app calls this function, it is replaced with an inline call to **FlsAlloc**. Refer to [FlsAlloc](https://learn.microsoft.com/windows/win32/api/fibersapi/nf-fibersapi-flsalloc) for function documentation.

**Windows 10, version 1511** and **Windows 10, version 1607**: This function is fully supported for Universal Windows Platform (UWP) apps, and is no longer replaced with an inline call to **FlsAlloc**.

The threads of the process can use the TLS index in subsequent calls to the [TlsFree](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree), [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue), or [TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) functions. The value of the TLS index should be treated as an opaque value; do not assume that it is an index into a zero-based array.

TLS indexes are typically allocated during process or dynamic-link library (DLL) initialization. When a TLS index is allocated, its storage slots are initialized to **NULL**. After a TLS index has been allocated, each thread of the process can use it to access its own TLS storage slot. To store a value in its TLS slot, a thread specifies the index in a call to [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue). The thread specifies the same index in a subsequent call to [TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue), to retrieve the stored value.

TLS indexes are not valid across process boundaries. A DLL cannot assume that an index assigned in one process is valid in another process.

#### Examples

For an example, see [Using Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/using-thread-local-storage) or [Using Thread Local Storage in a Dynamic-Link Library](https://learn.microsoft.com/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage)

[TlsFree](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree)

[TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)

[TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)