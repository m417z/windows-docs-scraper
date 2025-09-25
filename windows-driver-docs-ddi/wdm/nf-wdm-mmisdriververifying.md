# MmIsDriverVerifying function

## Description

The **MmIsDriverVerifying** routine indicates whether the kernel-mode driver that is identified by the specified [driver object](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-driver-objects) is being verified or calls a driver that is being verified by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development).

## Parameters

### `DriverObject` [in]

A pointer to a [DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure that represents a driver object. The driver receives this pointer as an input parameter to its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine.

## Return value

**MmIsDriverVerifying** returns **TRUE** if the specified driver either is in the driver verification list or imports calls to entry points in a driver that is in the driver verification list. Otherwise, this routine returns **FALSE**.

## Remarks

A kernel-mode driver can call this routine to determine whether it is being monitored by [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development). Driver Verifier monitors kernel-mode drivers to detect illegal function calls or actions that might corrupt the system. To select drivers to be verified, you can use the [Verifier Command Line](https://learn.microsoft.com/windows-hardware/drivers/devtest/verifier-command-line) or [Driver Verifier Manager](https://learn.microsoft.com/windows-hardware/drivers/devtest/driver-verifier-manager--windows-xp-and-later-). For more information about adding drivers to the driver verification list, see [Selecting Drivers to be Verified](https://learn.microsoft.com/windows-hardware/drivers/devtest/selecting-drivers-to-be-verified).

A similar routine, [MmIsDriverVerifyingByAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifyingbyaddress), indicates whether a driver identified by a driver image address is being verified or calls a driver that is being verified. **MmIsDriverVerifyingByAddress** is available starting with Windows Vista.

Another related routine, [MmIsDriverSuspectForVerifier](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriversuspectforverifier), indicates whether a driver represented by a [driver object](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-driver-objects) is in the list of drivers that are selected to be verified. **MmIsDriverSuspectForVerifier** is available starting with Windows 8.

For example, if driver A has an import table through which it calls one or more entry points in driver B, and driver B is in the driver verification list, then `MmIsDriverVerifying(A)` returns **TRUE** and `MmIsDriverSuspectForVerifier(B)` returns **TRUE**. If driver A is not in the driver verification list, `MmIsDriverSuspectForVerifier(A)` returns **FALSE**. Even if driver B does not call entry points in any drivers that are in the driver verification list, `MmIsDriverVerifying(B)` returns **TRUE** because driver B is in the driver verification list. If a driver C is not in the driver verification list and does not call entry points in any drivers that are in the driver verification list, `MmIsDriverVerifying(C)` and `MmIsDriverSuspectForVerifier(C)` both return **FALSE**.

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[MmIsDriverVerifyingByAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmisdriververifyingbyaddress)