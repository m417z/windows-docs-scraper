## Description

This routine is a wrapper and replacement option for [**ExAllocatePoolWithTagPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority).

**ExAllocatePoolPriorityUninitialized** allocates pool memory of the specified type.

## Parameters

### `PoolType`

The type of pool memory to allocate. For a description of the available pool memory types, see [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type).

You can modify the enumeration value by performing a bitwise-OR with the **POOL_RAISE_IF_ALLOCATION_FAILURE** flag defined in `wdm.h`. This flag causes an exception to be raised if the request cannot be satisfied. Use of this flag is not recommended because it is costly.

Similarly, you can modify the *PoolType* value by bitwise-ORing this value with the **POOL_COLD_ALLOCATION** flag (also defined in `wdm.h`) as a hint to the kernel to allocate the memory from pages that are likely to be paged out quickly. To reduce the amount of resident pool memory as much as possible, you should not reference these allocations frequently. The **POOL_COLD_ALLOCATION** flag is only advisory.

### `NumberOfBytes`

The number of bytes to allocate.

### `Tag`

The pool tag to use for the allocated memory. For more information, see the Tag parameter of [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

### `Priority`

An [**EX_POOL_PRIORITY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-ex_pool_priority) enumeration value specifying the priority of this request.

## Return value

**ExAllocatePoolPriorityUninitialized** returns NULL if there is insufficient memory in the free pool to satisfy the request unless POOL_RAISE_IF_ALLOCATION_FAILURE is specified. Otherwise, the routine returns a pointer to the allocated memory.

## Remarks

Memory that **ExAllocatePoolPriorityUninitialized** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents)

See the **Remarks** section of [**ExAllocatePoolWithTagPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority) for additional guidance.

## See also

[**ExAllocatePoolWithTagPriority**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtagpriority)

[**ExAllocatePoolPriorityZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolpriorityzero)