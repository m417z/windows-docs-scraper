# ExInterlockedAddUlong function

## Description

The **ExInterlockedAddUlong** routine adds an unsigned long value to a given unsigned integer as an atomic operation.

## Parameters

### `Addend` [in, out]

A pointer to an unsigned long integer whose value is to be adjusted by the *Increment* value.

### `Increment` [in]

Specifies an unsigned long integer to be added.

### `Lock` [in, out]

A pointer to a spin lock to be used to synchronize access to the *Addend*.

## Return value

**ExInterlockedAddUlong** returns the original (unsummed) value of the *Addend*.

## Remarks

Consider using **InterlockedExchangeAdd** instead of this routine. **InterlockedExchangeAdd** can be more efficient because it does not use a spin lock and it is inlined by the compiler.

Support routines that do interlocked operations are assumed to be incapable of causing a page fault. That is, neither their code nor any of the data they touch can cause a page fault without bringing down the system. They use spin locks to achieve atomicity on symmetric multiprocessor machines. The caller must provide resident storage for the *Lock*, which must be initialized with **KeInitializeSpinLock** before the initial call to an **ExInterlocked*Xxx***.

The *Lock* passed to **ExInterlockedAddULong** is used to assure that the add operation on *Addend* is atomic with respect to any other operations on the same value which synchronize with this same spin lock.

**ExInterlockedAddUlong** masks interrupts. Consequently, it can be used for synchronization between an ISR and other driver code, provided that the same *Lock* is never reused in a call to a routine that runs at IRQL = DISPATCH_LEVEL.

Note that calls to **Interlocked*Xxx*** are guaranteed to be atomic with respect to other **Interlocked*Xxx*** calls without caller-supplied spin locks.

Callers of **ExInterlockedAddUlong** run at any IRQL. The storage for the *Addend* parameter must be resident at all IRQLs.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)

[KeInitializeSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializespinlock)