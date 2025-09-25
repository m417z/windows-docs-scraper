# VideoPortReleaseSpinLockFromDpcLevel function

## Description

The **VideoPortReleaseSpinLockFromDpcLevel** function releases the spin lock obtained by a previous call to [VideoPortAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/previous-versions/ff570176(v=vs.85)).

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `SpinLock` [in, out]

Pointer to a memory location that contains the spin lock to be released.

## Return value

None

## Remarks

Miniport drivers call **VideoPortReleaseSpinLockFromDpcLevel** to release a spin lock acquired by calling [VideoPortAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/previous-versions/ff570176(v=vs.85)).

It is an error to call **VideoPortReleaseSpinLockFromDpcLevel** if the given spin lock was acquired by calling [VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85)) because the caller's original IRQL is not restored, which can cause deadlocks or fatal page faults.

## See also

[VideoPortAcquireSpinLock](https://learn.microsoft.com/previous-versions/ff570175(v=vs.85))

[VideoPortAcquireSpinLockAtDpcLevel](https://learn.microsoft.com/previous-versions/ff570176(v=vs.85))