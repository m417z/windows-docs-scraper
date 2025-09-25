# _CM_SERIAL_DEVICE_DATA structure

## Description

The **CM_SERIAL_DEVICE_DATA** structure defines a device-type-specific data record that is stored in the \\Registry\Machine\Hardware\Description tree for a serial controller if the system can collect this information during the boot process.

## Members

### `Version`

The version number of this structure.

### `Revision`

The revision of this structure.

### `BaudClock`

The clock baud rate, in megahertz, at which data is transferred.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)