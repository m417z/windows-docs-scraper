## Description

The **KeSrcuReadUnlock** routine exits a read-side RCU critical section of a specified Sleepable Read-Copy-Update (SRCU) partition.

## Parameters

### `Rcu` [in]

A pointer to the SRCU instance that was used in the corresponding [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock) call.

### `Lock` [in]

A pointer to the [**KE_SRCU_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-ke_srcu_lock) structure that was filled by the corresponding [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock) call.

## Remarks

**KeSrcuReadUnlock** exits a read-side critical section that was entered with [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock). This function must be called in the same thread that called the corresponding [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock).

This function can be called at any IRQL when the thread is still on the same processor. If the thread migrated to a different processor, the maximum effective IRQL is DISPATCH_LEVEL due to inter-processor interrupt (IPI) requirements.

This function can be called with interrupts disabled.

If the calling thread migrated to a different processor since calling [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock), this function will:

1. Detect the processor change.
2. Send an inter-processor interrupt (IPI) to the original processor.
3. Complete the unlock operation remotely on the original processor.

After this call, the protected data should no longer be accessed.

## See also

[**KE_SRCU_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-ke_srcu_lock)

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)