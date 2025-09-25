## Description

The PO_FX_DIRECTED_POWER_UP_CALLBACK callback function is implemented by the client driver to handle driver-specific power up activities on behalf of DFx (Directed [PoFx](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework)).

## Parameters

### `Context`

Supplies a pointer to the context passed in to [**PoFxRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice).

### `Flags`

Reserved for future use.

## Remarks

WDM drivers that register with PoFx for runtime idle power management support need to implement this callback to add DFx support.

Register your implementation of this callback function by setting the appropriate member of the [**PO_FX_DEVICE_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-po_fx_device_v3) structure and then calling [**PoFxRegisterDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice).

This callback is invoked when the system determines the device needs to power up after having previously being powered down in the [*PO_FX_DIRECTED_POWER_DOWN_CALLBACK*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_down_callback) callback function. The device may need to be powered up when the system exits Modern Standby, [activators](https://learn.microsoft.com/windows-hardware/design/device-experiences/activators) start to run, or a hardware-initiated wake occurs.

When this callback is invoked, the driver typically performs the following high-level tasks:

- Request a D0 IRP to power up the device.

- After the D0 IRP completes, call [**PoFxReportDevicePoweredOn**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxreportdevicepoweredon).

- Unblock I/O queues and start processing requests normally.

Once the driver completes the Directed power up call, it can resume runtime-idle (RTD3) behavior.

The contract is very similar to S0, although no S-IRPs are involved.

Note that if a device hierarchy is involved, the directed power framework asks the child devices to power down before the parent device. For a given parent device, direct children (ones enumerated by the parent) and indirect children due to [power relations](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) are considered.

## See also

[Introduction to the Directed Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-the-directed-power-management-framework)

[PO_FX_DIRECTED_POWER_DOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_directed_power_down_callback)