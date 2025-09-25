# StorPortReleaseSpinLock function

## Description

The **StorPortReleaseSpinLock** routine releases a spinlock acquired by [StorPortAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock).

## Parameters

### `DeviceExtension`

Pointer to a per-adapter device extension.

### `LockHandle` [in, out]

Pointer to a lock handle returned by [StorPortAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock).

## See also

[StorPortAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)