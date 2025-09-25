# IFsrmPipelineModuleDefinition::put_SupportedExtensions

## Description

The list of file extensions supported by this module.

This property is read/write.

## Parameters

## Remarks

This property is optional. Set this property only if you support a limited number of file types. FSRM uses the
list of extensions to determine the files that it sends to the module. If the list is empty, FSRM will send the
module all files.

## See also

[IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)