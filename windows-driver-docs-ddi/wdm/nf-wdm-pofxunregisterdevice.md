# PoFxUnregisterDevice function

## Description

The **PoFxUnregisterDevice** routine removes the registration of a device from the power management framework (PoFx).

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

## Remarks

The driver that owns the power policy for a device must unregister the device from PoFx when the device is removed. The Plug and Play (PnP) manager can remove the device stack from the PnP tree only after the device is unregistered.

To unregister the device, the driver calls **PoFxUnregisterDevice** during the handling of an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) or [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) request, whichever is received first. This call should occur after the driver no longer requires access to the device's hardware.

A device driver that calls this routine must previously have called the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine to register the device with PoFx.

## See also

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)