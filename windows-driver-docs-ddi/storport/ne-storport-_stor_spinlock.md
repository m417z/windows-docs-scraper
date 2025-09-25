# STOR_SPINLOCK enumeration

## Description

The **STOR_SPINLOCK** enumeration is used to specify the type of a spinlock.

## Constants

### `InvalidLock`

Indicates an invalid spinlock. This value should never be used.

### `DpcLock`

Indicates a DPC spinlock.

### `StartIoLock`

Indicates a StartIo spinlock.

### `InterruptLock`

Indicates an Interrupt spinlock.

### `ThreadedDpcLock`

Indicates a threaded DPC spinlock.

### `DpcLevelLock`

Indicates a spinlock that is to be used when the IRQL level is already at DPC level.

## Remarks

[**StorPortAcquireSpinLockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlockex)
supports all of the spinlock types. [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock) only supports: **DpcLock**, **StartIoLock**, and **InterruptLock**.

## See also

[**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)

[**StorPortAcquireSpinLockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlockex)