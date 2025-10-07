# IFsrmFileManagementJob::get_MailTo

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The email addresses to which to send the reports, if any.

This property is read/write.

## Parameters

## Remarks

This property is optional.

The email message is sent only if the job finishes successfully. Email is not sent for
**FsrmReportType_ExportReport** report types. The reports are attached to the email
message. You can specify [Admin Email] to send notification to the administrator (if the
[IFsrmSetting::AdminEmail](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_adminemail) property is set). The
subject is "\<ReportType>: \<ReportName>". The body of the email message is empty.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)