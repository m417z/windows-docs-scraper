# CCHeapFree function

The **CCHeapFree** function releases the memory allocated by the **CCHeapAlloc** function.

## Parameters

*lpMem*

Pointer to the memory that this function releases.

## Return value

If the **CCHeapFree** function is successful, the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

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

[CCHeapReAlloc](https://learn.microsoft.com/windows/win32/netmon2/ccheaprealloc)

[CCHeapSize](https://learn.microsoft.com/windows/win32/netmon2/ccheapsize)

