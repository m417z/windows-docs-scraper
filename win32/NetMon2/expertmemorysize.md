# ExpertMemorySize function

The **ExpertMemorySize** function returns the amount of memory allocated by the [ExpertAllocMemory](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory) function.

## Parameters

*hExpertKey* \[in\]

Unique expert identifier. Network Monitor passes *hExpertKey* to the expert when it calls the [Run](https://learn.microsoft.com/windows/win32/netmon2/run) function.

*pOriginalMemory* \[in\]

Pointer to the memory address of the expert allocated by [ExpertAllocMemory](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory).

## Return value

The function returns the amount of allocated memory in bytes.

## Remarks

For information on the **SIZE\_T** data type that **ExpertMemorySize** returns, see Data Types.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Nmapi.lib |
| DLL<br> | Nmapi.dll |

