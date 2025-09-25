## Description

Retrieves the value in the calling thread's thread local storage (TLS) slot for the specified TLS index. Each thread of a process has its own slot for each TLS index.

## Parameters

### `dwTlsIndex` [in]

The TLS index that was allocated by the [TlsAlloc function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc).

## Return value

If the function succeeds, the return value is the value stored in the calling thread's TLS slot associated with the specified index. If *dwTlsIndex* is a valid index allocated by a successful call to [TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc), this function always succeeds.

If the function fails, the return value is zero.

## Remarks

TLS indexes are typically allocated by the [TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc) function during process or DLL initialization. After a TLS index is allocated, each thread of the process can use it to access its own TLS slot for that index. A thread specifies a TLS index in a call to [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) to store a value in its slot. The thread specifies the same index in a subsequent call to **TlsGetValue2** to retrieve the stored value.

**TlsGetValue2** was implemented with speed as the primary goal. The function performs minimal parameter validation and error checking. In particular, it succeeds if *dwTlsIndex* is in the range 0 through (**TLS_MINIMUM_AVAILABLE**– 1). It is up to the programmer to ensure that the index is valid and that the thread calls [TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue) before calling **TlsGetValue2**.

This function is identical to [**TlsGetValue**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsgetvalue) except that it doesn't set the thread's last error. Applications calling this function should avoid using 0 as a valid value, because **GetLastError** cannot be called to check if the function failed.

### Examples

See [Using Thread Local Storage](https://learn.microsoft.com/windows/desktop/ProcThread/using-thread-local-storage) or [Using Thread Local Storage in a Dynamic-Link Library](https://learn.microsoft.com/windows/desktop/Dlls/using-thread-local-storage-in-a-dynamic-link-library).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Thread Local Storage](https://learn.microsoft.com/windows/win32/ProcThread/thread-local-storage)

[TlsAlloc](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)

[TlsFree](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsfree)

[TlsSetValue](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlssetvalue)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)