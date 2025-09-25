# _CDROM_TOC_ATIP_DATA_BLOCK structure

## Description

Device control IRPs with a control code of [IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex) and a format of CDROM_READ_TOC_EX_FORMAT_ATIP return their output data in a header structure of type [CDROM_TOC_ATIP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data) followed by a series of ATIP data block descriptors defined by **CDROM_TOC_ATIP_DATA_BLOCK**.

## Members

### `CdrwReferenceSpeed`

Indicates the recommended write speed for the media. Values 0x00 to 0x01 are reserved. A value of 0x02 indicates a CD-ROM speed of 4X. A value of 0x03 indicates a CD-ROM speed of 8X. Values 0x04 to 0x07 are reserved.

### `Reserved3`

Reserved.

### `WritePower`

Indicates media's recommended initial laser power setting. The high order bit must be set to 1. The setting of the other bits varies between CD-R and CD-RW media. For an explanation of the values these bits can have, see the *SCSI Multimedia Commands - 3* (MMC-3) specification.

### `True1`

Must be set to 1.

### `Reserved4`

Reserved.

### `UnrestrictedUse`

Indicates, when set to 1, that the mounted disc is defined for unrestricted use. When set to zero, indicates that the mounted disc is defined for restricted use.

### `Reserved5`

Reserved.

### `A3Valid`

Indicates that bytes 16-18 (bytes 12-14 of the ATIP descriptor) are valid when set to 1. When set to zero, indicates that bytes 16-18 are invalid.

### `A2Valid`

Indicates that A2 values field is valid when set to 1. When set to zero, indicates that the A2 values field is invalid.

### `A1Valid`

Indicates that A3 values field is valid when set to 1. When set to zero, indicates that the A3 values field is invalid.

### `DiscSubType`

Must be set to zero.

### `IsCdrw`

Indicates the media is rewritable (CD-RW) when set to 1. When set to zero, indicates the media is write-once (CD-R).

### `True2`

Must be set to 1.

### `Reserved7`

Reserved.

### `LeadInMsf`

Indicates the ATIP start time of lead-in, in terms of minutes, seconds, and frames. Valid values of the first byte are from 0x50 to 0x63. For an explanation of the values that the second and third bytes can have, see the *SCSI Multimedia Commands - 3* (MMC-3) specification.

### `Reserved8`

Reserved.

### `LeadOutMsf`

Indicates the ATIP last possible start time of lead-out in terms of minutes, seconds, and frames. Valid values of the first byte are from 0x0 to 0x04F. For an explanation of the values that the second and third bytes can have, see the *SCSI Multimedia Commands - 3* (MMC-3) specification.

### `Reserved9`

Reserved.

### `A1Values`

See specification *T10/1363-D*, by National Committee for Information Technology Standards (NCITS) For information about the permissible values for this member.

### `Reserved10`

Reserved.

### `A2Values`

Reserved.

### `Reserved11`

Reserved.

### `A3Values`

Reserved.

### `Reserved12`

Reserved.

## See also

[CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_read_toc_ex)

[CDROM_TOC_ATIP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_toc_atip_data)

[IOCTL_CDROM_READ_TOC_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_read_toc_ex)