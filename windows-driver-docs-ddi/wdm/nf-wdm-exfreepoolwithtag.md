# ExFreePoolWithTag function

## Description

The **ExFreePoolWithTag** routine deallocates a block of pool memory allocated with the specified tag.

## Parameters

### `P` [in]

Specifies the beginning address of a block of pool memory allocated by either [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) or [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag).

### `Tag` [in]

Specifies the tag value passed to [ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag) or [ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag) when the block of memory was originally allocated.

The tag is a non-zero character literal of one to four characters delimited by single quotation marks (for example, 'Tag1'). The string is usually specified in reverse order (for example, '1gaT'). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

## Remarks

Callers of **ExFreePoolWithTag** must be running at IRQL <= DISPATCH_LEVEL. A caller at DISPATCH_LEVEL must have specified a **NonPaged***Xxx**PoolType* when the memory was allocated. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[ExAllocatePoolWithQuotaTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithquotatag)

[ExAllocatePoolWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[ExFreePool](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)