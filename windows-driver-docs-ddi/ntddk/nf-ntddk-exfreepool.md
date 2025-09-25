# ExFreePool macro

## Description

The **ExFreePool** routine deallocates a block of pool memory.

## Parameters

### `a`

Specifies the address of the block of pool memory being deallocated.

## Remarks

This routine releases memory allocated by [ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool), [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag), [ExAllocatePoolWithQuota](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquota), or [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag). The memory block must not be accessed after it is freed.

Drivers can also use the **ExFreePoolWithTag** routine to free buffers allocated by [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) and [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag).

Callers of **ExFreePool** must be running at IRQL <= DISPATCH_LEVEL. A caller at DISPATCH_LEVEL must have specified a **NonPaged***Xxx**PoolType* when the memory was allocated. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[ExAllocatePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool)

[ExAllocatePoolWithQuota](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquota)

[ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag)