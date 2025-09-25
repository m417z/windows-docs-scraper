## Description

**SCSI_UC_DEVICE_USAGE_TYPE** specifies the device usage type from a PnP device usage notification.

## Constants

### `ScsiDeviceUsageTypeUndefined`

The device usage type is undefined.

### `ScsiDeviceUsageTypePaging`

The page file will be used on the device.

### `ScsiDeviceUsageTypeHibernation`

The hibernation file will be used on the device.

### `ScsiDeviceUsageTypeDumpFile`

The dump file will be used on the device.

### `ScsiDeviceUsageTypeBoot`

The device is used to boot the operating system.

## Remarks

**SCSI_UC_DEVICE_USAGE_TYPE** is a member of the [**STOR_UC_DEVICE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_uc_device_usage) structure, which Storport uses when it calls a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine with a **ControlType** of **ScsiUnitUsage**.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_UC_DEVICE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_uc_device_usage)