# IFsrmFileManagementJob::CreatePropertyCondition

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Creates a new property condition and adds it to the collection of property conditions.

## Parameters

### `name` [in]

The name of the property definition that the condition applies to. To enumerate the defined property
definitions, call the
[IFsrmClassificationManager::EnumPropertyDefinitions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-enumpropertydefinitions)
method.

### `propertyCondition` [out]

An [IFsrmPropertyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmpropertycondition) interface that you
use to define the newly created property condition.

## Return value

The method returns the following return values.

## Remarks

To enumerate the collection of property conditions associated with the job, access the
[PropertyConditions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_propertyconditions)
property.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)