# CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR structure

## Description

The **CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR** structure indicates that the result data from the [**IOCTL_CDROM_GET_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request is for exception conditions.

## Members

### `Lba[4]`

Indicates that there is a seek delay between the logical block address (LBA) and the preceding LBA (LBA -1).

### `Time[2]`

Indicates the expected additional seek delay between LBA and the preceding LBA (LBA - 1) from nominal, in units of tenths of milliseconds (100 microseconds). The cause of the seek delay might be linear replacement, zone boundaries, or other media dependent features.

## Remarks

Exception conditions are exception locations that could cause seek delays to occur. The **CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR** is returned by the **IOCTL_CDROM_GET_PERFORMANCE** I/O control request when the request type is **CdromPerformanceRequest** and the **Except** field of the [**CDROM_PERFORMANCE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header) is true (1). Separate descriptors are returned for read and write performance requests. The fields in **CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR** correspond to the similarly named fields in the Performance Descriptor - Exceptions table described in the *MultiMedia Command Set - 6 (MMC-6)* specification.

## See also

[**CDROM_PERFORMANCE_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header)

[**IOCTL_CDROM_GET_PERFORMANCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)