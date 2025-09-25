## Description

The MEDIA\_TYPE enumerators are used in conjunction with the [**IOCTL\_DISK\_FORMAT\_TRACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks) request to format the specified set of contiguous tracks on the disk.

## Constants

### `Unknown`

Format is unknown.

### `F5_1Pt2_512`

Indicates 5.25", 1.2 MB, 512 bytes/sector media.

### `F3_1Pt44_512`

Indicates 3.5", 1.44 MB, 512 bytes/sector media.

### `F3_2Pt88_512`

Indicates 3.5", 2.88 MB, 512 bytes/sector media.

### `F3_20Pt8_512`

Indicates 3.5", 20.8 MB, 512 bytes/sector media.

### `F3_720_512`

Indicates 3.5", 720 KB, 512 bytes/sector media.

### `F5_360_512`

Indicates 5.25", 360 KB, 512 bytes/sector media.

### `F5_320_512`

Indicates 5.25", 320 KB, 512 bytes/sector media.

### `F5_320_1024`

Indicates 5.25", 320 KB, 1024 bytes/sector media.

### `F5_180_512`

Indicates 5.25", 180 KB, 512 bytes/sector media.

### `F5_160_512`

Indicates 5.25", 160 KB, 512 bytes/sector media.

### `RemovableMedia`

Indicates removable media other than a floppy disk.

### `FixedMedia`

Indicates fixed hard disk media.

### `F3_120M_512`

Indicates 3.5", 120 MB media.

### `F3_640_512`

Indicates 3.5", 640 KB, 512 bytes/sector media.

### `F5_640_512`

Indicates 5.25", 640 KB, 512 bytes/sector media.

### `F5_720_512`

Indicates 5.25", 720 KB, 512 bytes/sector media.

### `F3_1Pt2_512`

Indicates 3.5", 1.2 MB, 512 bytes/sector media.

### `F3_1Pt23_1024`

Indicates 3.5", 1.23 MB, 1024 bytes/sector media.

### `F5_1Pt23_1024`

Indicates 5.25", 1.23 MB, 1024 bytes/sector media.

### `F3_128Mb_512`

Indicates 3.5" magneto-optical (MO), 128 MB, 512 bytes/sector media.

### `F3_230Mb_512`

Indicates 3.5" magneto-optical (MO), 230 MB, 512 bytes/sector media.

### `F8_256_128`

Indicates 8", 256 KB, 128 bytes/sector media.

### `F3_200Mb_512`

3.5", 200M Floppy (HiFD)

### `F3_240M_512`

3.5", 240Mb Floppy (HiFD)

### `F3_32M_512`

3.5", 32Mb Floppy

## Remarks

The caller of the IOCTL\_DISK\_FORMAT\_TRACK request indicates the disk size and number of bytes per sector, along with other formatting information, by specifying one of these values in the **MediaType** member of the [**FORMAT\_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_parameters) structure.

Removable disks include zip drivers, jaz drives, magneto-optical (MO) drives, and LS-120 floppies as well as regular floppies.

## See also

[**IOCTL\_DISK\_FORMAT\_TRACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ni-ntdddisk-ioctl_disk_format_tracks)

[**FORMAT\_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_format_parameters)