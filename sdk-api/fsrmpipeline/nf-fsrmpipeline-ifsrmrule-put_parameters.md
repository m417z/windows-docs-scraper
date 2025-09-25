# IFsrmRule::put_Parameters

## Description

The parameters that are passed to the classifier.

This property is read/write.

## Parameters

## Remarks

Specify parameters only if the classifier expects the rule to pass parameters.

The parameters are not passed directly to the classifier. Instead the rule is passed to the classifier which contains the parameters (see the [IFsrmPipelineModuleImplementation::OnLoad](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpipelinemoduleimplementation-onload) method).

FSRM does not limit the length of the parameter name or value, nor does it limit the number of parameters that you can specify. Specifying a parameter without a value is valid (for example, "parameter=").

## See also

[IFsrmRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmrule)