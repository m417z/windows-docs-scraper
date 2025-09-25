# TlsSetValue function

## Description

Stores a value in the calling thread's thread local storage (TLS) slot for the specified TLS index. Each thread of a process has its own slot for each TLS index.

## Parameters

### `dwTlsIndex` [in]

The TLS index that was allocated by the [TlsAlloc](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function.

### `lpTlsValue` [in, optional]

The value to be stored in the calling thread's TLS slot for the index.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later. When a Windows Phone Store app calls this function, it is replaced with an inline call to **FlsSetValue**. Refer to [FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue) for function documentation.

**Windows 8.1**, **Windows Server 2012 R2**, and **Windows 10, version 1507**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and Windows 10, version 1507. When a Windows Store app calls this function, it is replaced with an inline call to **FlsSetValue**. Refer to [FlsSetValue](https://learn.microsoft.com/windows/desktop/api/fibersapi/nf-fibersapi-flssetvalue) for function documentation.

**Windows 10, version 1511** and **Windows 10, version 1607**: This function is fully supported for Universal Windows Platform (UWP) apps, and is no longer replaced with an inline call to **FlsSetValue**.

TLS indexes are typically allocated by the [TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function during process or DLL initialization. When a TLS index is allocated, its storage slots are initialized to NULL. After a TLS index is allocated, each thread of the process can use it to access its own TLS slot for that index. A thread specifies a TLS index in a call to **TlsSetValue**, to store a value in its slot. The thread specifies the same index in a subsequent call to [TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue), to retrieve the stored value.

**TlsSetValue** was implemented with speed as the primary goal. The function performs minimal parameter validation and error checking. In particular, it succeeds if *dwTlsIndex* is in the range 0 through (**TLS_MINIMUM_AVAILABLE** – 1). It is up to the programmer to ensure that the index is valid before calling [TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue).

#### Examples

For an example, see [Using Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/using-thread-local-storage) or [Using Thread Local Storage in a Dynamic-Link Library](https://learn.microsoft.com/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage)

[TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)

[TlsFree](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree)

[TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)