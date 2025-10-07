# ExpertReallocMemory function

The **ExpertReallocMemory** function increases or decreases the amount of memory allocated by Network Monitor.

## Parameters

*hExpertKey* \[in\]

Unique identifier passed to the expert at [**Run**](https://learn.microsoft.com/windows/win32/netmon2/run) or [**Configure**](https://learn.microsoft.com/windows/win32/netmon2/configure).

*pOriginalMemory* \[in\]

Pointer to the memory allocated by Network Monitor. The *pOriginalMemory* pointer can be returned by a previous call to [**ExpertAllocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory) or **ExpertReallocMemory**.

*nBytes* \[in\]

Size of reallocated memory.

*pError* \[out\]

On return, an error code if the function fails. If the error code is NMERR\_EXPERT\_TERMINATE, the expert must clean up and return immediately.

## Return value

If the function is successful, the return value is a pointer to the allocated memory.

If the function is unsuccessful, the return value is **NULL**, and *pError* (if it is a non-**NULL** value) indicates the reason for the failure.

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

