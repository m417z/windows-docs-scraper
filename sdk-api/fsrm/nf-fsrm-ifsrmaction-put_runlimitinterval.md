# IFsrmAction::put_RunLimitInterval

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Retrieves or sets the interval that must expire before the action is run again.

This property is read/write.

## Parameters

## Remarks

This property specifies the interval that should occur before the action is run again. For example, if the
interval has expired since the action last ran, the server will run the action again in response to an event;
otherwise, the server cannot run the action again.

You can specify the interval as follows.

| Interval | Description |
| --- | --- |
| –1 | Use the global run-time limit. For a description, see the [IFsrmSetting::SetActionRunLimitInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-setactionrunlimitinterval) method. |
| 0 | Run the action for each quota or file screen event. |
| >0 | If an event occurs during this interval, do not run the action again. The interval timer starts when the action begins. When the interval expires, the timer is reset. |

## See also

[IFsrmAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmaction)