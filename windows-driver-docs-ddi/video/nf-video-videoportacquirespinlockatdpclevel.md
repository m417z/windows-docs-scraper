# VideoPortAcquireSpinLockAtDpcLevel function

## Description

The **VideoPortAcquireSpinLockAtDpcLevel** function acquires a spin lock when the caller is already running at IRQL = DISPATCH_LEVEL.

## Parameters

### `HwDeviceExtension` [in, out]

Pointer to the miniport driver's device extension.

### `SpinLock` [in]

Pointer to a memory location that contains the spin lock.

## Return value

None

## Remarks

Miniport drivers call **VideoPortAcquireSpinLockAtDpcLevel** instead of [VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85)) for better driver performance if and only if they are already running at IRQL = DISPATCH_LEVEL.

If a miniport driver is running at IRQL < DISPATCH_LEVEL, it should call **VideoPortAcquireSpinLock** to have IRQL raised by that routine. **VideoPortAcquireSpinLockAtDpcLevel** requires the caller to be running already at IRQL = DISPATCH_LEVEL, so no raise is necessary.

The caller should release the spin lock with [VideoPortReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/previous-versions/ff570358(v=vs.85)) as quickly as possible.

## See also

[VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85))

[VideoPortReleaseSpinLockFromDpcLevel](https://learn.microsoft.com/previous-versions/ff570358(v=vs.85))