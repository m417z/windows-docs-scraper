## Description

Binds the pipeline module implementation to the FSRM communication channel.

## Parameters

### `moduleDefinition` [in]

An [IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition) interface that contains the definition of the module.

### `moduleImplementation` [in]

An [IFsrmPipelineModuleImplementation](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleimplementation) interface to the module's implementation.

## Return value

The method returns the following return values.

## Remarks

Call this method from your [IFsrmPipelineModuleImplementation::OnLoad](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduleimplementation-onload) implementation.

## See also

[FsrmPipelineModuleConnector](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmpipelinemoduleconnector)

[IFsrmPipelineModuleConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduleconnector)