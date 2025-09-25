# IFsrmFileManagementJob::get_CustomAction

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The action to execute when all the conditions are met.

This property is read-only.

## Parameters

## Remarks

To create the custom action, call the
[IFsrmFileManagementJob::CreateCustomAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-createcustomaction)
method.

For a list of macros supported, perform a "get" operation on the
[IFsrmFileManagementJobManager::ActionVariables](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-get_actionvariables)
and
[IFsrmFileManagementJobManager::ActionVariableDescriptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-get_actionvariabledescriptions)
properties.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)