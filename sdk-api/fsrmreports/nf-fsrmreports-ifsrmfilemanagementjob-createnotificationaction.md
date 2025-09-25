# IFsrmFileManagementJob::CreateNotificationAction

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Creates a notification action and associates it with the notification value.

## Parameters

### `days` [in]

The notification value to associate with the action.

### `actionType` [in]

The action to perform when the notification period is reached, enumerated by the
[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype) enumeration.

**Note** The **FsrmActionType_Report** type is not valid for this method.

#### FsrmActionType_EventLog (1)

Log an event to the Application event log.

#### FsrmActionType_Email (2)

Send an email message.

#### FsrmActionType_Command (3)

Execute a command or script.

### `action` [out]

An [IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface of the newly created action.
Query the interface for the action interface that you specified in the *actionType*
parameter. For example, if the action type is **FsrmActionType_Command**, query the
interface for the [IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand) interface.

## Return value

The method returns the following return values.

## Remarks

You can specify up to three unique actions for each notification value.

The action is deleted when the notification is deleted.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[IFsrmFileManagementJob::EnumNotificationActions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-enumnotificationactions)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)