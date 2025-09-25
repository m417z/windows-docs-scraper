# IFsrmFileManagementJob::CreateCustomAction

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Creates a custom action object.

## Parameters

### `customAction` [out]

An [IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand) interface that you can use
to specify a custom action to perform if the job's property conditions are met.

## Return value

The method returns the following return values. Implementers should return an
**HRESULT** error code for any other errors.

## Remarks

To get the custom action, access the
[CustomAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_customaction) property.

Create a custom action only if the job's
[OperationType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_operationtype) is set to
**FsrmFileManagementType_Custom**.

For a list of macros supported, perform a "get" operation on the
[IFsrmFileManagementJobManager::ActionVariables](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-get_actionvariables)
and
[IFsrmFileManagementJobManager::ActionVariableDescriptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-get_actionvariabledescriptions)
properties.

## See also

[IFsrmActionCommand::Arguments](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_arguments)

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)