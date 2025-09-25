## Description

The **KeRcuSynchronize** function waits for a grace period to elapse in the default RCU (Read-Copy-Update) domain, ensuring that all pre-existing RCU read-side critical sections have completed.

## Remarks

**KeRcuSynchronize** is a blocking operation that waits for a grace period using a kernel gate object. It must be called at IRQL < DISPATCH_LEVEL (typically PASSIVE_LEVEL) because it can cause the calling thread to be suspended.

This function blocks the calling thread until all RCU read-side critical sections that were active at the time of the call have exited. It provides a synchronization point for writers to safely reclaim or modify RCU-protected data structures.

**KeRcuSynchronize** guarantees that:

- All RCU read-side critical sections that began before the call to **KeRcuSynchronize** will complete before the function returns.
- It's safe to reclaim memory or data structures protected by RCU after this function returns.
- New readers that begin after **KeRcuSynchronize** starts may or may not be waited for.

This function is typically used in update-side code paths where the caller needs to ensure that all readers have finished accessing data structures before safely reclaiming or modifying them.

The function is non-failing. It will always complete successfully and cannot return an error.

For more complex scenarios requiring custom synchronization domains, use [**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize) with an explicit SRCU partition.

## See also

[**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock)

[**KeRcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadunlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree)