# IFsrmFileManagementJob::AddNotification

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFMJNotification::CreateFMJNotification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotification-createfmjnotification)
method.]

Adds a new notification value (period) to the file management job's list of
notifications.

## Parameters

### `days` [in]

A unique notification value to add. The value cannot be less than zero.

## Return value

The method returns the following return values.

## Remarks

The *days* parameter specifies the number of days before the file is to expire. If the
appropriate conditions set in the job are met, notification will be sent to the user to let them know that the
file is about to expire. FSRM uses the actions associated with the notification value to determine how the user is
notified.

Notification occurs when the job runs and the following conditions are met:

* Today is the day when notification should occur.
* The day when notification should occur is before the next scheduled run time.

Note that it is possible for the user to receive duplicate notifications. For example, the user can receive
duplicate notifications if the job is run manually after the notification is sent but on or before the day when
the notification should occur.

The [FromDate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_fromdate) determines when the
notification window begins. The following properties determine when the file is to expire:

* [DaysSinceFileCreated](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_dayssincefilecreated)
* [DaysSinceFileLastAccessed](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_dayssincefilelastaccessed)
* [DaysSinceFileLastModified](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_dayssincefilelastmodified)
* [PropertyConditions](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_propertyconditions) (use
  the
  [CreatePropertyCondition](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-createpropertycondition)
  method to create the property condition)
* [FileNamePattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_filenamepattern)

To associate an action with the notification value, call the
[IFsrmFileManagementJob::CreateNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-createnotificationaction)
method.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[IFsrmFileManagementJob::DeleteNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-deletenotification)

[IFsrmFileManagementJob::ModifyNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-modifynotification)

[IFsrmFileManagementJob::Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_notifications)

[MSFT_FSRMFMJNotification::CreateFMJNotification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotification-createfmjnotification)