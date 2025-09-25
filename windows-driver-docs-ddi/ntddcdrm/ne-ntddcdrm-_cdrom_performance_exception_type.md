# _CDROM_PERFORMANCE_EXCEPTION_TYPE enumeration

## Description

The **CDROM_PERFORMANCE_EXCEPTION_TYPE** enumeration defines the exceptional conditions for performance data. It is a member of the [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) structure, which is used as an input parameter to the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request.

## Constants

### `CdromNominalPerformance`

Requests nominal performance parameters.

### `CdromEntirePerformanceList`

Requests the entire performance list, as qualified by the **StartingLba** field of the [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) structure.

### `CdromPerformanceExceptionsOnly`

Requests only performance exceptions that cause the performance to fall outside the nominal.

## See also

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)