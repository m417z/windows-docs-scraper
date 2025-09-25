# IoReleaseVpbSpinLock function

## Description

The **IoReleaseVpbSpinLock** routine releases the Volume Parameter Block (VPB) spin lock.

## Parameters

### `Irql` [in]

Saved IRQL value returned by [IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock) when the VPB spin lock was acquired.

## Remarks

This routine is the reciprocal to [IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock). Every successful call to **IoAcquireVpbSpinLock** must be matched by a subsequent call to **IoReleaseVpbSpinLock**.

Before using [IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock) and **IoReleaseVpbSpinLock**, driver writers are strongly encouraged to study the way these routines are used in the FASTFAT sample.

The holder of the VPB spin lock executes at IRQL DISPATCH_LEVEL after calling [IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock). **IoReleaseVpbSpinLock** restores the caller's original IRQL.

## See also

[IoAcquireVpbSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioacquirevpbspinlock)