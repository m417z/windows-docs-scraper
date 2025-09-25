# VideoPortReleaseSpinLock function

## Description

The **VideoPortReleaseSpinLock** function releases ownership of a given spin lock and restores the original IRQL at which the caller was running.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `SpinLock` [in, out]

Pointer to a memory location that contains the spin lock to be released.

### `NewIrql` [in]

Specifies the IRQL to be restored.

## Return value

None

## Remarks

This call is the inverse of [VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85)). The *NewIrql* value must be the same as the value pointed to by *OldIrql* when **VideoPortAcquireSpinLock** returned.

Callers of **VideoPortReleaseSpinLock** must be running at IRQL = DISPATCH_LEVEL. On return from this routine, IRQL is restored to the *NewIrql* value.

## See also

[VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85))