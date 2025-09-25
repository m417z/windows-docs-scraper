## Description

The **KeSrcuReadLock** routine enters the read-side RCU critical section of a specified Sleepable Read-Copy-Update (SRCU) partition.

## Parameters

### `Rcu` [in]

A pointer to the SRCU instance that was previously allocated by [**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate).

### `Lock` [out]

A pointer to a [**KE_SRCU_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-ke_srcu_lock) structure that receives the lock context. This context must be passed to [**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock) when exiting the critical section.

## Remarks

**KeSrcuReadLock** enters a read-side critical section, allowing the caller to safely access data protected by the SRCU partition. Multiple readers can hold read locks simultaneously, but updates must wait for all readers to exit.

Unlike regular RCU, readers can sleep while holding the read lock. Read locks can be nested within the same thread. The thread can migrate to different processors while holding the lock.

Always pair with [**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock) in the same thread. The **Lock** parameter receives context needed for unlocking. Multiple readers can access the protected data concurrently. Writers must use [**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize) to wait for reader completion.

If the thread migrates to a different processor between lock and unlock, the unlock operation will use an inter-processor interrupt (IPI) to complete the unlock on the original processor.

## See also

[**KE_SRCU_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-ke_srcu_lock)

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)