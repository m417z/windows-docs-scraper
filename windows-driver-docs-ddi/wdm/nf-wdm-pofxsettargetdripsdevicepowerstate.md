# PoFxSetTargetDripsDevicePowerState function

## Description

 This routine is called to notify the power manager of the device's target
device power state for DRIPS. The driver can override the
DRIPS constraint provided by the PEP.

## Parameters

### `Handle` [in]

A handle that represents the registration of the device with PoFx. The device driver previously received this handle from the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine.

### `TargetState` [in]

Specifies the target DRIPS device power state. Possible values are defined in the [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) enumeration. This value must
be lower than the existing device constraint. A device power state
of **PowerDeviceUnspecified** resets to the PEP provided constraint.

## Return value

Returns STATUS_SUCCESS if the target state was accepted.