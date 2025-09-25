## Description

The **KeSrcuFree** routine performs cleanup of a Sleepable Read-Copy-Update (SRCU) partition and deallocates its storage.

## Parameters

### `Rcu` [in]

A pointer to the SRCU instance that was previously allocated by [**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate).

## Remarks

**KeSrcuFree** performs cleanup and deallocates an SRCU partition that was previously created with [**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate). This function ensures that all pending operations are completed before freeing the resources.

Don't access the SRCU instance after calling this function.

## See also

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)