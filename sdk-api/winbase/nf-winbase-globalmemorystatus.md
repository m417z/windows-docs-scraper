# GlobalMemoryStatus function

## Description

[**GlobalMemoryStatus** can return incorrect information. Use the
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function instead.]

Retrieves information about the system's current usage of both physical and virtual memory.

## Parameters

### `lpBuffer` [out]

A pointer to a
[MEMORYSTATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-memorystatus) structure. The
**GlobalMemoryStatus** function stores information about current memory availability into this structure.

## Remarks

On computers with more than 4 GB of memory, the
**GlobalMemoryStatus** function can return incorrect information, reporting a value of –1 to indicate an overflow. For this reason, applications should use the
[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex) function instead.

On Intel x86 computers with more than 2 GB and less than 4 GB of memory, the
**GlobalMemoryStatus** function will always return 2 GB in the **dwTotalPhys** member of the
[MEMORYSTATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-memorystatus) structure. Similarly, if the total available memory is between 2 and 4 GB, the **dwAvailPhys** member of the
**MEMORYSTATUS** structure will be rounded down to 2 GB. If the executable is linked using the **/LARGEADDRESSAWARE** linker option, then the
**GlobalMemoryStatus** function will return the correct amount of physical memory in both members.

The information returned by the
**GlobalMemoryStatus** function is volatile. There is no guarantee that two sequential calls to this function will return the same information.

## See also

[GlobalMemoryStatusEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-globalmemorystatusex)

[MEMORYSTATUS](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-memorystatus)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))

[Virtual Address Space and Physical Storage](https://learn.microsoft.com/windows/desktop/Memory/virtual-address-space-and-physical-storage)