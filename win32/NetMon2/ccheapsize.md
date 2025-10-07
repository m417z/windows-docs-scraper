# CCHeapSize function

The **CCHeapSize** function returns the size of the memory allocated by the **CCHeapAlloc** function.

## Parameters

*lpMem*

Pointer to the allocated memory.

## Return value

If the function is successful, the return value is the size of the requested memory block measured in bytes.

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

[SetCCInstPtr](https://learn.microsoft.com/windows/win32/netmon2/setccinstptr)

[GetCCInstPtr](https://learn.microsoft.com/windows/win32/netmon2/getccinstptr)

[CCHeapAlloc](https://learn.microsoft.com/windows/win32/netmon2/ccheapalloc)

[CCHeapFree](https://learn.microsoft.com/windows/win32/netmon2/ccheapfree)

[CCHeapReAlloc](https://learn.microsoft.com/windows/win32/netmon2/ccheaprealloc)

