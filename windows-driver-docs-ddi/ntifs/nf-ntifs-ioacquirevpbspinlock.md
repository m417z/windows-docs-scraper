# IoAcquireVpbSpinLock function

## Description

The **IoAcquireVpbSpinLock** routine acquires the Volume Parameter Block (VPB) spin lock.

## Parameters

### `Irql` [out]

Pointer to a caller-allocated variable in which to save the current IRQL for a subsequent call to [**IoReleaseVpbSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioreleasevpbspinlock). Usually the **Irql** is saved on the stack as a local variable.

## Remarks

File systems call **IoAcquireVpbSpinLock** to acquire the VPB spin lock. This global spin lock must be acquired before accessing any of the following fields of a VPB:

* Flags (specifically, VPB_MOUNTED)

* DeviceObject

* RealDevice

* ReferenceCount

Every successful call to **IoAcquireVpbSpinLock** must be matched by a subsequent call to [**IoReleaseVpbSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioreleasevpbspinlock). To prevent deadlock, the holder of the VPB spin lock must release it immediately when it is no longer needed.

Before using **IoAcquireVpbSpinLock** and **IoReleaseVpbSpinLock**, driver writers are strongly encouraged to study the way these routines are used in the FASTFAT sample.

After calling **IoAcquireVpbSpinLock**, the caller executes at IRQL DISPATCH_LEVEL. Calling **IoReleaseVpbSpinLock** restores the caller's original IRQL.

## See also

[**IoReleaseVpbSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioreleasevpbspinlock)