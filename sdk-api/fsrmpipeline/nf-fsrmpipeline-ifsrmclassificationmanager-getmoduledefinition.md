# IFsrmClassificationManager::GetModuleDefinition

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Retrieves the specified module definition.

## Parameters

### `moduleName` [in]

The name of the module to retrieve. Must not exceed 100 characters in length.

### `moduleType` [in]

The type of the module to retrieve. For possible types, see the
[FsrmPipelineModuleType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpipelinemoduletype) enumeration.

### `moduleDefinition` [out]

An [IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)
interface to the retrieved module definition. Query the
**IFsrmPipelineModuleDefinition** interface to
get the interface for the specified module. For example, if *moduleType* is
**FsrmPipelineModuleType_Classifier**, query the
**IFsrmPipelineModuleDefinition** interface for
the [IFsrmClassifierModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduledefinition)
interface.

## Return value

The method returns the following return values.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::CreateModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-createmoduledefinition)

[IFsrmClassificationManager::EnumModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enummoduledefinitions)

[IFsrmClassifierModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduledefinition)

[IFsrmStorageModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduledefinition)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)