# MmIsDriverSuspectForVerifier function

## Description

The **MmIsDriverSuspectForVerifier** routine indicates whether the driver represented by the specified [driver object](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-driver-objects) is in the list of drivers that are selected to be verified by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development).

## Parameters

### `DriverObject` [in]

A pointer to the driver object. This object is a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure that represents a loaded driver image. The driver receives this pointer as an input parameter to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

## Return value

**MmIsDriverSuspectForVerifier** returns **TRUE** if the driver is selected for verification. Otherwise, the routine returns **FALSE**.

## Remarks

A kernel-mode driver can call this routine to determine whether it is being monitored by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development). Driver Verifier monitors kernel-mode drivers to detect illegal function calls or actions that might corrupt the system. To select drivers to be verified, you can use the [Verifier Command Line](https://learn.microsoft.com/windows-hardware/drivers/devtest/verifier-command-line) or [Driver Verifier Manager](https://learn.microsoft.com/windows-hardware/drivers/devtest/driver-verifier-manager--windows-xp-and-later-). For more information about adding drivers to the driver verification list, see [Selecting Drivers to be Verified](https://learn.microsoft.com/windows-hardware/drivers/devtest/selecting-drivers-to-be-verified).

A related routine, [MmIsDriverVerifying](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifying), returns **TRUE** if the specified driver either is in the driver verification list or imports calls to entry points in a driver that is in the driver verification list. Otherwise, **MmIsDriverVerifying** returns **FALSE**.

For example, if driver A has an import table through which it calls one or more entry points in driver B, and driver B is in the driver verification list, then `MmIsDriverVerifying(A)` returns **TRUE** and `MmIsDriverSuspectForVerifier(B)` returns **TRUE**. If driver A is not in the driver verification list, `MmIsDriverSuspectForVerifier(A)` returns **FALSE**. Even if driver B does not call entry points in any drivers that are in the driver verification list, `MmIsDriverVerifying(B)` returns **TRUE** because driver B is in the driver verification list. If a driver C is not in the driver verification list and does not call entry points in any drivers that are in the driver verification list, `MmIsDriverVerifying(C)` and `MmIsDriverSuspectForVerifier(C)` both return **FALSE**.

Another related routine, [MmIsDriverVerifyingByAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifyingbyaddress), indicates whether a driver identified by a driver image address is being verified or calls a driver that is being verified. **MmIsDriverVerifyingByAddress** is available starting with Windows Vista.

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MmIsDriverVerifying](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifying)

[MmIsDriverVerifyingByAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifyingbyaddress)