# HeapQueryInformation function

## Description

Retrieves information about the specified heap.

## Parameters

### `HeapHandle` [in, optional]

A handle to the heap whose information is to be retrieved. This handle is returned by either the
[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate) or
[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) function.

### `HeapInformationClass` [in]

The class of information to be retrieved. This parameter can be the following value from the **HEAP_INFORMATION_CLASS** enumeration type.

| Value | Meaning |
| --- | --- |
| **HeapCompatibilityInformation**<br><br>0 | Indicates the heap features that are enabled. <br><br>The *HeapInformation* parameter is a pointer to a **ULONG** variable.<br><br>If *HeapInformation* is 0, the heap is a standard heap that does not support look-aside lists.<br><br>If *HeapInformation* is 1, the heap supports look-aside lists. For more information, see Remarks.<br><br>If *HeapInformation* is 2, the [low-fragmentation heap](https://learn.microsoft.com/windows/desktop/Memory/low-fragmentation-heap) (LFH) has been enabled for the heap. Enabling the LFH disables look-aside lists. |

### `HeapInformation` [out]

A pointer to a buffer that receives the heap information. The format of this data depends on the value of the *HeapInformationClass* parameter.

### `HeapInformationLength` [in]

The size of the heap information being queried, in bytes.

### `ReturnLength` [out, optional]

A pointer to a variable that receives the length of data written to the *HeapInformation* buffer. If the buffer is too small, the function fails and *ReturnLength* specifies the minimum size required for the buffer.

If you do not want to receive this information, specify **NULL**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To enable the
LFH or the terminate-on-corruption feature, use the
[HeapSetInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsetinformation) function.

**Windows XP and Windows Server 2003:**  A look-aside list is a fast memory allocation mechanism that contains only fixed-sized blocks. Look-aside lists are enabled by default for heaps that support them. Starting with Windows Vista, look-aside lists are not used and the LFH is enabled by default.

Look-aside lists are faster than general pool allocations that vary in size, because the system does not search for free memory that fits the allocation. In addition, access to look-aside lists is generally synchronized using fast atomic processor exchange instructions instead of mutexes or spinlocks. Look-aside lists can be created by the system or drivers. They can be allocated from paged or nonpaged pool.

#### Examples

The following example uses [GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap) to
obtain a handle to the default process heap and
**HeapQueryInformation** to retrieve information
about the heap.

```cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

#define HEAP_STANDARD 0
#define HEAP_LAL 1
#define HEAP_LFH 2

int __cdecl _tmain()
{
    BOOL bResult;
    HANDLE hHeap;
    ULONG HeapInformation;

    //
    // Get a handle to the default process heap.
    //
    hHeap = GetProcessHeap();
    if (hHeap == NULL) {
        _tprintf(TEXT("Failed to retrieve default process heap with LastError %d.\n"),
                 GetLastError());
        return 1;
    }

    //
    // Query heap features that are enabled.
    //
    bResult = HeapQueryInformation(hHeap,
                                   HeapCompatibilityInformation,
                                   &HeapInformation,
                                   sizeof(HeapInformation),
                                   NULL);
    if (bResult == FALSE) {
        _tprintf(TEXT("Failed to retrieve heap features with LastError %d.\n"),
                 GetLastError());
        return 1;
    }

    //
    // Print results of the query.
    //
    _tprintf(TEXT("HeapCompatibilityInformation is %d.\n"), HeapInformation);
    switch(HeapInformation)
    {
    case HEAP_STANDARD:
        _tprintf(TEXT("The default process heap is a standard heap.\n"));
        break;
    case HEAP_LAL:
        _tprintf(TEXT("The default process heap supports look-aside lists.\n"));
        break;
    case HEAP_LFH:
        _tprintf(TEXT("The default process heap has the low-fragmentation ") \
                 TEXT("heap enabled.\n"));
        break;
    default:
        _tprintf(TEXT("Unrecognized HeapInformation reported for the default ") \
                 TEXT("process heap.\n"));
        break;
     }

    return 0;
}

```

## See also

[GetProcessHeap](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-getprocessheap)

[Heap Functions](https://learn.microsoft.com/windows/desktop/Memory/heap-functions)

[HeapCreate](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapcreate)

[HeapSetInformation](https://learn.microsoft.com/windows/desktop/api/heapapi/nf-heapapi-heapsetinformation)

[Memory Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)