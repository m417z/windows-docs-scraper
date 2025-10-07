# ObFindHandleForObject function

\[This function is obsolete and may be altered or unavailable in future versions of Windows. Avoid using this function.\]

Retrieves an object handle for the specified object associated with the specified process.

## Parameters

*Process* \[in\]

The process. This handle is returned by the **IoGetCurrentProcess** or **PsGetCurrentProcess** function.

*Object* \[in\]

A pointer to the object.

*Reserved1* \[in, optional\]

Reserved.

*Reserved2* \[in, optional\]

Reserved.

*Handle* \[out\]

The object handle.

## Return value

The function returns **TRUE** if a match is found and **FALSE** otherwise.

## Remarks

This function is available in Ntoskrnl.exe and can be called only from kernel mode. The corresponding import library is available through the Windows Driver Kit (WDK).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Ntosp.h |
| Library<br> | Ntoskrnl.lib |

