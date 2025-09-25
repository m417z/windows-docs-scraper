# _CDROM_TOC_ATIP_DATA structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) and a format of CDROM_READ_TOC_EX_FORMAT_ATIP return their output data in this header structure followed by a series of descriptors of type [CDROM_TOC_ATIP_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data_block).

## Members

### `Length`

Indicates the number of bytes to be transferred in response to the command. This length value does not include the length of the **Length** member itself.

### `Reserved1`

Reserved.

### `Reserved2`

Reserved.

### `Descriptors`

Contains zero or more ATIP data block descriptors of type [CDROM_TOC_ATIP_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data_block).

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[CDROM_TOC_ATIP_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data_block)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)