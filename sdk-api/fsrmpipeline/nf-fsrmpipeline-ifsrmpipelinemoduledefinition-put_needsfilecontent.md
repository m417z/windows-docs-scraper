# IFsrmPipelineModuleDefinition::put_NeedsFileContent

## Description

Determines whether the module needs to read the contents of the file.

This property is read/write.

## Parameters

## Remarks

If the
**NeedsFileContent** property
value is **VARIANT_TRUE**, FSRM will provide a stream for a file's contents to the module.
This may be necessary if a classification module needs to analyze the contents of the file to determine the
property values or if a storage module handles property values embedded in the file's contents

## See also

[IFsrmPipelineModuleDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpipelinemoduledefinition)