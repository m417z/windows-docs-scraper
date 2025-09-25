# IFsrmClassificationRule::get_PropertyAffected

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassificationrule) class.]

The name of the property that this rule affects.

This property is read/write.

## Parameters

## Remarks

If the classifier specifies a list of properties that it affects (see
[IFsrmClassifierModuleDefinition::PropertiesAffected](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassifiermoduledefinition-get_propertiesaffected)), the property that you specify must exist in the list of affected properties.

To enumerate the properties that have been defined, call the [IFsrmClassificationManager::EnumPropertyDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumpropertydefinitions) method. To access the name of the property, use the [IFsrmPropertyDefinition.Name](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmpropertydefinition-get_name)
property.

## See also

[IFsrmClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationrule)

[MSFT_FSRMClassificationRule](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassificationrule)