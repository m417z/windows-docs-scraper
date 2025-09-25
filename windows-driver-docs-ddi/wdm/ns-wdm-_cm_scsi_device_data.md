# _CM_SCSI_DEVICE_DATA structure

## Description

The **CM_SCSI_DEVICE_DATA** structure defines a device-type-specific data record that is stored in the \\Registry\Machine\Hardware\Description tree for a SCSI HBA if the system can collect this information during the boot process.

## Members

### `Version`

The version number of this structure.

### `Revision`

The revision for this structure.

### `HostIdentifier`

The SCSI bus identifier used by the ARC firmware.

## See also

[CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor)

[IoQueryDeviceDescription](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[IoReportResourceUsage](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)