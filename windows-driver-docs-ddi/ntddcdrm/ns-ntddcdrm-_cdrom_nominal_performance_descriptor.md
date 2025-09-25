# _CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR structure

## Description

The **CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR** structure gives the host an approximation of logical unit
performance. It is returned by the [IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance) I/O control request when the request type is **CdromPerformanceRequest** and the **Except** field of the [CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header) is false (0). Separate descriptors are returned for read and write performance requests. The fields in **CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR** correspond to the similarly named fields in the "Performance Descriptor - Nominal Performance" table described in the MultiMedia Command Set - 6 (MMC-6)
specification.

## Members

### `StartLba`

The StartLba field (Start LBA) contains the first logical block address of the extent described by this descriptor.

### `StartPerformance`

The StartPerformance field (Start Performance) contains the nominal logical unit performance at the Start LBA in kilobytes per second.

### `EndLba`

The EndLba field (End LBA) contains the last logical block address of the extent described by this descriptor.

### `EndPerformance`

The EndPerformance field (End Performance) contains the nominal logical unit performance at the End LBA in kilobytes per second.

## See also

[CDROM_PERFORMANCE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_performance_header)

[IOCTL_CDROM_GET_PERFORMANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_get_performance)