# FILE_OBJECTID_BUFFER structure

## Description

Contains an object identifier and user-defined metadata associated with the object identifier.

## Members

### `ObjectId`

The identifier that uniquely identifies the file or directory within the volume on which it resides.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BirthVolumeId`

The identifier of the volume on which the object resided when the object identifier was created, or zero if the volume had no object identifier at that time. After copy operations, move operations, or other file operations, this may not be the same as the object identifier of the volume on which the object presently resides.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.BirthObjectId`

The object identifier of the object at the time it was created. After copy operations, move operations, or other file operations, this may not be the same as the **ObjectId** member at present.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.DomainId`

Reserved; must be zero.

### `DUMMYUNIONNAME.ExtendedInfo`

User-defined extended data to be set with [FSCTL_SET_OBJECT_ID_EXTENDED](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_object_id_extended). Use this data as an alternative to the **BirthVolumeId**, **BirthObjectId**, and **DomainId** members.

## Remarks

Object identifiers are used to track files and directories. They are invisible to most applications and should never be modified by applications. Modifying an object identifier can result in the loss of data from portions of a file, up to and including entire volumes of data.

## See also

[FSCTL_CREATE_OR_GET_OBJECT_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_create_or_get_object_id)

[FSCTL_DELETE_OBJECT_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_delete_object_id)

[FSCTL_GET_OBJECT_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_get_object_id)

[FSCTL_SET_OBJECT_ID](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_object_id)

[FSCTL_SET_OBJECT_ID_EXTENDED](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_set_object_id_extended)

[Object Identifiers](https://learn.microsoft.com/windows/desktop/FileIO/distributed-link-tracking-and-object-identifiers)