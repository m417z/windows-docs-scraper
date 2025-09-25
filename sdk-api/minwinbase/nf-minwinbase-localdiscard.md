# LocalDiscard macro

## Syntax

```cpp
HLOCAL LocalDiscard(
  [in]  HLOCAL h
);
```

## Return value

Type: **[HLOCAL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, the return value is a handle to the local memory object.If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Description

Discards the specified local memory object. The lock count of the memory object must be zero.

**Note** The local functions have greater overhead and provide fewer features than other memory management functions. New applications should use the [heap functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions) unless documentation states that a local function should be used. For more information, see [Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions).

## Parameters

### `h` [in]

A handle to the local memory object. This handle is returned by either the
[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc) or
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function.

## Remarks

Although
**LocalDiscard** discards the object's memory block, the handle to the object remains valid. A process can subsequently pass the handle to the
[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc) function to allocate another local memory object identified by the same handle.

## See also

[Global and Local Functions](https://learn.microsoft.com/windows/desktop/Memory/global-and-local-functions)

[LocalAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localalloc)

[LocalReAlloc](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localrealloc)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)