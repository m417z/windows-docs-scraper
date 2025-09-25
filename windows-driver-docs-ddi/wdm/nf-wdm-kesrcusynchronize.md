## Description

The **KeSrcuSynchronize** routine waits until all currently active read-side critical sections for a Sleepable Read-Copy-Update (SRCU) partition have exited.

## Parameters

### `Rcu` [in]

A pointer to the SRCU instance that was previously allocated by [**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate).

## Remarks

**KeSrcuSynchronize** implements the "synchronize" operation for SRCU, which starts a grace period and waits for all currently active readers to exit their critical sections. This function is essential for safe memory reclamation and data structure updates.

The grace period semantics are as follows:

- The function waits only for readers that were active when the call was made.
- New readers that enter after the call begins are not included in the wait.
- The function might block until all target readers call [**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock).
- Multiple synchronize operations can be in progress simultaneously.

Call this function only at IRQL < DISPATCH_LEVEL since it may block. This function can sleep, making it suitable for pageable code. Don't call this function from within an SRCU read-side critical section.

The typical writer pattern is as follows:

1. Remove data structure from global visibility.
2. Call **KeSrcuSynchronize** to wait for existing readers.
3. Safely deallocate or modify the data structure.

The function ensures that no readers are accessing the data when it returns, making it safe to perform updates or memory reclamation.

## See also

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)