# _CDROM_TOC_FULL_TOC_DATA structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) and a format of CDROM_READ_TOC_EX_FORMAT_FULL_TOC return their output data in this structure optionally followed by a series of descriptors of type [CDROM_TOC_FULL_TOC_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data_block).

## Members

### `Length`

Indicates the length, in bytes, of the table of contents data. This length value does not include the length of the **Length** member itself.

### `FirstCompleteSession`

Contains the number of the first complete session.

### `LastCompleteSession`

Contains the number of last complete session.

### `Descriptors`

Contains zero or more track descriptors. See [CDROM_TOC_FULL_TOC_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data_block) for a description of the track descriptor.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[CDROM_TOC_FULL_TOC_DATA_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_full_toc_data_block)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)