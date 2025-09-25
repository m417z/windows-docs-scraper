# ExInterlockedAddLargeInteger function

## Description

The **ExInterlockedAddLargeInteger** routine adds a large integer value to the specified variable as an atomic operation.

## Parameters

### `Addend` [in, out]

A pointer to the variable to be adjusted by the *Increment* value.

### `Increment` [in]

Specifies a value to be added to *Addend*.

### `Lock` [in, out]

A pointer to a spin lock to be used to synchronize access to *Addend*.

## Return value

**ExInterlockedAddLargeInteger** returns the initial value of the *Addend* parameter.

## Remarks

Support routines that do interlocked operations are assumed to be incapable of causing a page fault. That is, neither their code nor any of the data they touch can cause a page fault without bringing down the system. They use spin locks to achieve atomicity on symmetric multiprocessor machines. The caller must provide resident storage for the *Lock*, which must be initialized with **KeInitializeSpinLock** before the initial call to an **ExInterlocked*Xxx***.

The *Lock* passed to **ExInterlockedAddLargeInteger** is used to assure that the add operation on *Addend* is atomic with respect to any other operations on the same value which synchronize with this same spin lock.

**ExInterlockedAddLargeInteger** masks interrupts. Consequently, it can be used for synchronization between an ISR and other device driver code, provided that the same *Lock* is never reused in a call to a routine that runs at IRQL = DISPATCH_LEVEL.

Note that calls to **Interlocked*Xxx*** are guaranteed to be atomic with respect to other **Interlocked*Xxx*** calls without caller-supplied spin locks.

Callers of **ExInterlockedAddLargeInteger** run at any IRQL. The storage for the *Addend* parameter must be resident at all IRQLs.

## See also

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)