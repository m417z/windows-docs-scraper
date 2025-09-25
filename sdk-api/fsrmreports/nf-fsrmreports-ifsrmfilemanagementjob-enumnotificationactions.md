# IFsrmFileManagementJob::EnumNotificationActions

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Enumerates the actions associated with a notification value.

## Parameters

### `days` [in]

The notification value that contains the actions that you want to enumerate.

### `actions` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a collection of actions. The variant type of each item in the collection is **VT_DISPATCH**. Query the **pdispVal** member of the variant to get an [IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction) interface. You can use the [IFsrmAction::ActionType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmaction-get_actiontype) property to determine the actual action interface to query.

## Return value

The method returns the following return values.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[IFsrmFileManagementJob::CreateNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-createnotificationaction)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)