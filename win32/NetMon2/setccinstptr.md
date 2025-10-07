# SetCCInstPtr function

The **SetCCInstPtr** function captures a context instance pointer.

## Parameters

*lpCurCaptureInst*

Pointer to the instance data added to the capture.

## Return value

None.

## Remarks

Use this function to store a pointer to a block that was allocated with the **CCHeapAlloc** function. Each parser can set a single instance of data on a capture.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

## See also

[GetCCInstPtr](https://learn.microsoft.com/windows/win32/netmon2/getccinstptr)

[CCHeapAlloc](https://learn.microsoft.com/windows/win32/netmon2/ccheapalloc)

[CCHeapFree](https://learn.microsoft.com/windows/win32/netmon2/ccheapfree)

[CCHeapReAlloc](https://learn.microsoft.com/windows/win32/netmon2/ccheaprealloc)

[CCHeapSize](https://learn.microsoft.com/windows/win32/netmon2/ccheapsize)

