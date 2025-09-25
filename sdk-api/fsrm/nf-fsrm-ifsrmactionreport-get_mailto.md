# IFsrmActionReport::get_MailTo

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Retrieves or sets the email address to which the reports are sent.

This property is read/write.

## Parameters

## Remarks

The email message contains the reports as attachments. It is possible that the mail server may reject the
message if the server limits attachment sizes. The
[IFsrmSetting::MailFrom](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_mailfrom) property specifies the
sender of the email. The subject and message body contain predefined text that identifies the quota that caused
the notification. The email addresses are not checked for format until the action is run.

You can also call the
[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory)
method to specify the storage location for these incident reports.

#### Examples

For an example, see [Updating a Quota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/updating-a-quota).

## See also

[IFsrmActionReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactionreport)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)

[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction)

[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)