## Description

The **KE_SRCU_LOCK** structure represents the lock context used in SRCU (Sleepable Read-Copy-Update) read-side critical sections.

## Members

### `Placeholder[2]`

An array of two `ULONG_PTR` values that serve as opaque storage for the SRCU lock context. The contents of this field are implementation-specific and should not be accessed or modified by drivers.

## Remarks

This structure is returned by [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock) and [**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock) functions and must be passed to the corresponding unlock functions.

This structure is opaque to drivers. Drivers should never:

- Access or modify the `Placeholder` field directly.
- Make assumptions about the structure's internal layout.
- Copy or serialize the structure contents.
- Use the structure across different SRCU partitions.

The structure is typically used in the following pattern:

```c
PSRCU_PARTITION SrcuPartition = KeSrcuAllocate();
KE_SRCU_LOCK LockContext;

// Enter read-side critical section
LockContext = KeSrcuReadLock(SrcuPartition);

// Access RCU-protected data safely
// ...

// Exit read-side critical section
KeSrcuReadUnlock(SrcuPartition, LockContext);
```

The lock context returned by the read lock function must be passed to the corresponding unlock function to properly exit the critical section. Using an incorrect or uninitialized lock context may result in system instability.

## See also

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeRcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadlock)

[**KeRcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kercureadunlock)

[**KeSrcuAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcuallocate)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)