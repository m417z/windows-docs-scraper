# _CDROM_PERFORMANCE_REQUEST_TYPE enumeration

## Description

The CDROM_PERFORMANCE_REQUEST_TYPE enumeration defines the types of performance data requests. It is a member of the [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) structure, which is used as an input parameter to the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request.

## Constants

### `CdromPerformanceRequest`

Requests streaming performance data.

### `CdromWriteSpeedRequest`

Requests the write speed descriptor.

## See also

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)