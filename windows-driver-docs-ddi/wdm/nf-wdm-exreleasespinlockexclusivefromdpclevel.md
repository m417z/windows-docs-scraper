## Description

The **ExReleaseSpinLockExclusiveFromDpcLevel** routine releases a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks) that the caller acquired for exclusive access, and leaves the IRQL unchanged.

## Parameters

### `SpinLock`

[in, out] A pointer to the spin lock to release. The caller must own this spin lock for exclusive access.

## Remarks

On entry to this routine, the caller must be running at IRQL \>= DISPATCH\_LEVEL. This routine does not change the IRQL.

**ExReleaseSpinLockExclusiveFromDpcLevel** releases a spin lock that the caller acquired in a previous call to the [**ExAcquireSpinLockExclusiveAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockexclusiveatdpclevel) routine.

The caller should hold the spin lock only briefly before releasing it. For more information, see [Introduction to Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks).

## See also

[**ExAcquireSpinLockExclusiveAtDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockexclusiveatdpclevel)