## Description

**STOR_UC_DEVICE_USAGE** is the structure pointed to by the **Parameters** parameter when a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine is called with a **ControlType** of **ScsiUnitUsage**.

## Members

### `Address`

The device address for the usage notification.

### `UsageType`

A [**SCSI_UC_DEVICE_USAGE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_uc_device_usage_type) value specifying the usage type from a PnP device usage notification.

### `InUse`

**TRUE** if the unit is used for the type in **UsageType**. Otherwise, **FALSE**.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**SCSI_UC_DEVICE_USAGE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_uc_device_usage_type)