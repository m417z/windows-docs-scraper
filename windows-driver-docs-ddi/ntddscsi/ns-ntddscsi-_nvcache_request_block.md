# _NVCACHE_REQUEST_BLOCK structure

## Description

The **NVCACHE_REQUEST_BLOCK** structure is used in conjunction with the [**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport) request to manage hybrid-hard disk drive (H-HDD) devices (for example, Microsoft ReadyDrive technology). This topic defines the general structure for both input data and output data for a call made to the NV Cache Manager. A caller should fill all required fields before calling [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) or [**IoBuildDeviceIoControlRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuilddeviceiocontrolrequest). The miniport driver must do the same after the requested function is completed, and before it returns.

## Members

### `NRBSize`

The **sizeof**(NVCACHE_REQUEST_BLOCK).

### `Function`

Specifies the operation to be performed, which can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| NRB_FUNCTION_NVCACHE_INFO | Get NV Cache Manager feature support information from the device. Upon the successful completion of this function, the required data fields are returned to the caller. The return data structure is [**NV_FEATURE_PARAMETER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ns-ntddscsi-_nv_feature_parameter). |
| NRB_FUNCTION_SPINDLE_STATUS | Determine if the device is currently spinning up or spinning down. For an ATA device, a Check Power Mode command is required to obtain the device's spindle status. For a SCSI device, a Mode Sense command can be used to query the device's current power mode. |
| NRB_FUNCTION_NVCACHE_POWER_MODE_SET | Turn on the NV Cache Manager power mode. |
| NRB_FUNCTION_NVCACHE_POWER_MODE_RESET | Turn off the NV Cache Manager power mode. |
| NRB_FUNCTION_FLUSH_NVCACHE | Flush the data that is currently pinned in NV cache memory to make the required NV cache memory space available. |
| NRB_FUNCTION_QUERY_PINNED_SET | Get the Logical Block Address (LBA) ranges currently in the NV Cache Manager pinned set. |
| NRB_FUNCTION_QUERY_CACHE_MISS | Request that the device report NV Cache Misses in LBA ranges in a single 512-byte block. |
| NRB_FUNCTION_ADD_LBAS_PINNED_SET | Add the LBAs that are specified in the NV Cache Manager Set Data to the NV Cache Manager Pinned Set if they are not already. |
| NRB_FUNCTION_REMOVE_LBAS_PINNED_SET | Remove the LBAs that are specified in the NV Cache Set Data from the NV Cache pinned set. |
| NRB_FUNCTION_QUERY_HYBRID_DISK_STATUS | Reserved for future use. |
| NRB_FUNCTION_PASS_HINT_PAYLOAD | Pass IO hints to a SATA device. |

### `NRBFlags`

Reserved for future use.

### `NRBStatus`

Indicates the NV Cache Manager function request status from the driver. This can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| NRB_SUCCESS | No error. |
| NRB_ILLEGAL_REQUEST | Illegal request detected by the port driver. |
| NRB_INVALID_PARAMETER | Invalid parameter passed to the port driver. |
| NRB_INPUT_DATA_OVERRUN | Too much data provided to the port driver. |
| NRB_INPUT_DATA_UNDERRUN | Not enough data provided to the port driver. |
| NRB_OUTPUT_DATA_OVERRUN | Too much data returned from the port driver. |
| NRB_OUTPUT_DATA_UNDERRUN | Not enough data returned from the port driver. |

### `Count`

Number of 512-byte blocks to be transferred with the specified function.

### `LBA`

Starting LBA of the device for the specified function.

### `DataBufSize`

Size of the data buffer, in bytes.

### `NVCacheStatus`

Status returned from the device. For an ATA device, this value is the contents of the Status Register in its Task File. For a SCSI device, this value is the Sense Code returned from the device.

### `NVCacheSubStatus`

The error code returned from the device. For an ATA device, this value is the contents of the Error Register in its Task File. For a SCSI device, this value is the Sense key returned from the device.

## Remarks

For more information on function behavior, see section 7.20 of the ATA8-ACS specification.

## See also

[**IOCTL_SCSI_MINIPORT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport)

[**IOCTL_SCSI_MINIPORT_NVCACHE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddscsi/ni-ntddscsi-ioctl_scsi_miniport_nvcache)