# FsrmPipelineModuleType enumeration

## Description

Defines the types of modules that you can define.

## Constants

### `FsrmPipelineModuleType_Unknown:0`

The module type is unknown; do not use this value.

### `FsrmPipelineModuleType_Storage:1`

The module is a storage module. A storage module persists property values for the files that it
supports.

### `FsrmPipelineModuleType_Classifier:2`

The module is a classifier module. A classifier module assigns property values to files based on
classification rules.

## See also

[IFsrmClassificationManager::CreateModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-createmoduledefinition)

[IFsrmClassificationManager::EnumModuleDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enummoduledefinitions)

[IFsrmClassificationManager::GetModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getmoduledefinition)

[IFsrmPipelineModuleDefinition.ModuleType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduledefinition-get_moduletype)