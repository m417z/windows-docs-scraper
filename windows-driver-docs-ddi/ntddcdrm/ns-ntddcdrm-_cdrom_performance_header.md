# _CDROM_PERFORMANCE_HEADER structure

## Description

The CDROM_PERFORMANCE_HEADER structure is used by the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) IOCTL to return data. When the request type is CdromPerformanceRequest, the IOCTL returns this header followed by optional descriptors.

## Members

### `DataLength`

The size of the available data (not just the size of returned data). The size does not include this **Datalength** field.

### `Except`

The format of the descriptors that follow the header depend on the value in this field. If false (0), the [CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_nominal_performance_descriptor) follows the **CDROM_PERFORMANCE_HEADER** in the returned data. If true (1), the [CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exception_performance_descriptor) follows the **CDROM_PERFORMANCE_HEADER** in the returned data.

### `Write`

Indicates whether the result data is for read or write performance. If false (0), it indicates that the result data is for read performance. If true (1), it indicates that the result data is for write performance.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

### `Data`

Contains a list of the following records, depending upon the type of request: [CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_nominal_performance_descriptor),
[CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exception_performance_descriptor),
[CDROM_WRITE_SPEED_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_write_speed_descriptor).

## See also

[CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_exception_performance_descriptor)

[CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_nominal_performance_descriptor)

[CDROM_WRITE_SPEED_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_write_speed_descriptor)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)