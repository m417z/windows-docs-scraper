# __RAW_READ_INFO structure

## Description

The RAW_READ_INFO structure is used in conjunction with the [IOCTL_CDROM_RAW_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_raw_read) request to read data from a CD-ROM in raw mode.

## Members

### `DiskOffset`

Contains an offset into the CD-ROM disc where data will be read. You can calculate this offset by multiplying the starting sector number for the request times 2048.

### `SectorCount`

Contains the number of sectors to read.

### `TrackMode`

Contains an enumerator of type [TRACK_MODE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_track_mode_type) that indicates the type of the track mode.

## See also

[IOCTL_CDROM_RAW_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_raw_read)

[TRACK_MODE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_track_mode_type)