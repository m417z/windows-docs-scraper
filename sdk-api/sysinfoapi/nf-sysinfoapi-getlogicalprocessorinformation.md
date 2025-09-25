# GetLogicalProcessorInformation function

## Description

Retrieves information about logical processors and related hardware.

To retrieve information about logical processors and related hardware, including processor groups, use the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function.

## Parameters

### `Buffer` [out]

A pointer to a buffer that receives an array of [SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information) structures. If the function fails, the contents of this buffer are undefined.

### `ReturnedLength` [in, out]

On input, specifies the length of the buffer pointed to by *Buffer*, in bytes. If the buffer is large enough to contain all of the data, this function succeeds and *ReturnLength* is set to the number of bytes returned. If the buffer is not large enough to contain all of the data, the function fails, [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, and *ReturnLength* is set to the buffer length required to contain all of the data. If the function fails with an error other than ERROR_INSUFFICIENT_BUFFER, the value of *ReturnLength* is undefined.

## Return value

If the function succeeds, the return value is TRUE and at least one [SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information) structure is written to the output buffer.

If the function fails, the return value is FALSE. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetLogicalProcessorInformation** can be used to get information about the relationship between logical processors in the system, including:

* The logical processors that are part of a [NUMA](https://learn.microsoft.com/windows/desktop/ProcThread/numa-support) node.
* The logical processors that share resources. An example of this type of resource sharing would be hyperthreading scenarios.

Your application can use this information when affinitizing your threads and processes to take best advantage of the hardware properties of the platform, or to determine the number of logical and physical processors for licensing purposes.

Each of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information) structures returned in the buffer contains the following:

* A logical processor affinity mask, which indicates the logical processors that the information in the structure applies to.
* A logical processor mask of type [LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship), which indicates the relationship between the logical processors in the mask. Applications calling this function must be prepared to handle additional indicator values in the future.

Note that the order in which the structures are returned in the buffer may change between calls to this function.

The size of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information) structure varies between processor architectures and versions of Windows. For this reason, applications should first call this function to obtain the required buffer size, then dynamically allocate memory for the buffer.

On systems with more than 64 logical processors, the **GetLogicalProcessorInformation** function retrieves logical processor information about processors in the [processor group](https://learn.microsoft.com/windows/desktop/ProcThread/processor-groups) to which the calling thread is currently assigned. Use the [GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex) function to retrieve information about processors in all processor groups on the system.

> [!NOTE]
> Starting with *TBD Release Iron*, the behavior of this and other NUMA functions has been modified to better support systems with nodes containing more that 64 processors. For more information about this change, including information about enabling the old behavior of this API, see [NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support).

### Behavior starting with TBD Release Iron

The relationship structures for [RelationNumaNode](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-logical_processor_relationship) contain the affinity mask for the node's affinity within the calling thread's group.

#### Examples

The following C++ example uses the **GetLogicalProcessorInformation** function to display information about processors on the current system. Because **GetLogicalProcessorInformation** is not present on all systems, this example uses the [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function instead of calling **GetLogicalProcessorInformation** directly.

This example reports the number of active processor cores. This example also reports the number of NUMA nodes, physical packages, and caches on systems that support this information. For more information, see the description of the **Relationship** member of the [SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information) structure. **Windows Server 2003, Windows XP Professional x64 Edition and Windows XP with SP3:** This example reports the number of physical processors rather than the number of active processor cores.

```cpp

#include <windows.h>
#include <malloc.h>
#include <stdio.h>
#include <tchar.h>

typedef BOOL (WINAPI *LPFN_GLPI)(
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION,
    PDWORD);

// Helper function to count set bits in the processor mask.
DWORD CountSetBits(ULONG_PTR bitMask)
{
    DWORD LSHIFT = sizeof(ULONG_PTR)*8 - 1;
    DWORD bitSetCount = 0;
    ULONG_PTR bitTest = (ULONG_PTR)1 << LSHIFT;
    DWORD i;

    for (i = 0; i <= LSHIFT; ++i)
    {
        bitSetCount += ((bitMask & bitTest)?1:0);
        bitTest/=2;
    }

    return bitSetCount;
}

int _cdecl _tmain ()
{
    LPFN_GLPI glpi;
    BOOL done = FALSE;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer = NULL;
    PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ptr = NULL;
    DWORD returnLength = 0;
    DWORD logicalProcessorCount = 0;
    DWORD numaNodeCount = 0;
    DWORD processorCoreCount = 0;
    DWORD processorL1CacheCount = 0;
    DWORD processorL2CacheCount = 0;
    DWORD processorL3CacheCount = 0;
    DWORD processorPackageCount = 0;
    DWORD byteOffset = 0;
    PCACHE_DESCRIPTOR Cache;

    glpi = (LPFN_GLPI) GetProcAddress(
                            GetModuleHandle(TEXT("kernel32")),
                            "GetLogicalProcessorInformation");
    if (NULL == glpi)
    {
        _tprintf(TEXT("\nGetLogicalProcessorInformation is not supported.\n"));
        return (1);
    }

    while (!done)
    {
        DWORD rc = glpi(buffer, &returnLength);

        if (FALSE == rc)
        {
            if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
            {
                if (buffer)
                    free(buffer);

                buffer = (PSYSTEM_LOGICAL_PROCESSOR_INFORMATION)malloc(
                        returnLength);

                if (NULL == buffer)
                {
                    _tprintf(TEXT("\nError: Allocation failure\n"));
                    return (2);
                }
            }
            else
            {
                _tprintf(TEXT("\nError %d\n"), GetLastError());
                return (3);
            }
        }
        else
        {
            done = TRUE;
        }
    }

    ptr = buffer;

    while (byteOffset + sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION) <= returnLength)
    {
        switch (ptr->Relationship)
        {
        case RelationNumaNode:
            // Non-NUMA systems report a single record of this type.
            numaNodeCount++;
            break;

        case RelationProcessorCore:
            processorCoreCount++;

            // A hyperthreaded core supplies more than one logical processor.
            logicalProcessorCount += CountSetBits(ptr->ProcessorMask);
            break;

        case RelationCache:
            // Cache data is in ptr->Cache, one CACHE_DESCRIPTOR structure for each cache.
            Cache = &ptr->Cache;
            if (Cache->Level == 1)
            {
                processorL1CacheCount++;
            }
            else if (Cache->Level == 2)
            {
                processorL2CacheCount++;
            }
            else if (Cache->Level == 3)
            {
                processorL3CacheCount++;
            }
            break;

        case RelationProcessorPackage:
            // Logical processors share a physical package.
            processorPackageCount++;
            break;

        default:
            _tprintf(TEXT("\nError: Unsupported LOGICAL_PROCESSOR_RELATIONSHIP value.\n"));
            break;
        }
        byteOffset += sizeof(SYSTEM_LOGICAL_PROCESSOR_INFORMATION);
        ptr++;
    }

    _tprintf(TEXT("\nGetLogicalProcessorInformation results:\n"));
    _tprintf(TEXT("Number of NUMA nodes: %d\n"),
             numaNodeCount);
    _tprintf(TEXT("Number of physical processor packages: %d\n"),
             processorPackageCount);
    _tprintf(TEXT("Number of processor cores: %d\n"),
             processorCoreCount);
    _tprintf(TEXT("Number of logical processors: %d\n"),
             logicalProcessorCount);
    _tprintf(TEXT("Number of processor L1/L2/L3 caches: %d/%d/%d\n"),
             processorL1CacheCount,
             processorL2CacheCount,
             processorL3CacheCount);

    free(buffer);

    return 0;
}

```

## See also

[GetLogicalProcessorInformationEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-getlogicalprocessorinformationex)

[LOGICAL_PROCESSOR_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-logical_processor_relationship)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SYSTEM_LOGICAL_PROCESSOR_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-system_logical_processor_information)