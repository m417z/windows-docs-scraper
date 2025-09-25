# IFsrmClassificationRule::put_Value

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassificationrule) class.]

The value that this rule will set the property to.

This property is read/write.

## Parameters

## Remarks

The classifier determines whether you must specify a value. If the classifier sets the
[IFsrmClassifierModuleDefinition.NeedsExplicitValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduledefinition-get_needsexplicitvalue)
property to **VARIANT_TRUE**, then you must provide a value; otherwise, the classifier
determines the value to set the property's value to (do not set this property).

## See also

[IFsrmClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationrule)

[MSFT_FSRMClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassificationrule)