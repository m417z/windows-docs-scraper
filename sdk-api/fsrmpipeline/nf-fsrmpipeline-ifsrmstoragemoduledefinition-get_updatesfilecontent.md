# IFsrmStorageModuleDefinition::get_UpdatesFileContent

## Description

Determines whether the module updates the contents of the file.

This property is read/write.

## Parameters

## Remarks

Setting this property to **VARIANT_TRUE** does not require that the
[IFsrmStorageModuleDefinition::StorageType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmstoragemoduledefinition-get_storagetype)
property to be set to **FsrmStorageModuleType_InFile**. For example, you can set this
property to **VARIANT_TRUE** if you need to update the file to let another process know that
you have processed the file.

## See also

[IFsrmStorageModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduledefinition)