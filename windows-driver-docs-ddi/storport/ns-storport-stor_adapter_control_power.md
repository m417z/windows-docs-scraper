## Description

**STOR_ADAPTER_CONTROL_POWER** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiAdapterPower**.

## Members

### `Header`

The [**STOR_POWER_CONTROL_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_control_header) structure.

### `PowerAction`

A [**STOR_POWER_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-stor_power_action) value that indicates the power action. For a runtime power transition, set **PowerAction** to **StorPowerActionNone**.

### `PowerState`

A [**STOR_DEVICE_POWER_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-_stor_device_power_state) value that indicates the current power state. This is either **StorPowerDeviceD0** or **StorPowerDeviceD3** for the power on or power off states respectively.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)