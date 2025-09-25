# MEDIA_TYPE enumeration

## Description

Represents the various forms of device media.

## Constants

### `Unknown:0`

Format is unknown

### `F5_1Pt2_512`

A 5.25" floppy, with 1.2MB and 512 bytes/sector.

### `F3_1Pt44_512`

A 3.5" floppy, with 1.44MB and 512 bytes/sector.

### `F3_2Pt88_512`

A 3.5" floppy, with 2.88MB and 512 bytes/sector.

### `F3_20Pt8_512`

A 3.5" floppy, with 20.8MB and 512 bytes/sector.

### `F3_720_512`

A 3.5" floppy, with 720KB and 512 bytes/sector.

### `F5_360_512`

A 5.25" floppy, with 360KB and 512 bytes/sector.

### `F5_320_512`

A 5.25" floppy, with 320KB and 512 bytes/sector.

### `F5_320_1024`

A 5.25" floppy, with 320KB and 1024 bytes/sector.

### `F5_180_512`

A 5.25" floppy, with 180KB and 512 bytes/sector.

### `F5_160_512`

A 5.25" floppy, with 160KB and 512 bytes/sector.

### `RemovableMedia`

Removable media other than floppy.

### `FixedMedia`

Fixed hard disk media.

### `F3_120M_512`

A 3.5" floppy, with 120MB and 512 bytes/sector.

### `F3_640_512`

A 3.5" floppy, with 640KB and 512 bytes/sector.

### `F5_640_512`

A 5.25" floppy, with 640KB and 512 bytes/sector.

### `F5_720_512`

A 5.25" floppy, with 720KB and 512 bytes/sector.

### `F3_1Pt2_512`

A 3.5" floppy, with 1.2MB and 512 bytes/sector.

### `F3_1Pt23_1024`

A 3.5" floppy, with 1.23MB and 1024 bytes/sector.

### `F5_1Pt23_1024`

A 5.25" floppy, with 1.23MB and 1024 bytes/sector.

### `F3_128Mb_512`

A 3.5" floppy, with 128MB and 512 bytes/sector.

### `F3_230Mb_512`

A 3.5" floppy, with 230MB and 512 bytes/sector.

### `F8_256_128`

An 8" floppy, with 256KB and 128 bytes/sector.

### `F3_200Mb_512`

A 3.5" floppy, with 200MB and 512 bytes/sector. (HiFD).

### `F3_240M_512`

A 3.5" floppy, with 240MB and 512 bytes/sector. (HiFD).

### `F3_32M_512`

A 3.5" floppy, with 32MB and 512 bytes/sector.

## Remarks

The **MediaType** member of the [DISK_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry) data structure is of type **MEDIA_TYPE**. The [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function receives a **DISK_GEOMETRY** structure in response to an [IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry) control code. The **DeviceIoControl** function receives an array of **DISK_GEOMETRY** structures in response to an [IOCTL_STORAGE_GET_MEDIA_TYPES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_get_media_types) control code. The [STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_media_type) enumeration type extends this enumeration type.

## See also

* [DISK_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ns-winioctl-disk_geometry)
* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [IOCTL_DISK_GET_DRIVE_GEOMETRY](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_disk_get_drive_geometry)
* [IOCTL_STORAGE_GET_MEDIA_TYPES](https://learn.microsoft.com/windows/win32/api/winioctl/ni-winioctl-ioctl_storage_get_media_types)
* [STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/win32/api/winioctl/ne-winioctl-storage_media_type)