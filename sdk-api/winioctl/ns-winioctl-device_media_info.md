# DEVICE_MEDIA_INFO structure

## Description

Provides information about the media supported by a device.

## Members

### `DeviceSpecific`

A union that contains the following members.

### `DeviceSpecific.DiskInfo`

A structure that contains the following members.

### `DeviceSpecific.DiskInfo.Cylinders`

The number of cylinders on this disk.

### `DeviceSpecific.DiskInfo.MediaType`

The media type. This member can be one of the values from the
[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type) or
[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type) enumeration types.

### `DeviceSpecific.DiskInfo.TracksPerCylinder`

The number of tracks per cylinder.

### `DeviceSpecific.DiskInfo.SectorsPerTrack`

The number of sectors per track.

### `DeviceSpecific.DiskInfo.BytesPerSector`

The number of bytes per sector.

### `DeviceSpecific.DiskInfo.NumberMediaSides`

The number of sides of the disk that can contain data. This member is 1 for one-sided media or 2 for
two-sided media.

### `DeviceSpecific.DiskInfo.MediaCharacteristics`

The characteristics of the media. This member can be one or more of the following values.

###### DiskInfo.MediaCharacteristics.MEDIA_CURRENTLY_MOUNTED (0x80000000)

###### DiskInfo.MediaCharacteristics.MEDIA_ERASEABLE (0x00000001)

###### DiskInfo.MediaCharacteristics.MEDIA_READ_ONLY (0x00000004)

###### DiskInfo.MediaCharacteristics.MEDIA_READ_WRITE (0x00000008)

###### DiskInfo.MediaCharacteristics.MEDIA_WRITE_ONCE (0x00000002)

###### DiskInfo.MediaCharacteristics.MEDIA_WRITE_PROTECTED (0x00000100)

### `DeviceSpecific.RemovableDiskInfo`

A structure that contains the following members.

### `DeviceSpecific.RemovableDiskInfo.Cylinders`

The number of cylinders on this disk.

### `DeviceSpecific.RemovableDiskInfo.MediaType`

The media type. This member can be one of the values from the
[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type) or
[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type) enumeration types.

### `DeviceSpecific.RemovableDiskInfo.TracksPerCylinder`

The number of tracks per cylinder.

### `DeviceSpecific.RemovableDiskInfo.SectorsPerTrack`

The number of sectors per track.

### `DeviceSpecific.RemovableDiskInfo.BytesPerSector`

The number of bytes per sector.

### `DeviceSpecific.RemovableDiskInfo.NumberMediaSides`

The number of sides of the disk that can contain data. This member is 1 for one-sided media or 2 for
two-sided media.

### `DeviceSpecific.RemovableDiskInfo.MediaCharacteristics`

The characteristics of the media. This member can be one or more of the following values.

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_CURRENTLY_MOUNTED (0x80000000)

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_ERASEABLE (0x00000001)

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_READ_ONLY (0x00000004)

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_READ_WRITE (0x00000008)

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_WRITE_ONCE (0x00000002)

###### RemovableDiskInfo.MediaCharacteristics.MEDIA_WRITE_PROTECTED (0x00000100)

### `DeviceSpecific.TapeInfo`

A structure that contains the following members.

### `DeviceSpecific.TapeInfo.MediaType`

The media type. This member can be one of the values from the
[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type) or
[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type) enumeration types.

### `DeviceSpecific.TapeInfo.MediaCharacteristics`

The characteristics of the media. This member can be one or more of the following values.

###### TapeInfo.MediaCharacteristics.MEDIA_CURRENTLY_MOUNTED (0x80000000)

###### TapeInfo.MediaCharacteristics.MEDIA_ERASEABLE (0x00000001)

###### TapeInfo.MediaCharacteristics.MEDIA_READ_ONLY (0x00000004)

###### TapeInfo.MediaCharacteristics.MEDIA_READ_WRITE (0x00000008)

###### TapeInfo.MediaCharacteristics.MEDIA_WRITE_ONCE (0x00000002)

###### TapeInfo.MediaCharacteristics.MEDIA_WRITE_PROTECTED (0x00000100)

### `DeviceSpecific.TapeInfo.CurrentBlockSize`

The current block size, in bytes.

### `DeviceSpecific.TapeInfo.BusType`

The type of bus to which the tape drive is connected. This members can be one of the
[STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_bus_type) enumeration values.

### `DeviceSpecific.TapeInfo.BusSpecificData`

A union that contains the following members.

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation`

A structure that contains the following members.

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation.MediumType`

The SCSI-specific medium type.

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation.DensityCode`

The SCSI-specific current operating density for read/write operations.

## See also

[GET_MEDIA_TYPES](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-get_media_types)

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)

[MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-media_type)

[STORAGE_BUS_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_bus_type)

[STORAGE_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/winioctl/ne-winioctl-storage_media_type)