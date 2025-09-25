# IFsrmClassificationManager::get_ClassificationLastError

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification) class.]

The error message from the last time that classification was run.

This property is read-only.

## Parameters

## Remarks

The property is set after classification is run either manually using
[IFsrmClassificationManager::RunClassification](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-runclassification)
or is scheduled using Task Scheduler.

## See also

[FsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmclassificationmanager)

[IFsrmClassificationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager)

[IFsrmClassificationManager.ClassificationRunningStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_classificationrunningstatus)

[IFsrmClassificationManager2](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nn-fsrmpipeline-ifsrmclassificationmanager2)

[MSFT_FSRMClassification](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmclassification)