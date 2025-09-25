# FsrmStorageModuleCaps enumeration

## Description

Flags that define the capabilities of the storage module.

## Constants

### `FsrmStorageModuleCaps_Unknown:0`

The storage module's capabilities are unknown. Do not use this value.

### `FsrmStorageModuleCaps_CanGet:0x1`

The storage module is allowed to retrieve classification properties.

### `FsrmStorageModuleCaps_CanSet:0x2`

The storage module is allowed to store classification properties.

### `FsrmStorageModuleCaps_CanHandleDirectories:0x4`

The storage module is allowed to handle folders. Only secure properties
(**FsrmPropertyDefinitionFlags_Secure** flags set on the
[PropertyDefinitionFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertydefinition2-get_propertydefinitionflags)
property) can be stored unless **FsrmStorageModuleCaps_CanHandleFiles** is also
specified.

**Windows Server 2008 R2:** This storage module capability is not supported before Windows Server 2012.

### `FsrmStorageModuleCaps_CanHandleFiles:0x8`

The storage module is allowed to handle files.

**Windows Server 2008 R2:** This storage module capability is not supported before Windows Server 2012.

## See also

[IFsrmStorageModuleDefinition.Capabilities](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduledefinition-get_capabilities)