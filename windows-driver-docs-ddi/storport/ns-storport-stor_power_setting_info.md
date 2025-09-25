## Description

**STOR_POWER_SETTING_INFO** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine is called with a **ControlType** of **ScsiPowerSettingNotification**.

## Members

### `PowerSettingGuid`

The GUID of the power setting that changed.

### `Value`

Data representing the new value for the power setting.

### `ValueLength`

Length in bytes of the data pointed to by **Value.**

## Remarks

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)