## Description

**STOR_UNIT_CONTROL_POWER** is the structure pointed to by the **Parameters** parameter when Storport calls a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine with a **ControlType** of **ScsiUnitPower**.

## Members

### `Address`

The device address for the power notification.

### `PowerAction`

A [**STOR_POWER_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_power_action) value that indicates the power action. For a runtime power transition, set **PowerAction** to **StorPowerActionNone**.

### `PowerState`

A [**STOR_DEVICE_POWER_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_device_power_state) value that indicates the current power state. This is either **StorPowerDeviceD0** or **StorPowerDeviceD3** for the power on or power off states respectively.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)