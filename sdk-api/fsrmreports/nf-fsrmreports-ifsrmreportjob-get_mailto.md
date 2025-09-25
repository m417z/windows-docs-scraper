# IFsrmReportJob::get_MailTo

## Description

Retrieves or sets the email addresses of those that will receive the reports via email.

This property is read/write.

## Parameters

## Remarks

This property is optional.

The email message is sent only if the job finishes successfully. Email is not sent for
**FsrmReportType_ExportReport** report types. The reports are attached to the email
message. You can specify [Admin Email] to send notification to the administrator (if the
[IFsrmSetting::AdminEmail](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_adminemail) property is set). The
subject is "<ReportType>: <ReportName>". The body of the email message is empty.

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)