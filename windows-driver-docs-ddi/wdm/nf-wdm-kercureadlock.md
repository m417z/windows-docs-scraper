## Description

The **KeRcuReadLock** function enters a RCU (Read-Copy-Update) read-side critical section in the default RCU domain. This function pins the calling thread to its current processor and prevents it from being preempted by the scheduler.

## Remarks

**KeRcuReadLock** provides low-cost synchronization for reading shared data structures without traditional locking overhead. It only accesses data local to the current CPU, making it extremely efficient.

RCU read-side critical sections allow multiple threads to concurrently access shared data structures while ensuring that writers can safely update the data using RCU protocols. RCU read-side critical sections can be nested.

**KeRcuReadLock** must always be paired with a corresponding call to [**KeRcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadunlock).

This function cannot fail and always succeeds.

Within a RCU read-side critical section:

- The calling thread is guaranteed that RCU-protected data structures won't be reclaimed.
- Multiple readers can access the same data concurrently without blocking each other.
- The thread should access only RCU-protected data structures using appropriate RCU dereference primitives.
- The thread must not perform operations that could cause extended delays.

This function can be called from any IRQL. If it's called below DISPATCH_LEVEL, the function automatically raises IRQL to DISPATCH_LEVEL. The original IRQL is restored when the corresponding [**KeRcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadunlock) is called

The calling thread is pinned to its current processor to maintain RCU semantics. If the processor is marked as idle, the function adjusts the idle state counters appropriately. The scheduler is prevented from preempting the thread while in the critical section.

The function uses the default RCU domain, making it suitable for simple RCU use cases. For more complex scenarios requiring custom synchronization domains, use [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock) with an explicit SRCU partition.

## See also

[**KeRcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadunlock)

[**KeRcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercusynchronize)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)