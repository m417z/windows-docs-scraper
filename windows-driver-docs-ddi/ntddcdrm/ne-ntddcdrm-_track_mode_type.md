# _TRACK_MODE_TYPE enumeration

## Description

The TRACK_MODE_TYPE enumeration type is used in conjunction with the [IOCTL_CDROM_RAW_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_raw_read) request and the [RAW_READ_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-__raw_read_info) structure to read data from a CD-ROM in raw mode.

## Constants

### `YellowMode2`

Indicates that CD-ROM mode should be used. This mode is used with read-only 120 mm Optical Data Discs (CD-ROM). For more information, see the ISO/IEC 10149 specification.

### `XAForm2`

Indicates that compact disc read-only memory extended architecture mode should be used. For more information see the specification for CD-ROM XA published by NV Philips and Sony Corporation.

### `CDDA`

Indicates that digital audio information mode should be used. For more information, see the IEC 908:1987 specification.

### `RawWithC2AndSubCode`

CD_RAW_SECTOR_WITH_C2_AND_SUBCODE_SIZE per sector

### `RawWithC2`

CD_RAW_SECTOR_WITH_C2_SIZE per sector

### `RawWithSubCode`

CD_RAW_SECTOR_WITH_SUBCODE_SIZE per sector

## See also

[IOCTL_CDROM_RAW_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_raw_read)

[RAW_READ_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-__raw_read_info)