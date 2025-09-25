# AddSecureMemoryCacheCallback function

## Description

Registers a callback function to be called when a secured memory range is freed or its protections are
changed.

## Parameters

### `pfnCallBack` [in]

A pointer to the application-defined
[SecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-psecure_memory_cache_callback) function to
register.

## Return value

If the function succeeds, it registers the callback function and returns
**TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

An application that performs I/O directly to a high-performance device typically caches a virtual-to-physical
memory mapping for the buffer it uses for the I/O. The device's driver typically secures this memory address range
by calling the [MmSecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntddk/nf-ntddk-mmsecurevirtualmemory) routine,
which prevents the memory range from being freed or its protections changed until the driver unsecures the
memory.

An application can use
**AddSecureMemoryCacheCallback** to register
a callback function that will be called when the memory is freed or its protections are changed, so the
application can invalidate its cached memory mapping. For more information, see
[SecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-psecure_memory_cache_callback).

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0600
or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[RemoveSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-removesecurememorycachecallback)

[SecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-psecure_memory_cache_callback)