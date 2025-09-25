## Description

The **ExTryConvertSharedSpinLockExclusive** routine attempts to convert the access state of a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-spin-locks) from *acquired for shared access* to *exclusive access*.

## Parameters

### `SpinLock` [in, out]

A pointer to the spin lock whose access state is to be converted to exclusive access. The caller must already own this spin lock for shared access.

## Return value

**ExTryConvertSharedSpinLockExclusive** returns TRUE if the conversion succeeds; otherwise, it returns FALSE.

## Remarks

If the caller acquired the shared spin lock by calling the [ExAcquireSpinLockSharedAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlocksharedatdpclevel) routine, the caller should release the converted spin lock by calling the [ExReleaseSpinLockExclusiveFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusivefromdpclevel) routine. If the caller acquired the shared spin lock by calling the [ExAcquireSpinLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockshared) routine, the caller should release the converted spin lock by calling the [ExReleaseSpinLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusive) routine, and the *OldIrql* value supplied as an input parameter to this routine should be the KIRQL value returned by **ExAcquireSpinLockShared**.

## See also

[ExAcquireSpinLockShared](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlockshared)

[ExAcquireSpinLockSharedAtDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirespinlocksharedatdpclevel)

[ExReleaseSpinLockExclusive](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusive)

[ExReleaseSpinLockExclusiveFromDpcLevel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleasespinlockexclusivefromdpclevel)