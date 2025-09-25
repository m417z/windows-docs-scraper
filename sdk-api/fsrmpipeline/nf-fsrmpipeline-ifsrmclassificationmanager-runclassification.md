# IFsrmClassificationManager::RunClassification

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

Runs classification rules and generates the classification report.

## Parameters

### `context` [in]

Specifies the report subdirectory to which the classification report is written. For possible values, see
the [FsrmReportGenerationContext](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportgenerationcontext) enumeration.
To set the report directory, call the
[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory)
method.

### `reserved` [in]

Must be **NULL**.

## Return value

The method returns the following return values.

## Remarks

To run classification, there must be at least one property defined, at least one rule that references one of
the defined properties, and a registered classification module.

If you call this method and the classification is already queued or running, the method returns an error. To
determine whether classification is running, access the
[IFsrmClassificationManager.ClassificationRunningStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationrunningstatus)
property. To determine whether classification was successful, access the
[ClassificationLastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationlasterror)
property.

Classification generates the classification report only if reporting is enabled (see the
[IFsrmClassificationManager.ClassificationReportEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationreportenabled)
property).

To run classification on a schedule, use the Task Scheduler. Create a version 1.0 task. The command to run is
C:\Windows\System32\StorRept.exe. Specify "classification run" as the arguments to
StorRept.exe. StorRept.exe uses the
**FsrmReportGenerationContext_ScheduledReport** reporting context.

FSRM does not apply the classification rule if the rule, file, and cache are valid and have not changed.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)