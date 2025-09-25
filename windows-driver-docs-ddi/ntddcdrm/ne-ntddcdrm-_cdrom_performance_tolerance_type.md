# _CDROM_PERFORMANCE_TOLERANCE_TYPE enumeration

## Description

The **CDROM_PERFORMANCE_TOLERANCE_TYPE** enumeration defines the allowable tolerances for performance data. It is a member of the [CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request) structure, which is used as an input parameter to the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request.

## Constants

### `Cdrom10Nominal20Exceptions`

Specifies that the descriptors returned have a 10% performance tolerance for the nominal performance and a 20% time tolerance for the exception list.

## See also

[CDROM_PERFORMANCE_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_request)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)