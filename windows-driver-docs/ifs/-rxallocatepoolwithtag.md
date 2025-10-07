# \_RxAllocatePoolWithTag function

**\_RxAllocatePoolWithTag** allocates memory from a pool with a four-byte tag at the beginning of the block that can be used to help catch instances of memory trashing.

## Parameters

*Type*
The type of the pool to be allocated. This parameter can be one of the following enumeration values for POOL\_TYPE:

**NonPagedPool**
Nonpageable system memory that can be accessed from any IRQL. **NonPagedPool** memory is a scarce resource and drivers should allocate it only when necessary. The system can only allocate buffers larger than PAGE\_SIZE from **NonPagedPool** in multiples of PAGE\_SIZE. Requests for buffers larger than PAGE\_SIZE, but not a PAGE\_SIZE multiple, waste nonpageable memory.

**PagedPool**
Pageable system memory that can only be allocated and accessed at IRQL < DISPATCH\_LEVEL.

*Size*
The size of the memory block, in bytes, to be allocated.

*Tag*
The four-byte tag to be used to mark the allocated buffer. For a description of how to use tags, see [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag). The ASCII value of each character in the tag must be between 0 and 127.

*FileName*
A pointer to the source file name where the memory allocation occurred. This parameter is not currently used.

*LineNumber*
The line number in the source file where the memory allocation occurred. This parameter is not currently used.

## Return value

**RxAllocatePoolWithTag** returns **NULL** if there is insufficient memory in the free pool to satisfy the request. Otherwise, the routine returns a pointer to the allocated memory.

## Remarks

It is recommended that the **RxAllocatePoolWithTag** macro be called instead of using this routine directly. On retail builds, this macro is defined to call [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag). On checked builds, this macro is defined to call **\_RxAllocatePoolWithTag**.

The **\_RxAllocatePoolWithTag** routine calls **ExAllocatePoolWithTagPriority** with the priority (importance of the request) set to LowPoolPriority. The system may fail the request for LowPoolPriority when it runs low on resources. A driver should be prepared to recover from an allocation failure when using this routine.

When the system allocates a buffer from pool memory of PAGE\_SIZE or greater, it aligns the buffer on a page boundary. Memory requests smaller than PAGE\_SIZE are not necessarily aligned on page boundaries, but always fit within a single page, and are aligned on an 8-byte boundary. Any successful allocation that requests a block larger than PAGE\_SIZE that is not a multiple of PAGE\_SIZE wastes all unused bytes on the last-allocated page.

The system associates the pool tag with the allocated memory. Programming tools, such as WinDbg, can display the pool tag associated with each allocated buffer. The value of *Tag* is normally displayed in reverse order. For example, if a caller passes 'Fred' as a *Tag*, it would appear as 'derF' if memory is dumped or when tracking memory usage in the debugger.

Memory allocated with **\_RxAllocatePoolWithTag** should be released by calling [**\_RxFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxfreepool).

Callers of **\_RxAllocatePoolWithTag** must be executing at IRQL <= DISPATCH\_LEVEL. A caller executing at DISPATCH\_LEVEL must specify a **NonPagedPool** value for the *Type* parameter. A caller executing at IRQL <= APC\_LEVEL can specify any POOL\_TYPE value for the *Type* parameter.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Ntrxdef.h (include Ntrxdef.h) |
| IRQL | See Remarks section. |

## See also

[**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[**\_RxCheckMemoryBlock**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxcheckmemoryblock)

[**\_RxFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ifs/-rxfreepool)

