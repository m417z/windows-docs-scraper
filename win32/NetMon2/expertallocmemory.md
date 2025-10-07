# ExpertAllocMemory function

The **ExpertAllocMemory** function allocates memory for the expert.

## Parameters

*hExpertKey*

Unique expert identifier. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*nBytes* \[in\]

Allocated memory, measured in bytes.

*pError* \[out\]

Error indicator. If the function fails, the *nBytes* parameter contains the error code. If the error code is NMERR\_EXPERT\_TERMINATE, the expert must clean-up and return immediately.

## Return value

If the function is successful, the return value is a pointer to the allocated memory.

If the function is unsuccessful, the return value is **NULL**, and *pError* provides an error code that indicates the reason for the failure.

## Remarks

It is important to note that an expert should use the Network Monitor memory allocation functions (including [ExpertReallocMemory](https://learn.microsoft.com/windows/win32/netmon2/expertreallocmemory)) for memory management. If your expert fails during run time, using these functions will allow Network Monitor to free the memory it has allocated.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

