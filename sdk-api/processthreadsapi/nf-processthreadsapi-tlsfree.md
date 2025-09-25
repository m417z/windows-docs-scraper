# TlsFree function

## Description

Releases a thread local storage (TLS) index, making it available for reuse.

## Parameters

### `dwTlsIndex` [in]

The TLS index that was allocated by the [TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**Windows Phone 8.1:** This function is supported for Windows Phone Store apps on Windows Phone 8.1 and later. When a Windows Phone Store app calls this function, it is replaced with an inline call to **FlsFree**. Refer to [FlsFree](https://learn.microsoft.com/windows/win32/api/fibersapi/nf-fibersapi-flsfree) for function documentation.

**Windows 8.1**, **Windows Server 2012 R2**, and **Windows 10, version 1507**: This function is supported for Windows Store apps on Windows 8.1, Windows Server 2012 R2, and Windows 10, version 1507. When a Windows Store app calls this function, it is replaced with an inline call to **FlsFree**. Refer to [FlsFree](https://learn.microsoft.com/windows/win32/api/fibersapi/nf-fibersapi-flsfree) for function documentation.

**Windows 10, version 1511** and **Windows 10, version 1607**: This function is fully supported for Universal Windows Platform (UWP) apps, and is no longer replaced with an inline call to **FlsFree**.

If the threads of the process have allocated memory and stored a pointer to the memory in a TLS slot, they should free the memory before calling
**TlsFree**. The **TlsFree** function does not free memory blocks whose addresses have been stored in the TLS slots associated with the TLS index. It is expected that DLLs call this function (if at all) only during **DLL_PROCESS_DETACH**.

For more information, see [Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage).

#### Examples

For an example, see [Using Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/using-thread-local-storage) or [Using Thread Local Storage in a Dynamic-Link Library](https://learn.microsoft.com/windows/win32/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

## See also

[Processes and Threads Overview](https://learn.microsoft.com/windows/win32/ProcThread/processes-and-threads)

[Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage)

[TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)

[TlsGetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue)

[TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)