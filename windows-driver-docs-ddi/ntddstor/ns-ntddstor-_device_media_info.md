# _DEVICE_MEDIA_INFO structure (ntddstor.h)

## Description

A storage class driver returns an array of **DEVICE_MEDIA_INFO** structures, embedded in a [**GET_MEDIA_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_get_media_types) structure, in response to an [**IOCTL_STORAGE_GET_MEDIA_TYPES_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_get_media_types_ex) device-control request.

## Members

### `DeviceSpecific`

### `DeviceSpecific.DiskInfo`

Describes a nonremovable (fixed) disk.

### `DeviceSpecific.DiskInfo.Cylinders`

Specifies the number of cylinders on this disk.

### `DeviceSpecific.DiskInfo.MediaType`

Specifies a [**MEDIA_TYPE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562216(v=vs.85)) of **FixedMedia**.

### `DeviceSpecific.DiskInfo.TracksPerCylinder`

Specifies the number of tracks per cylinder.

### `DeviceSpecific.DiskInfo.SectorsPerTrack`

Specifies the number of sectors per track.

### `DeviceSpecific.DiskInfo.BytesPerSector`

Specifies the number of bytes per sector.

### `DeviceSpecific.DiskInfo.NumberMediaSides`

Specifies the number of sides of the disk that can contain data: either 1 for one-sided media or 2 for two-sided media.

### `DeviceSpecific.DiskInfo.MediaCharacteristics`

Specifies characteristics of the disk indicated by one or more of the following flags.

* MEDIA_ERASEABLE 0x00000001
* MEDIA_WRITE_ONCE 0x00000002
* MEDIA_READ_ONLY 0x00000004
* MEDIA_READ_WRITE 0x00000008
* MEDIA_WRITE_PROTECTED 0x00000100
* MEDIA_CURRENTLY_MOUNTED 0x80000000

### `DeviceSpecific.RemovableDiskInfo`

Describes a removable (nonfixed) disk.

### `DeviceSpecific.RemovableDiskInfo.Cylinders`

Specifies the number of cylinders on this disk.

### `DeviceSpecific.RemovableDiskInfo.MediaType`

Specifies a [**MEDIA_TYPE**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff562216(v=vs.85)) or [**STORAGE_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_media_type) value that indicates the type of removable disk.

### `DeviceSpecific.RemovableDiskInfo.TracksPerCylinder`

Specifies the number of tracks per cylinder.

### `DeviceSpecific.RemovableDiskInfo.SectorsPerTrack`

Specifies the number of sectors per track.

### `DeviceSpecific.RemovableDiskInfo.BytesPerSector`

Specifies the number of bytes per sector.

### `DeviceSpecific.RemovableDiskInfo.NumberMediaSides`

Specifies the number of sides of the disk that can contain data: 1 for one-sided media or 2 for two-sided media.

### `DeviceSpecific.RemovableDiskInfo.MediaCharacteristics`

Specifies characteristics of the disk, indicated by MEDIA_*XXX* flags ORed together. For a list of these flags, see the **DeviceSpecific.DiskInfo.MediaCharacteristics** member of the **DeviceSpecific.DiskInfo** structure.

### `DeviceSpecific.TapeInfo`

Describes a tape.

### `DeviceSpecific.TapeInfo.MediaType`

Specifies a [**STORAGE_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_media_type) value that indicates the type of tape described in this structure.

### `DeviceSpecific.TapeInfo.MediaCharacteristics`

Specifies characteristics of the tape, indicated by MEDIA_*XXX* flags ORed together. For a list of these flags, see the **DeviceSpecific.DiskInfo.MediaCharacteristics** member of the **DeviceSpecific.DiskInfo** structure.

### `DeviceSpecific.TapeInfo.CurrentBlockSize`

Specifies the current block size, in bytes.

### `DeviceSpecific.TapeInfo.BusType`

Specifies a value of type [**STORAGE_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-storage_bus_type) that indicates the bus type.

### `DeviceSpecific.TapeInfo.BusSpecificData`

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation`

Specifies bus-specific information from mode page data that describes the medium supported by the tape drive. Values for other bus types will be supplied in a later release.

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation.MediumType`

Specifies the SCSI-specific medium type.

### `DeviceSpecific.TapeInfo.BusSpecificData.ScsiInformation.DensityCode`

Specifies the SCSI-specific current operating density for read/write operations.

## Remarks

This structure is used by a storage driver to indicate the types of media supported by a device and which type is currently mounted, if any. A driver must provide this information if it might control drives in a media library or changer or if its device might be accessed by the Removable Storage Manager (RSM).

The driver fills in an array of **DEVICE_MEDIA_INFO** structures, one for each medium type supported by the device, embedded in a [**GET_MEDIA_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-_get_media_types) structure.

## See also

[**STORAGE_MEDIA_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ne-ntddstor-_storage_media_type)

[**TapeMiniGetMediaTypes**](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)