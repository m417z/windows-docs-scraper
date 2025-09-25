# IFsrmClassificationManager::get_ClassificationLastReportPathWithoutExtension

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

The local directory path where the reports were stored the last time that classification
ran.

This property is read-only.

## Parameters

## Remarks

If the reports failed, this is the path where the reports would have been stored. The directory may contain
reports that completed successfully before the failure occurred. The value passed to
[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory),
if any, and the reporting context determine the path.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager.ClassificationReportEnabled](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationreportenabled)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)