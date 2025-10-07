# CCHeapAlloc function

The **CCHeapAlloc** function allocates memory on a capture-by-capture basis.

## Parameters

*dwBytes*

Requested length of memory allocated.

*bZeroInit*

Indicator of whether allocated memory was initialized. If the parameter value is **TRUE**, the allocated memory initializes to zero.

## Return value

If the function is successful, the return value is a pointer to the allocated memory. When you have finished using the allocated memory, free the memory by calling the [**CCHeapFree**](https://learn.microsoft.com/windows/win32/netmon2/ccheapfree) function.

If the function is unsuccessful, the return value is **NULL**.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[**SetCCInstPtr**](https://learn.microsoft.com/windows/win32/netmon2/setccinstptr)

[**GetCCInstPtr**](https://learn.microsoft.com/windows/win32/netmon2/getccinstptr)

[**CCHeapFree**](https://learn.microsoft.com/windows/win32/netmon2/ccheapfree)

[**CCHeapReAlloc**](https://learn.microsoft.com/windows/win32/netmon2/ccheaprealloc)

[**CCHeapSize**](https://learn.microsoft.com/windows/win32/netmon2/ccheapsize)

