# GET_STORAGE_DEPENDENCY_FLAG enumeration

## Description

Contains virtual hard disk (VHD) storage dependency request flags.

## Constants

### `GET_STORAGE_DEPENDENCY_FLAG_NONE:0x00000000`

No flags specified.

### `GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES:0x00000001`

Return information for volumes or disks hosting the volume specified.

### `GET_STORAGE_DEPENDENCY_FLAG_DISK_HANDLE:0x00000002`

The handle provided is to a disk, not a volume or file.

## Remarks

If the **GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES** flag is not set, the [GetStorageDependencyInformation](https://learn.microsoft.com/windows/win32/api/virtdisk/nf-virtdisk-getstoragedependencyinformation) function returns information about the volumes or disks being hosted by the volume or disk specified. For example, if the VHD file C:\file.vhd defines the virtual drive D, setting the **GET_STORAGE_DEPENDENCY_FLAG_HOST_VOLUMES** flag will retrieve information about the C: volume. If not, information about the virtual D: volume will be retrieved.

## See also

[About VHD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323654(v=vs.85))

[VHD Reference](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd323700(v=vs.85))