# IFsrmClassificationManager::CreatePropertyDefinition

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Creates a property definition.

## Parameters

### `propertyDefinition` [out]

An [IFsrmPropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmpropertydefinition) interface to the
new property definition. To save the property definition, call
[IFsrmPropertyDefinition::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

You create a property definition to define the property that you want to use to classify files. One or more
classification rules can specify the property. The FSRM server limits the number of property definitions to
100.

You cannot delete a property that is referenced by a rule or report job.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmClassificationManager::EnumPropertyDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumpropertydefinitions)

[IFsrmClassificationManager::GetPropertyDefinition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-getpropertydefinition)

[IFsrmClassificationRule::PropertyAffected](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationrule-get_propertyaffected)

**MSFT_FSRMClassification**