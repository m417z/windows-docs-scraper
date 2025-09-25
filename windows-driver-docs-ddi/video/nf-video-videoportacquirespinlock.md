# VideoPortAcquireSpinLock function

## Description

The **VideoPortAcquireSpinLock** function obtains the specified spin lock.

## Parameters

### `HwDeviceExtension` [in, out]

Pointer to the miniport driver's device extension.

### `SpinLock` [in]

Pointer to a memory location that contains the spin lock.

### `OldIrql` [out]

Pointer to a memory location that will receive the current IRQL.

## Return value

None

## Remarks

The current IRQL is saved in *OldIrql*. Then, the current IRQL is reset to DISPATCH_LEVEL, and the specified spin lock is acquired.

The *OldIrql* value must be specified when the spin lock is released with [VideoPortReleaseSpinLock](https://learn.microsoft.com/previous-versions/ff570357(v=vs.85)).

Spin locks can cause serious problems if not used judiciously. In particular, no deadlock protection is performed and dispatching is disabled while the spin lock is held. Therefore:

* The code within a critical region guarded by a spin lock must neither be pageable nor make any references to pageable data.
* The code within a critical region guarded by a spin lock can neither call any external function that might access pageable data or raise an exception, nor can it generate any exceptions.
* The caller should release the spin lock with **VideoPortReleaseSpinLock** as quickly as possible.

## See also

[VideoPortAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/previous-versions/ff570176(v=vs.85))

[VideoPortReleaseSpinLock](https://learn.microsoft.com/previous-versions/ff570357(v=vs.85))