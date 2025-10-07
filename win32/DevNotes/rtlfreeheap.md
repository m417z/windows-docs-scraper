# RtlFreeHeap function

Frees a memory block that was allocated from a heap by [**RtlAllocateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap).

## Parameters

*HeapHandle* \[in\]

A handle for the heap whose memory block is to be freed. This parameter is a handle returned by [**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap).

*Flags* \[in, optional\]

A set of flags that controls aspects of freeing a memory block. Specifying the following value overrides the corresponding value that was specified in the *Flags* parameter when the heap was created by [**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap).

| Flag | Meaning |
|--------------------------------|-------------------------------------------------------------------------------------------|
| HEAP\_NO\_SERIALIZE<br> | Mutual exclusion will not be used when **RtlFreeHeap** is accessing the heap. <br> |

*HeapBase* \[in\]

A pointer to the memory block to free. This pointer is returned by [**RtlAllocateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap).

## Return value

Returns **TRUE** if the block was freed successfully; **FALSE** otherwise.

> [!Note]
> Starting with Windows 8 the return value is typed as **LOGICAL**, which has a different size than **BOOLEAN**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Target platform<br> | [Universal](https://msdn.microsoft.com/Library/Windows/Hardware/EB2264A4-BAE8-446B-B9A5-19893936DDCA) |
| Header<br> | Ntifs.h (include Ntifs.h) |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll |

## See also

[**RtlAllocateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlallocateheap)

[**RtlCreateHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlcreateheap)

[**RtlDestroyHeap**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtldestroyheap)

