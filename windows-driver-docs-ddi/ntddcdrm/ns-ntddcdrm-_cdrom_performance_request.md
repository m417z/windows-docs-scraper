# CDROM_PERFORMANCE_REQUEST structure

## Description

The **CDROM_PERFORMANCE_REQUEST** structure is used as an input parameter to the [**IOCTL_CDROM_GET_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request and describes the performance data requested.

## Members

### `RequestType`

The [**CDROM_PERFORMANCE_REQUEST_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_performance_request_type) enumeration specifies the request type, **CdromPerformanceRequest**, or **CdromWriteSpeedRequest**.

### `PerformanceType`

The [**CDROM_PERFORMANCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_performance_type) enumeration specifies the type of performance data.

### `Exceptions`

The [**CDROM_PERFORMANCE_EXCEPTION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_performance_exception_type) enumeration specifies the type of exception.

### `Tolerance`

The [**CDROM_PERFORMANCE_TOLERANCE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_performance_tolerance_type) enumeration specifies the performance tolerance for the nominal performance and the time tolerance (seek delay) for the exception list.

### `StaringLba`

The starting logical block address field.

## See also

[**IOCTL_CDROM_GET_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)