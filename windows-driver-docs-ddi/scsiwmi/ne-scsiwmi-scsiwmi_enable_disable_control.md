# SCSIWMI_ENABLE_DISABLE_CONTROL enumeration

## Description

The SCSIWMI_ENABLE_DISABLE_CONTROL enumerator is used to specify what to enable or disable.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Constants

### `ScsiWmiEventControl`

Indicates that a WMI event is to be enabled or disabled.

### `ScsiWmiDataBlockControl`

Indicates that a data collection for a block is to be enabled or disabled.

## See also

[DpWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nc-wmilib-wmi_function_control_callback)

[HwScsiWmiFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsiwmi/nc-scsiwmi-pscsiwmi_function_control)