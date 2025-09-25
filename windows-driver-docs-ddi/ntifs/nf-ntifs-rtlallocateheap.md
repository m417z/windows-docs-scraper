# RtlAllocateHeap function

## Description

The **RtlAllocateHeap** routine allocates a block of memory from a heap.

## Parameters

### `HeapHandle` [in]

Handle for a private heap from which the memory will be allocated. This parameter is a handle returned from a successful call to [**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap) .

### `Flags` [in, optional]

Controllable aspects of heap allocation. Specifying any of these values will override the corresponding value specified when the heap was created with **RtlCreateHeap**. This parameter can be one or more of the following values.

| Flag | Meaning |
| ---- | ------- |
| HEAP_GENERATE_EXCEPTIONS | The system will raise an exception to indicate a function failure, such as an out-of-memory condition, instead of returning **NULL**. |
| HEAP_NO_SERIALIZE | Mutual exclusion will not be used while **RtlAllocateHeap** is accessing the heap. |
| HEAP_ZERO_MEMORY | The allocated memory will be initialized to zero. Otherwise, the memory is not initialized to zero. |

### `Size` [in]

Number of bytes to be allocated. If the heap, specified by the *HeapHandle* parameter, is a nongrowable heap, *Size* must be less than or equal to the heap's virtual memory threshold. (For more information, see the **VirtualMemoryThreshold** member of the *Parameters* parameter to [**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap).)

## Return value

If the call to **RtlAllocateHeap** succeeds, the return value is a pointer to the newly-allocated block. The return value is NULL if the allocation failed.

## Remarks

**RtlAllocateHeap** allocates a block of memory of the specified size from the specified heap.

To free a block of memory allocated by **RtlAllocateHeap**, call **RtlFreeHeap**.

Memory allocated by **RtlAllocateHeap** is not movable. Since the memory is not movable, it is possible for the heap to become fragmented.

Serialization ensures mutual exclusion when two or more threads attempt to simultaneously allocate or free blocks from the same heap. There is a small performance cost to serialization, but it must be used whenever multiple threads allocate and free memory from the same heap. Setting the HEAP_NO_SERIALIZE value eliminates mutual exclusion on the heap. Without serialization, two or more threads that use the same heap handle might attempt to allocate or free memory simultaneously, likely causing corruption in the heap. The HEAP_NO_SERIALIZE value can, therefore, be safely used only in the following situations:

- The process has only one thread.

- The process has multiple threads, but only one thread calls the heap functions for a specific heap.

- The process has multiple threads, and the application provides its own mechanism for mutual exclusion to a specific heap.

> [!NOTE]
> To guard against an access violation, use structured exception handling to protect any code that writes to or reads from a heap. For more information about structured exception handling with memory accesses, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

## See also

[**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)

[**RtlDestroyHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldestroyheap)

[**RtlFreeHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlfreeheap)