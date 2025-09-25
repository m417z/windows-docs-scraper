# ExAcquireRundownProtection function

## Description

The **ExAcquireRundownProtection** routine tries to acquire run-down protection on a shared object so the caller can safely access the object.

## Parameters

### `RunRef` [in, out]

A pointer to an [EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that was initialized by a previous call to the [ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection) routine. The run-down protection routines use this structure to track the run-down status of the associated shared object. This structure is opaque to drivers.

## Return value

**ExAcquireRundownProtection** returns **TRUE** if the routine successfully acquires run-down protection for the caller. Otherwise, it returns **FALSE**. A return value of **FALSE** indicates that the run down of the object has started and that the object must be treated as invalid.

## Remarks

To safely access a shared object, a driver calls **ExAcquireRundownProtection** to acquire run-down protection on the object. The routine returns **TRUE** to indicate that run-down protection is in effect. When run-down protection is in effect, the driver can safely access the object without risk that the object will be deleted before the access completes.

As long as the run-down block itself is nonpaged, this function can be called at DISPATCH_LEVEL.

After completing the access, the driver calls [ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection) to release the previously acquired run-down protection.

If **ExAcquireRundownProtection** returns **FALSE**, the object is no longer accessible. For example, if the object is to be replaced with a new one, the caller must wait for the object owner to create the new object, and then negotiate access to the new object.

For more information, see [Run-Down Protection](https://learn.microsoft.com/windows-hardware/drivers/kernel/run-down-protection).

## See also

[EX_RUNDOWN_REF](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ExInitializeRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializerundownprotection)

[ExReleaseRundownProtection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaserundownprotection)