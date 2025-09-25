# PSECURE_MEMORY_CACHE_CALLBACK callback function

## Description

An application-defined function previously registered with the
[AddSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addsecurememorycachecallback) function
that is called when a secured memory range is freed or its protections are changed.

The **PSECURE_MEMORY_CACHE_CALLBACK** type defines a pointer to this callback
function. *SecureMemoryCacheCallback* is a
placeholder for the application-defined function name.

## Parameters

### `Addr` [in]

The starting address of the memory range.

### `Range` [in]

The size of the memory range, in bytes.

## Return value

The return value indicates the success or failure of this function.

If the caller has secured the specified memory range, this function should unsecure the memory and return
**TRUE**.

If the caller has not secured the specified memory range, this function should return
**FALSE**.

## Remarks

After the callback function is registered, it is called after any attempt to free the specified memory range
or change its protections. If the application has secured any part of the specified memory range, the callback
function must invalidate all of the application's cached memory mappings for the secured memory range, unsecure
the secured parts of the memory range, and return **TRUE**. Otherwise it must return
**FALSE**.

The application secures and unsecures a memory range by sending requests to a device driver, which uses the
MmSecureVirtualMemory and
MmUnsecureVirtualMemory
functions to actually secure and unsecure the range. Operations on other types of secured or locked memory do not
trigger this callback.

Examples of function calls that trigger the callback function include calls to the
[VirtualFree](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfree),
[VirtualFreeEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualfreeex),
[VirtualProtect](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotect),
[VirtualProtectEx](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-virtualprotectex), and
[UnmapViewOfFile](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-unmapviewoffile) functions.

The callback function can also be triggered by a heap operation. In this case, the function must not perform
any further operations on the heap that triggered the callback. This includes calling
[heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) on a private heap or the process's default
heap, or calling standard library functions such as **malloc** and
**free**, which implicitly use the process's default heap.

To unregister the callback function, use the
[RemoveSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-removesecurememorycachecallback)
function.

## See also

[AddSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-addsecurememorycachecallback)

[RemoveSecureMemoryCacheCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-removesecurememorycachecallback)