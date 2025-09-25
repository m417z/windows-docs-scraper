# FsrmActionType enumeration

## Description

Defines the actions that can be triggered in response to a quota or file screen event (for example, a
quota is exceeded or a file violates a file screen). A file management job can also trigger the
action.

## Constants

### `FsrmActionType_Unknown:0`

The action is of an unknown type. Do not use this value to specify an action type.

### `FsrmActionType_EventLog:1`

Log an event to the Application event log.

### `FsrmActionType_Email:2`

Send an email message.

### `FsrmActionType_Command:3`

Execute a command or script.

### `FsrmActionType_Report:4`

Generate a report.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[FsrmAccountType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmaccounttype)

[FsrmEventType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmeventtype)

[IFsrmAction::ActionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmaction-get_actiontype)

[IFsrmFileManagementJob::CreateNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-createnotificationaction)

[IFsrmFileScreenBase::CreateAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreenbase-createaction)

[IFsrmQuotaBase::CreateThresholdAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotabase-createthresholdaction)

[IFsrmSetting::GetActionRunLimitInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-getactionrunlimitinterval)

[IFsrmSetting::SetActionRunLimitInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-setactionrunlimitinterval)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)