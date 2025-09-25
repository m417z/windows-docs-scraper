# FsrmStorageModuleType enumeration

## Description

Defines the possible storage module types.

## Constants

### `FsrmStorageModuleType_Unknown:0`

The module type is unknown. Do not use this value.

### `FsrmStorageModuleType_Cache:1`

The storage module caches classification properties for quick access. This type is reserved for use by FSRM
and should not be used by any third party providers.

### `FsrmStorageModuleType_InFile:2`

The storage module stores classification properties within the file itself.

### `FsrmStorageModuleType_Database:3`

The storage module stores classification properties in a database.

### `FsrmStorageModuleType_System:100`

The storage module stores classification properties in system data store. This type is reserved for use by
FSRM and should not be used by any third party providers.

**Windows Server 2008 R2:** This storage module type is not supported before Windows Server 2012.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmStorageModuleDefinition.StorageType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduledefinition-get_storagetype)