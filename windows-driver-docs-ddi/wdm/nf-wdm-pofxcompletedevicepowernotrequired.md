# PoFxCompleteDevicePowerNotRequired function

## Description

The **PoFxCompleteDevicePowerNotRequired** routine notifies the power management framework (PoFx) that the calling driver has completed its response to a call to the driver's [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) callback routine.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

## Remarks

After PoFx calls the driver's [DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback) callback routine, the driver must respond by calling **PoFxCompleteDevicePowerNotRequired**.

PoFx calls the driver's *DevicePowerNotRequiredCallback* routine to inform the driver that the device is no longer required to remain in the D0 state. In response to this call, the driver can choose to enter a low-power Dx state or to remain in the D0 state. After the driver has completed its response to the *DevicePowerNotRequiredCallback* call, the driver calls **PoFxCompleteDevicePowerNotRequired** to inform PoFx. The **PoFxCompleteDevicePowerNotRequired** call can occur either during or after the *DevicePowerNotRequiredCallback* call.

## See also

[DevicePowerNotRequiredCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_device_power_not_required_callback)

[PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice)