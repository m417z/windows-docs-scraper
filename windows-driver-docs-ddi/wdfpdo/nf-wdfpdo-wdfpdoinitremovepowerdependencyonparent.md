## Description

The **WdfPdoInitRemovePowerDependencyOnParent** method removes the power dependency described in the **Remarks** section.

## Parameters

### `DeviceInit`

A pointer to a [WDFDEVICE_INIT](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfdevice_init) structure.

## Remarks

In general, the framework requires that a parent bus driver enter the D0 device power state before a child device enters D0, and similarly that a child device exit D0 before the parent leaves D0.

However, this behavior may not be desired, in particular if the child device is a virtual device that doesn't represent any real hardware. At S0 idle power-down, the power state of the child device may not be relevant to the parent. In fact, the child device may have no reason to perform S0 idle detection. In this case, it would be better for the parent device to transition between D0 and Dx based on I/O activity, rather than being dependent on the power state of the child device.

Removing the power dependency has the following effects on the bus driver:

* The PDO PnP/Power callbacks might execute while the parent device is in Dx.
* The PDO enable/disable-wake-at-bus callbacks might execute while the parent device is in Dx.
* A request forwarded from a power-managed queue on the PDO (assuming the PDO is the power policy owner) to a non power-managed queue on the FDO might be dispatched while the bus driver is in Dx.
* The child stack performs power state transitions independently of the parent stack. This includes scenarios such as fast-resume in which the child stack might receive its S-IRP and even finish processing its D-IRP before the parent stack finishes processing its own D-IRP.

To remove the power dependency, the bus driver can call **WdfPdoInitRemovePowerDependencyOnParent** when it creates the PDO for the child device.

This function takes no action if the parent bus driver is not the power policy owner of the parent device stack.

## See also