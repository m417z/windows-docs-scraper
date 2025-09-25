# IFsrmClassificationManager::put_ClassificationReportMailTo

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

The email address to which to send the classification reports, if any.

This property is read/write.

## Parameters

## Remarks

This property is optional.

The email message is sent only if the classification finishes successfully. Email is not sent for
**FsrmReportType_ExportReport** report types. The reports are attached to the email
message. You can specify [Admin Email] to send notification to the administrator (if the
[IFsrmSetting::AdminEmail](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmsetting-get_adminemail) property is set). The
subject is "<ReportType>: <ReportName>". The body of the email message is empty.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)