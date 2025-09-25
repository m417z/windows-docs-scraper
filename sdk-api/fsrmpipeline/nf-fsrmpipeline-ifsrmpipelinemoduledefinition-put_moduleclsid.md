# IFsrmPipelineModuleDefinition::put_ModuleClsid

## Description

A string representation specifying the COM class identifier for the class that implements the module defined by this module definition.

This property is read/write.

## Parameters

## Remarks

Note that the COM class identifier specified must refer to a class that implements [IFsrmPipelineModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleimplementation), which is inherited though [IFsrmClassifierModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassifiermoduleimplementation) or [IFsrmStorageModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmstoragemoduleimplementation), depending on the type of module.

## See also

[IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)