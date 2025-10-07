# CCHeapReAlloc function

The **CCHeapReAlloc** function reallocates memory allocated by the **CCHeapAlloc** function.

## Parameters

*lpMem*

Pointer to the original allocated memory.

*dwBytes*

Size of the reallocated memory, measured in bytes.

*bZeroInit*

Indicator of whether reallocated memory was initialized. If the parameter value is **TRUE**, the newly reallocated memory initializes to zero.

## Return value

If the function is successful, the return value is a pointer to the reallocated memory.

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

[CCHeapSize](https://learn.microsoft.com/windows/win32/netmon2/ccheapsize)

