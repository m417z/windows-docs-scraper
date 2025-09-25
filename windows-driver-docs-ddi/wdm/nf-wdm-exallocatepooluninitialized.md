## Description

This routine is a wrapper and replacement option for [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag).

- To support Windows versions earlier than Windows 10, version 2004, use **ExAllocatePoolUninitialized** or [**ExAllocatePoolZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero).

- To support Windows 10, version 2004 and later, use [**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2).

## Parameters

### `PoolType`

Defines the **POOL_TYPE** parameter *PoolType*.

### `NumberOfBytes`

Defines the **SIZE_T** parameter *NumberOfBytes*.

### `Tag`

Defines the **ULONG** parameter *Tag*.

## Return value

## Remarks

Use this wrapper if you want to explicitly not zero the allocated memory range.

A driver should only access memory within the byte range that it allocates. Accessing memory outside this range may corrupt the pool and cause the system to crash.

Memory that **ExAllocatePoolUninitialized** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

See the Remarks section of [**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) for additional guidance.

## See also

[**ExAllocatePoolZero**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolzero)