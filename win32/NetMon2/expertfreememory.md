# ExpertFreeMemory function

The **ExpertFreeMemory** function frees memory acquired by calls to the [**ExpertAllocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory) and [**ExpertReallocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertreallocmemory) functions.

## Parameters

*hExpertKey*

Unique expert identifier. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*pMemory* \[in\]

Pointer to the memory that Network Monitor allocates. The *pMemory* pointer can be returned by a previous call to [**ExpertAllocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory) or [**ExpertReallocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertreallocmemory).

## Return value

If the function is successful. the return value is NMERR\_SUCCESS.

If the function is unsuccessful, the return value indicates the reason for the failure. If the return value is NMERR\_EXPERT\_TERMINATE, the expert immediately cleans up and returns.

## Remarks

It is important to note that an expert should use the Network Monitor memory allocation functions for memory management. If your expert fails during run time, using these functions will allow Network Monitor to free the memory it has allocated.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

