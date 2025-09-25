# STORAGE_RESERVE_ID enumeration

## Description

**STORAGE_RESERVE_ID** defines values for the storage reserve ID of a file, directory, or storage reserve area. The values are used by the [**FILE_STORAGE_RESERVE_ID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_storage_reserve_id_information) structure.

## Constants

### `StorageReserveIdNone`

The file or directory is not associated with any particular storage reserve area. Files created by users and applications are treated as having StorageReserveIdNone by default, unless they are created inside a directory that has been marked with a different storage reserve ID.

### `StorageReserveIdHard`

The file or directory is part of the "Hard" storage reserve area, which is used by the system to help ensure there is sufficient disk space to download and install updates. **_Warning: A file or directory marked as StorageReserveIdHard may be deleted automatically by the system at any time, without user consent._**

### `StorageReserveIdSoft`

The file or directory is part of the "Soft" storage reserve area, which is used by the system to help ensure there is sufficient disk space to install updates. **_Warning: A file or directory marked as StorageReserveIdSoft may be deleted automatically by the system at any time, without user consent._**

### `StorageReserveIdUpdateScratch`

The file or directory is part of the "Update Scratch" storage reserve area, which is used by the system to help ensure there is sufficient disk space to install an update from scratch. **_Warning: A file or directory marked as StorageReserveIdSoft may be deleted automatically by the system at any time, without user consent._**

### `StorageReserveIdMax`

Marks the limit of predefined storage reserve IDs currently understood by the system. File systems that support storage reserves may support IDs beyond this to allow for future use.

## See also

[**FILE_STORAGE_RESERVE_ID_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_storage_reserve_id_information)