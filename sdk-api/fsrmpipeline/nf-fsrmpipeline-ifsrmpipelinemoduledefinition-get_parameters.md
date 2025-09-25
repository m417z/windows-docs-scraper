# IFsrmPipelineModuleDefinition::get_Parameters

## Description

The optional parameters to pass to the module.

This property is read/write.

## Parameters

## Remarks

There is no limit to length of the parameter name or value, nor is there a limit the number of parameters that you can specify. Specifying a parameter without a value is valid (for example, "parameter=").

The parameters are included in the module definition that FSRM passes to the module's [IFsrmPipelineModuleImplementation::OnLoad](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduleimplementation-onload) implementation.

## See also

[IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)