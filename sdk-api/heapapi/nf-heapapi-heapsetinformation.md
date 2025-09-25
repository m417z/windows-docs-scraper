# HeapSetInformation function

## Description

Enables features for a specified heap.

## Parameters

### `HeapHandle` [in, optional]

A handle to the heap where information is to be set. This handle is returned by either the
[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or
[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `HeapInformationClass` [in]

The class of information to be set. This parameter can be one of the following values from the
**HEAP_INFORMATION_CLASS** enumeration type.

| Value | Meaning |
| --- | --- |
| **HeapCompatibilityInformation**<br><br>0 | Enables heap features. Only the [low-fragmentation heap](https://learn.microsoft.com/windows/desktop/Memory/low-fragmentation-heap) (LFH) is supported. However, it is not necessary for applications to enable the LFH because the system uses the LFH as needed to service memory allocation requests.<br><br>**Windows XP and Windows Server 2003:** The LFH is not enabled by default. To enable the LFH for the specified heap, set the variable pointed to by the *HeapInformation* parameter to 2. After the LFH is enabled for a heap, it cannot be disabled.<br><br>The LFH cannot be enabled for heaps created with **HEAP_NO_SERIALIZE** or for heaps created with a fixed size. The LFH also cannot be enabled if you are using the heap debugging tools in [Debugging Tools for Windows](https://learn.microsoft.com/windows-hardware/drivers/debugger/) or [Microsoft Application Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/application-verifier).<br><br>When a process is run under any debugger, certain heap debug options are automatically enabled for all heaps in the process. These heap debug options prevent the use of the LFH. To enable the low-fragmentation heap when running under a debugger, set the _NO_DEBUG_HEAP environment variable to 1. |
| **HeapEnableTerminationOnCorruption**<br><br>1 | Enables the terminate-on-corruption feature. If the heap manager detects an error in any heap used by the process, it calls the Windows Error Reporting service and terminates the process.<br><br>After a process enables this feature, it cannot be disabled.<br><br>**Windows Server 2003 and Windows XP:** This value is not supported until Windows Vista and Windows XP with SP3. The function succeeds but the **HeapEnableTerminationOnCorruption** value is ignored. |
| **HeapOptimizeResources**<br><br>3 | If HeapSetInformation is called with *HeapHandle* set to NULL, then all heaps in the process with a [low-fragmentation heap](https://learn.microsoft.com/windows/desktop/Memory/low-fragmentation-heap) (LFH) will have their caches optimized, and the memory will be decommitted if possible. <br><br>If a heap pointer is supplied in *HeapHandle*, then only that heap will be optimized.<br><br>Note that the HEAP_OPTIMIZE_RESOURCES_INFORMATION structure passed in *HeapInformation* must be properly initialized.<br><br>**Note** This value was added in Windows 8.1. |

### `HeapInformation` [in]

The heap information buffer. The format of this data depends on the value of the
*HeapInformationClass* parameter.

If the *HeapInformationClass* parameter is
**HeapCompatibilityInformation**, the *HeapInformation*
parameter is a pointer to a **ULONG** variable.

If the *HeapInformationClass* parameter is
**HeapEnableTerminationOnCorruption**, the *HeapInformation*
parameter should be **NULL** and *HeapInformationLength* should
be 0

### `HeapInformationLength` [in]

The size of the *HeapInformation* buffer, in bytes.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To retrieve the current settings for the heap, use the
[HeapQueryInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapqueryinformation) function.

Setting the **HeapEnableTerminateOnCorruption** option is strongly recommended because
it reduces an application's exposure to security exploits that take advantage of a corrupted heap.

#### Examples

The following example shows you how to enable the low-fragmentation heap.

```cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define HEAP_LFH 2

int __cdecl _tmain()
{
    BOOL bResult;
    HANDLE hHeap;
    ULONG HeapInformation;

    //
    // Enable heap terminate-on-corruption.
    // A correct application can continue to run even if this call fails,
    // so it is safe to ignore the return value and call the function as follows:
    // (void)HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);
    // If the application requires heap terminate-on-corruption to be enabled,
    // check the return value and exit on failure as shown in this example.
    //
    bResult = HeapSetInformation(NULL,
                                 HeapEnableTerminationOnCorruption,
                                 NULL,
                                 0);

    if (bResult != FALSE) {
        _tprintf(TEXT("Heap terminate-on-corruption has been enabled.\n"));
    }
    else {
        _tprintf(TEXT("Failed to enable heap terminate-on-corruption with LastError %d.\n"),
                 GetLastError());
        return 1;
    }

    //
    // Create a new heap with default parameters.
    //
    hHeap = HeapCreate(0, 0, 0);
    if (hHeap == NULL) {
        _tprintf(TEXT("Failed to create a new heap with LastError %d.\n"),
                 GetLastError());
        return 1;
    }

    //
    // Enable the low-fragmentation heap (LFH). Starting with Windows Vista,
    // the LFH is enabled by default but this call does not cause an error.
    //
    HeapInformation = HEAP_LFH;
    bResult = HeapSetInformation(hHeap,
                                 HeapCompatibilityInformation,
                                 &HeapInformation,
                                 sizeof(HeapInformation));
    if (bResult != FALSE) {
        _tprintf(TEXT("The low-fragmentation heap has been enabled.\n"));
    }
    else {
        _tprintf(TEXT("Failed to enable the low-fragmentation heap with LastError %d.\n"),
                 GetLastError());
        return 1;
    }

    return 0;
}

```

## See also

[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap)

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate)

[HeapQueryInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapqueryinformation)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)