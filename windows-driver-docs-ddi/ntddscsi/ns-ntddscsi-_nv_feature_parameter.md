# NV_FEATURE_PARAMETER structure

## Description

The NV_FEATURE_PARAMETER structure is used in conjunction with the [**IOCTL_SCSI_MINIPORT_NVCACHE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_nvcache) request to get NV Cache Manager feature support information from the device. The NV Cache Manager feature parameters structure is returned by the miniport driver upon the successful return from the NRB_NVCACHE_INFO function, as requested in the Function field of the [**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block) structure.

The values in these fields come from the IDENTIFY DEVICE command in section 7.16 of the ATA8-ACS specification.

## Members

### `NVPowerModeEnabled`

Taken from word 214, bit 0 of the IDENTIFY DEVICE data, a value of one means the NV Cache Power Mode feature set is enabled.

### `NVParameterReserv1`

Reserved for future use.

### `NVCmdEnabled`

Taken from word 214, bit 4 of the IDENTIFY DEVICE data, a value of one means the NV Cache feature set is enabled.

### `NVParameterReserv2`

Reserved for future use.

### `NVPowerModeVer`

Taken from word 214, bits 8 through 11 of the IDENTIFY DEVICE data, this field contains the NV Cache Power Mode feature set version.

### `NVCmdVer`

Taken from word 214, bits 12 through 15 of the IDENTIFY DEVICE data, this field contains the NV Cache feature set version.

### `NVSize`

Taken from words 215 and 216 of the IDENTIFY DEVICE data, this field contains the NV Cache Size, in logical blocks.

### `NVReadSpeed`

Taken from word 217 of the IDENTIFY DEVICE data, this field contains the NV Cache Read Transfer Speed, in megabytes per second (MB/s).

### `NVWrtSpeed`

Taken from word 218 of the IDENTIFY DEVICE data, this field contains the NV Cache Write Transfer Speed, in megabytes per second (MB/s).

### `DeviceSpinUpTime`

Taken from word 219, bits 0 through 7 of the IDENTIFY DEVICE data, this field contains the device's estimated time to spin up, in seconds.

## See also

[**IOCTL_SCSI_MINIPORT_NVCACHE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_nvcache)

[**NVCACHE_REQUEST_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nvcache_request_block)