# _CDROM_PERFORMANCE_TYPE enumeration

## Description

The **CDROM_PERFORMANCE_TYPE** enumeration defines the read and write performance data requests. It is a member of the [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) structure, which is used as an input parameter to the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request.

## Constants

### `CdromReadPerformance`

Requests streaming read performance data.

### `CdromWritePerformance`

Requests streaming write performance data.

## See also

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)