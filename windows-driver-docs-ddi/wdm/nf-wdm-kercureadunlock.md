## Description

The **KeRcuReadUnlock** function exits a RCU (Read-Copy-Update) read-side critical section in the default RCU domain that was previously entered with [**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock).

## Remarks

This function unpins the calling thread from its processor, restores the original IRQL if needed, and performs any necessary grace period reporting to advance RCU synchronization.

**KeRcuReadUnlock** must be called to exit every RCU read-side critical section that was entered with [**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock). Calls must be properly nested (LIFO order) when using nested RCU read-side critical sections.

After calling **KeRcuReadUnlock**:

- The calling thread is no longer protected from RCU grace periods.
- RCU-protected data structures accessed during the critical section may become eligible for reclamation.
- The thread should not continue to access RCU-protected data using pointers obtained during the critical section.
- The thread is no longer pinned to its processor and may be scheduled on different processors.

This function can be called from any IRQL. The function automatically handles IRQL restoration; that is, if the original IRQL before the corresponding **KeRcuReadLock** was below DISPATCH_LEVEL, it will be restored to that level.

This function uses the default RCU domain, making it suitable for simple RCU use cases. For more complex scenarios requiring custom synchronization domains, use [**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock) with an explicit SRCU partition.

## See also

[**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock)

[**KeRcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercusynchronize)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)