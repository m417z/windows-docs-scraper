# IFsrmClassificationManager::CreateModuleDefinition

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Creates a module definition of the specified type.

## Parameters

### `moduleType` [in]

The type of module to create (for example, a classifier or storage module). For possible types, see the
[FsrmPipelineModuleType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmpipelinemoduletype) enumeration.

### `moduleDefinition` [out]

An [IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)
interface to the new module definition. Query the
**IFsrmPipelineModuleDefinition** interface to
get the interface for the specified module. For example, if *moduleType* is
**FsrmPipelineModuleType_Classifier**, query the
**IFsrmPipelineModuleDefinition** interface
for the [IFsrmClassifierModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduledefinition)
interface.

To save the module definition, call
[IFsrmPipelineModuleDefinition::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

There is no limit to the number of modules that you can define.

In addition to defining the module with FSRM, you must also register the class with COM. This needs to be a
registration of a COM class that implements
[IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation) or
[IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation),
depending on the type of module.

FSRM provides the following built-in classifiers: the Folder Classifier and the Content Classifier. The Folder
Classifier classifies files based on the folder in which they are stored. The Content Classifier classifies by
searching for strings and regular expressions in the file using Windows text extraction methods.

FSRM provides the following three built-in storage modules:

* System Cache Storage Module—stores properties in an NTFS Alternate Data Stream
  cache.
* Office 97 - 2003 In-File Storage Module—stores properties within a Microsoft Office
  97 - 2003 file.
* Office 2007 In-File Storage Module—stores properties within a Microsoft Office
  2007 (or later) file.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::EnumModuleDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enummoduledefinitions)

[IFsrmClassificationManager::GetModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getmoduledefinition)

[IFsrmClassifierModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduledefinition)

[IFsrmPipelineModuleConnector::Bind](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduleconnector-bind)

[IFsrmStorageModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduledefinition)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)